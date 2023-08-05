#include "MeanFilter.h"
#include <math.h>

CMeanFilter::CMeanFilter()
{
	setWindowSize(0);
}

CMeanFilter::CMeanFilter(int Window, long lenth)
{
	setWindowSize(Window);
}

CMeanFilter::~CMeanFilter()
{
}

void CMeanFilter::setWindowSize(int Window)
{
	windowSize = Window;
}

int CMeanFilter::getWindowSize()
{
	return windowSize;
}

vector<CPoint3D>& CMeanFilter::getPath()
{
	return path;
}

void CMeanFilter::calculateMean(vector<CPoint3D>& sourcePath)
{
	double sumX = 0, sumY = 0, sumZ = 0;		// oder long??
	double div = 0;

	int i = 0;
	int m = 0;
	int OffsetPos = 0;
	int OffsetNeg = 0;

	CPoint3D p;

	int inputSize = sourcePath.size();

	for (i = 0; i < inputSize; ++i)
	{
		sumX = 0, sumY = 0, sumZ = 0;
		div = 0;
		for (int j = i - windowSize + 1; j <= i; ++j)
		{
			sumX += sourcePath[j].getX();
			sumY += sourcePath[j].getY();
			sumZ += sourcePath[j].getZ();
			div++;
		}


		p.set(sumX / div, sumY / div, sumZ / div);
		p.setTime(sourcePath[i].getTime());
		p.setEulerMatrix(sourcePath[i].getEulerMatrix());

		path.push_back(p);
	}

}