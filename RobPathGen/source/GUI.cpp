/**
 * @file GUI.cpp
 *
 * @brief Source File User Interface
 */

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
	ui.dpToleranz->setValue(10);
	connect(ui.dpToleranz, &QSpinBox::valueChanged, this, &GUI::setDP);
	dpTolerance = ui.dpToleranz->value();

	//Fenster fuer gleitenden Mittelwert
	ui.meanLength->setRange(3, 500);
	ui.meanLength->setSingleStep(1);
	ui.meanLength->setValue(50);
	connect(ui.meanLength, &QSpinBox::valueChanged, this, &GUI::setMean);
	meanLength = ui.meanLength->value();

	//Geschwindigkeit
	connect(ui.bSpeed, &QCheckBox::clicked, this, &GUI::activateSpeed);
	inputParameter.setSpeed(0, false);
	ui.speed->setRange(0.01, 2);
	ui.speed->setSingleStep(0.01);
	ui.speed->setValue(1);
	connect(ui.speed, &QDoubleSpinBox::valueChanged, this, &GUI::setSpeed);

	//Ausrichtung
	connect(ui.bManOrientation, &QCheckBox::clicked, this, &GUI::activateOrientation);


	inputParameter.setOrientation(false, 0, 0, 0);
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

	//Offset
	connect(ui.bOffset, &QCheckBox::clicked, this, &GUI::activateOffset);
	inputParameter.setOffset(0, 0, 0, false);


	ui.offsetX->setRange(-400, 400);
	ui.offsetX->setSingleStep(10);
	ui.offsetX->setValue(0);
	connect(ui.offsetX, &QDoubleSpinBox::valueChanged, this, &GUI::setOffset);

	ui.offsetY->setRange(-400, 400);
	ui.offsetY->setSingleStep(10);
	ui.offsetY->setValue(0);
	connect(ui.offsetY, &QDoubleSpinBox::valueChanged, this, &GUI::setOffset);

	ui.offsetZ->setRange(-400, 400);
	ui.offsetZ->setSingleStep(10);
	ui.offsetZ->setValue(0);
	connect(ui.offsetZ, &QDoubleSpinBox::valueChanged, this, &GUI::setOffset);

	//Logging
	ui.bLogging->setChecked(true);
	inputParameter.setOffset(0, 0, 0, false);
	connect(ui.bLogging, &QCheckBox::clicked, this, &GUI::activateLogging);

	connect(ui.startCalculation, &QPushButton::clicked, this, &GUI::calculate);
}

GUI::~GUI()
{}

void GUI::activateLogging(void)
{
	inputParameter.setLogging(ui.bLogging->isChecked());
}

void GUI::setOffset(void)
{
	inputParameter.setOffset(ui.offsetX->value(), ui.offsetY->value(), ui.offsetZ->value(),
		ui.bOffset->isChecked());
}

void GUI::activateOffset(void)
{
	if (ui.bOffset->isChecked())
	{
		ui.offset->setEnabled(true);
		ui.offset->setStyleSheet("background-color:  rgb(67, 72, 91); color: rgb(3, 8, 14); border: 1px solid black;");
	}
	else
	{
		ui.offset->setEnabled(false);
		ui.offset->setStyleSheet("background-color: rgb(210,211,218); color: rgb(117,125,149)");
		ui.offsetX->setValue(0);
		ui.offsetY->setValue(0);
		ui.offsetZ->setValue(0);
		inputParameter.setOffset(0, 0, 0, false);
	}
	inputParameter.setOffset(ui.offsetX->value(), ui.offsetY->value(), ui.offsetZ->value(),
			ui.bOffset->isChecked());
}

void GUI::setOrientation(void)
{
	inputParameter.setOrientation(ui.bManOrientation->isChecked(), ui.AValue->value(), ui.BValue->value(), ui.CValue->value());
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
	inputParameter.setOrientation(ui.bManOrientation->isChecked(), ui.AValue->value(), ui.BValue->value(), ui.CValue->value());
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
	inputParameter.setSpeed(ui.speed->value(), ui.bSpeed->isChecked());
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
	QMessageBox messageBox;

	if (inputPathUI.isEmpty())
	{
		messageBox.critical(0, "Error", "Keine Datei ausgewaehlt!");
		messageBox.setFixedSize(500, 200);
		return;
	}
	if (outputPathUI.isEmpty())
	{
		messageBox.critical(0, "Error", "Kein Pfad ausgewaehlt!");
		messageBox.setFixedSize(500, 200);
		return;
	}

	try
	{
		string outputPath = outputPathUI.toUtf8().constData();
		string inputPath = inputPathUI.toUtf8().constData();
		ui.textBrowser->clear();

		//read Data
		CInputParameter input;
		input = inputParameter;
		input.openFile(inputPath);
		ui.textBrowser->insertPlainText("Datei eingelesen\n");

		//logging Initialisieren
		CLogging logging(outputPath, input.getLoggingManual());

		//moving Average

		CMeanFilter meanFilter;
		meanFilter.setWindowSize(meanLength);
		meanFilter.mean(input.getPath(), logging);
		ui.textBrowser->insertPlainText("Gleitender Mittelwert berechnet\n");

		// Douglas-Peuker Algorithm

		CSegmentApproximator segmentApproximator;
		segmentApproximator.setmaxDistance(dpTolerance);
		segmentApproximator.approx(meanFilter.getPath(), logging);
		ui.textBrowser->insertPlainText("Douglas-Peuker-Algorithmus berechnet\n");

		// Puts the Segments together to one path

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentApproximator.getSegmentsApproxVector(), logging);
		ui.textBrowser->insertPlainText("Pfad zusammengesetzt\n");

		// Calculates Speed, Angle and generates the Output Data

		CRobCodeGenerator codeGenerator(input);
		codeGenerator.generateRobCode(pathBuilder.getPath(), outputPath, inputPath, logging);
		ui.textBrowser->insertPlainText("Datei erstellt\n");
	}

	catch (exception& e)
	{
		messageBox.critical(0, "Error", e.what());
		messageBox.setFixedSize(500, 200);
		return;
	}

}
