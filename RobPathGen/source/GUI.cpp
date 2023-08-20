#include "../header/GUI.h"

#include "../header/SegmentApproximator.h"
#include "../header/PathBuilder.h"
#include "../header/RobCodeGenerator.h"
#include "../header/MeanFilter.h"
#include "../header/Logging.h"

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	//Dateioperationen und Anzeige
	inputPathUI = "";
	ui.pathInput->setText(inputPathUI);
	outputPathUI = "";
	ui.pathOutput->setText(outputPathUI);

	connect(ui.pushOutput, &QPushButton::clicked, this, &GUI::setOutputPath);
	connect(ui.pushInput, &QPushButton::clicked, this, &GUI::setInputPath);

	//Zwingende Einstellwerte
	//Douglas-Peuker-Toleranz
	ui.dpToleranz->setRange(1, 100);
	ui.dpToleranz->setSingleStep(1);
	ui.dpToleranz->setValue(40);
	connect(ui.dpToleranz, &QSpinBox::valueChanged, this, &GUI::setDP);

	//Fenster für gleitenden Mittelwert
	ui.meanLength->setRange(3, 500);
	ui.meanLength->setSingleStep(1);
	ui.meanLength->setValue(50);
	connect(ui.meanLength, &QSpinBox::valueChanged, this, &GUI::setMean);

	//Geschwindigkeit
	connect(ui.bSpeed, &QCheckBox::clicked, this, &GUI::activateSpeed);
	ui.speed->setRange(0.01, 2);
	ui.speed->setSingleStep(0.01);
	ui.speed->setValue(1);
	connect(ui.speed, &QDoubleSpinBox::valueChanged, this, &GUI::setSpeed);

	//Ausrichtung
	connect(ui.bManOrientation, &QCheckBox::clicked, this, &GUI::activateOrientation);
	ui.AValue->setRange(-180, 180);
	ui.AValue->setSingleStep(5);
	ui.AValue->setValue(0);
	connect(ui.AValue, &QDoubleSpinBox::valueChanged, this, &GUI::setOrientation);

	ui.BValue->setRange(-180, 180);
	ui.BValue->setSingleStep(5);
	ui.BValue->setValue(90);
	connect(ui.BValue, &QDoubleSpinBox::valueChanged, this, &GUI::setOrientation);

	ui.CValue->setRange(-180, 180);
	ui.CValue->setSingleStep(5);
	ui.CValue->setValue(0);
	connect(ui.CValue, &QDoubleSpinBox::valueChanged, this, &GUI::setOrientation);

	connect(ui.startCalculation, &QPushButton::clicked, this, &GUI::calculate);
	//ui.progressBar->reset();
}

GUI::~GUI()
{}

void GUI::setOrientation(void)
{
	inputParameter.setOrientation(ui.AValue->value(), ui.BValue->value(), ui.CValue->value(),
		ui.bManOrientation->isChecked());
}

void GUI::activateOrientation(void)
{
	if (ui.bManOrientation->isChecked())
	{
		ui.orientation->setEnabled(true);
		ui.orientation->setStyleSheet("background-color:  rgb(67, 72, 91); color: rgb(3, 8, 14); border: 1px solid black;");
	}
	else
	{
		ui.orientation->setEnabled(false);
		ui.orientation->setStyleSheet("background-color: rgb(210,211,218); color: rgb(117,125,149)");
	}
}

void GUI::setSpeed(void)
{
	inputParameter.setSpeed(ui.speed->value(), ui.bSpeed->isChecked());
}

void GUI::activateSpeed(void)
{
	if (ui.bSpeed->isChecked())
	{
		ui.speed_2->setEnabled(true);
		ui.speed_2->setStyleSheet("background-color:  rgb(67, 72, 91); color: rgb(3, 8, 14); border: 1px solid black; ");
	}
	else
	{
		ui.speed_2->setEnabled(false);
		ui.speed_2->setStyleSheet("background-color: rgb(210,211,218); color: rgb(117,125,149)");
	}
}

void GUI::setMean(void)
{
	meanLength = ui.meanLength->value();
}


void GUI::setDP(void)
{
	dpTolerance = ui.dpToleranz->value();
}

void GUI::setInputPath(void)
{
	inputPathUI = QFileDialog::getOpenFileName(this);
	ui.pathInput->setText(inputPathUI);
}

void GUI::setOutputPath(void)
{
	outputPathUI = QFileDialog::getExistingDirectory(this);
	ui.pathOutput->setText(outputPathUI);
}

void GUI::calculate()
{

	if (inputPathUI.isEmpty() || outputPathUI.isEmpty())
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Keine Datei ausgewählt!");
		messageBox.setFixedSize(500, 200);
		return;
	}

	try
	{
		string outputPath = outputPathUI.toUtf8().constData();
		string inputPath = inputPathUI.toUtf8().constData();
		//ui.progressBar->setMaximum(5);
		//ui.progressBar->reset();
		ui.textBrowser->clear();

		//logging Initialisieren
		CLogging logging(outputPath);

		//read Data
		inputParameter.openFile(inputPath);

		ui.textBrowser->insertPlainText("Datei eingelesen\n");
		//ui.progressBar->setValue(1);
		//moving Average

		CMeanFilter meanFilter;
		meanFilter.setWindowSize(meanLength);
		meanFilter.mean(inputParameter.getPath(), logging);

		ui.textBrowser->insertPlainText("Gleitender Mittelwert berechnet\n");
		//ui.progressBar->setValue(2);
		// Douglas-Peuker Algorithm

		CSegmentApproximator segmentApproximator;
		segmentApproximator.setmaxDistance(dpTolerance);
		segmentApproximator.approx(meanFilter.getPath(), logging);

		ui.textBrowser->insertPlainText("Douglas-Peuker-Algorithmus berechnet\n");
		//ui.progressBar->setValue(3);

		// Puts the Segments together to one path

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentApproximator.getSegmentsApproxVector(), logging);

		ui.textBrowser->insertPlainText("Pfad zusammengesetzt\n");
		//ui.progressBar->setValue(4);
		// Calculates Speed, Angle and generates the Output Data

		CRobCodeGenerator codeGenerator(inputParameter.getSpeed(), inputParameter.getSpeedManual(),
			inputParameter.getOrientationManual(), inputParameter.getAngles());
		codeGenerator.generateRobCode(pathBuilder.getPath(), outputPath, "robCode.src");
		ui.textBrowser->insertPlainText("Datei erstellt\n");
		//ui.progressBar->setValue(5);
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}
}