#include "../header/GUI.h"

#include "../header/SegmentApproximator.h"
#include "../header/PathBuilder.h"
#include "../header/RobCodeGenerator.h"
#include "../header/InputParameter.h"
#include "../header/MeanFilter.h"
#include "../header/Logging.h"

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.startCalculation, &QPushButton::clicked, this, &GUI::calculate);
	connect(ui.pathInput, &QLabel::setText, this, &GUI::setInputPath)
}

GUI::~GUI()
{}

void GUI::calculate()
{
	try
	{
		//logging Initialisieren
		string loggingPath = "output";
		CLogging logging(loggingPath);

		//read Data

		CInputParameter inputParameter;
		string path = "input/path_01.csv";
		inputParameter.openFile(path);

		//moving Average

		CMeanFilter meanFilter;
		meanFilter.setWindowSize(3);
		meanFilter.mean(inputParameter.getPath(), logging);

		// Douglas-Peuker Algorithm

		CSegmentApproximator segmentApproximator;
		segmentApproximator.setmaxDistance(0.5);
		segmentApproximator.approx(meanFilter.getPath(), logging);

		// Puts the Segments together to one path

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentApproximator.getSegmentsApproxVector(), logging);

		// Calculates Speed, Angle and generates the Output Data

		CRobCodeGenerator codeGenerator(inputParameter.getSpeed(), inputParameter.getSpeedManual(),
			inputParameter.getOrientationManual(), inputParameter.getAngles());
		codeGenerator.generateRobCode(pathBuilder.getPath(), loggingPath, "robCode.src");
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}
}