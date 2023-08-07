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

vector<list<CPoint3D>>& CMeanFilter::getPath()
{
	return meanPath;
}

void CMeanFilter::mean(vector<list<CPoint3D>>& sourcePath)
{
	list<CPoint3D> dummyList;
	for (size_t s = 0; s < sourcePath.size(); s++)
	{
		dummyList = calculateMean(sourcePath[s]);
		meanPath.push_back(dummyList);
	}
}

list<CPoint3D> CMeanFilter::calculateMean(list<CPoint3D>& segment)
{
	double sumX = 0, sumY = 0, sumZ = 0;		// oder long??
	double div = 0;
	int m = 0;
	int OffsetPos = 0;
	int OffsetNeg = 0;

	CPoint3D p;

	int inputSize = segment.size();

	list<CPoint3D>::iterator it = segment.begin();
	list<CPoint3D> newSegment;

	for (size_t i = 0; i < inputSize; ++i)
	{
		sumX = 0, sumY = 0, sumZ = 0;
		div = 0;
		p.setTime(it->getTime());
		p.setEulerMatrix(it->getEulerMatrix());
		for (size_t j = i; j <= i + windowSize; ++j)
		{

			sumX += it->getX();
			sumY += it->getY();
			sumZ += it->getZ();
			div++;
			it++;
		}

		p.set(sumX / div, sumY / div, sumZ / div);
		it++;
		newSegment.push_back(p);

		return newSegment;
	}

}