/**
 * @file MeanFilter.cpp
 *
 * @brief Source File gleitender Mittelwertfilter
 */

#include "../header/MeanFilter.h"
#include "../header/Logging.h"
#include <math.h>

CMeanFilter::CMeanFilter()
{
	windowSize = 3;
}

CMeanFilter::CMeanFilter(int Window)
{
	windowSize = Window;
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

vector<list<CInputPoint3D>>& CMeanFilter::getPath()
{
	return meanPath;
}

void CMeanFilter::mean(vector<list<CInputPoint3D>>& sourcePath, CLogging log)
{
	list<CInputPoint3D> dummyList;
	for (size_t s = 0; s < sourcePath.size(); s++)
	{
		dummyList = calculateMean(sourcePath[s]);
		meanPath.push_back(dummyList);
	}
	log.setStep(2);
	log.logData(meanPath);
}

list<CInputPoint3D> CMeanFilter::calculateMean(list<CInputPoint3D>& segment)
{
	double sumX = 0, sumY = 0, sumZ = 0;
	double div = 0;
	int m = 0;
	int OffsetPos = 0;
	int OffsetNeg = 0;

	CInputPoint3D p;

	size_t inputSize = segment.size();

	list<CInputPoint3D>::iterator it = segment.begin();
	list<CInputPoint3D> newSegment;

	for (size_t i = 0; i < inputSize - windowSize; ++i) //For each element in the Segment
	{
		sumX = 0, sumY = 0, sumZ = 0;
		div = 0;
		p.setTime(it->getTime());
		p.setEulerMatrix(it->getEulerMatrix());
		for (size_t j = i; j < i + windowSize; ++j) // Build the sums for the three points
		{
			sumX += it->getX();
			sumY += it->getY();
			sumZ += it->getZ();
			div++;
			it++;
		}
		for (size_t index = windowSize; index > 0; index--) // Pain, the iterator has to be set back
		{
			it--;
		}
		p.set(sumX / div, sumY / div, sumZ / div); // Calculate smoothed values
		if(it != segment.end())
			it++;
		newSegment.push_back(p);
	}
	return newSegment;
}