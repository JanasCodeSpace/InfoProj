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
	inputPathUI = "input/path_01.csv";
	ui.pathInput->setText(inputPathUI);
	outputPathUI = "output";
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
	ui.meanLength->setValue(40);
	connect(ui.meanLength, &QSpinBox::valueChanged, this, &GUI::setMean);

	//Geschwindigkeit
	connect(ui.bSpeed, &QCheckBox::clicked, this, &GUI::activateSpeed);
	ui.meanLength->setRange(0.01, 2);
	ui.meanLength->setSingleStep(0.01);
	ui.meanLength->setValue(1);
	connect(ui.speed, &QDoubleSpinBox::valueChanged, this, &GUI::setSpeed);

	//Ausrichtung

	connect(ui.startCalculation, &QPushButton::clicked, this, &GUI::calculate);
}

GUI::~GUI()
{}


void GUI::setSpeed(void)
{
	inputParameter.setSpeed(ui.speed->value(), ui.bSpeed->isChecked());
}

void GUI::activateSpeed(void)
{
	if(ui.bSpeed->isChecked())
		ui.speed_2->setEnabled(true);
	else
		ui.speed_2->setEnabled(false);
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
	outputPathUI = QFileDialog::getOpenFileName(this);
	ui.pathOutput->setText(outputPathUI);
}

void GUI::calculate()
{
	try
	{
		string outputPath = outputPathUI.toUtf8().constData();
		string inputPath = inputPathUI.toUtf8().constData();

		//logging Initialisieren
		CLogging logging(outputPath);

		//read Data
		inputParameter.openFile(inputPath);

		//moving Average

		CMeanFilter meanFilter;
		meanFilter.setWindowSize(meanLength);
		meanFilter.mean(inputParameter.getPath(), logging);

		// Douglas-Peuker Algorithm

		CSegmentApproximator segmentApproximator;
		segmentApproximator.setmaxDistance(dpTolerance);
		segmentApproximator.approx(meanFilter.getPath(), logging);

		// Puts the Segments together to one path

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentApproximator.getSegmentsApproxVector(), logging);

		// Calculates Speed, Angle and generates the Output Data

		CRobCodeGenerator codeGenerator(inputParameter.getSpeed(), inputParameter.getSpeedManual(),
			inputParameter.getOrientationManual(), inputParameter.getAngles());
		codeGenerator.generateRobCode(pathBuilder.getPath(), outputPath, "robCode.src");
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}
}