/**
 * @file: RobPathEditor.c
 *
 * @brief: Hier wird die main Funktion aufgerufen
 */

 /** \mainpage My Personal Index Page
  *
  * \section intro_sec Introduction
  *
  * This is the introduction.
  *
  * \section install_sec Installation
  *
  * \subsection step1 Step 1: Opening the box
  *
  * etc...
  */

#include "./header/SegmentApproximator.h"
#include "./header/PathBuilder.h"
#include "./header/RobCodeGenerator.h"
#include "./header/InputParameter.h"
#include "./header/MeanFilter.h"
#include "./header/Logging.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	clock_t start;
	start = clock();

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
		codeGenerator.generateRobCode(pathBuilder.getPath(), "output/robCode.src");
	
		float elapsed = (float)(clock() - start) / CLOCKS_PER_SEC;
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}

	system("pause");

   return 0;
}