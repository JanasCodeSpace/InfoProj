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

#include "SegmentApproximator.h"
#include "PathBuilder.h"
#include "RobCodeGenerator.h"
#include "InputParameter.h"
#include "MeanFilter.h"
#include "GUI.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	clock_t start;
	start = clock();

	try
	{
		//read Data

		CInputParameter inputParameter;
		string path = "input/path_01.csv";
		inputParameter.openFile(path);

		//moving Average

		CMeanFilter meanFilter;
		meanFilter.setWindowSize(3);
		meanFilter.mean(inputParameter.getPath());

		// Douglas-Peuker Algorithm

		CSegmentApproximator segmentApproximator;
		segmentApproximator.setmaxDistance(0.5);
		segmentApproximator.approx(meanFilter.getPath());

		// Puts the Segments together to one path

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentApproximator.getSegmentsApproxVector(), "output/08_path.csv");

		// Calculates Speed, Angle and generates the Output Data

		CRobCodeGenerator codeGenerator(inputParameter.getSpeed(), inputParameter.getSpeedManual(),
			inputParameter.getOrientationManual(), inputParameter.getAngles());
		codeGenerator.generateRobCode(pathBuilder.getPath(), "output/09_robCode.src");
	
		float elapsed = (float)(clock() - start) / CLOCKS_PER_SEC;
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}

	system("pause");

   return 0;
}