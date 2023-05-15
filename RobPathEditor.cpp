//#include "bitmap_image.h"
//#include "BmpHandler.h"
//#include "ImgProcessor.h"
//#include "PointSequencer.h"
#include "SegmentApproximator.h"
#include "SegmentSequencer.h"
#include "PathBuilder.h"
#include "RobCodeGenerator.h"
#include <iostream>
#include <valarray>
#include <ctime>

using namespace std;

enum RobCodeLang {KUKA};

int main()
{
	//TODO: alte Bilder L�schen!
	clock_t start;
	start = clock();

	try
	{
		CPointSequencer pointSequencer;
		pointSequencer.createSegments(imgProcessor.getBinaryArrayThinned(), bmpHandler.getWidth(), bmpHandler.getHeight());
		bmpHandler.drawOnBitmap(pointSequencer.getSegmentsVector(), binary, pixel);
		bmpHandler.saveWorkingImage("05_segmentsOnBinary.bmp");

		CSegmentApproximator segmentApproximator;
		segmentApproximator.approx(pointSequencer.getSegmentsVector(), 5.0);
		bmpHandler.drawOnBitmap(segmentApproximator.getSegmentsApproxVector(), working, lineConnect);
		bmpHandler.saveWorkingImage("06_segmentsApproxOnBinary.bmp");
	
		CSegmentSequencer segmentSequencer;
		segmentSequencer.sortSegments(segmentApproximator.getSegmentsApproxVector());
		bmpHandler.drawOnBitmap(segmentSequencer.getSegmentsSortedVector(), binary, lineConnect);
		bmpHandler.saveWorkingImage("07_segmentsSortedOnBinary.bmp");

		CPathBuilder pathBuilder;
		pathBuilder.createPath(segmentSequencer.getSegmentsSortedVector(), "08_path.csv");

		CRobCodeGenerator codeGenerator;
		codeGenerator.scaleX = 0.7;
		codeGenerator.scaleY = -0.7;
		codeGenerator.scaleZ = 50.0;
		codeGenerator.offsetX = 1000.0; // 1m in front of robot
		codeGenerator.offsetY = 0.0;	
		codeGenerator.offsetZ = 750.0; // on top of a table with 0.75m height
		codeGenerator.generateRobCode(pathBuilder.getPath(), "09_robCode.src");
	
	
		float elapsed = (float)(clock() - start) / CLOCKS_PER_SEC;
		printf("Elapsed time: %f\n", elapsed);
	}

	catch (exception& e)
	{
		cerr << e.what() << "\n";
	}

	system("pause");

   return 0;
}