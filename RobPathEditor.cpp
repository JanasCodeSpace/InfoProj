#include "SegmentApproximator.h"
#include "PathBuilder.h"
#include "RobCodeGenerator.h"
#include "InputParameter.h"
#include "MeanFilter.h"
#include "GUI.h"
#include <iostream>
#include <valarray>
#include <ctime>

using namespace std;

enum RobCodeLang {KUKA};

int main()
{
	clock_t start;
	start = clock();

	try
	{
		//read Data

		CInputParameter inputParameter;
		string path = "path_01.csv";
		inputParameter.openFile(path);

		//moving Average

		CMeanFilter meanFilter;
		meanFilter.setWindowSize(3);
		meanFilter.mean(inputParameter.getPath());

		CSegmentApproximator segmentApproximator;
		segmentApproximator.setmaxDistance(0.5);
		segmentApproximator.approx(meanFilter.getPath());

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentApproximator.getSegmentsApproxVector(), "08_path.csv");

		CRobCodeGenerator codeGenerator;
		codeGenerator.scaleX = 1.0;
		codeGenerator.scaleY = 1.0;
		codeGenerator.scaleZ = 1.0;
		codeGenerator.offsetX = 0.0; // 1m in front of robot
		codeGenerator.offsetY = 0.0;	
		codeGenerator.offsetZ = 0.0; // on top of a table with 0.75m height
		codeGenerator.generateRobCode(pathBuilder.getPath(), "09_robCode.src");
	
		float elapsed = (float)(clock() - start) / CLOCKS_PER_SEC;
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}

	system("pause");

   return 0;
}