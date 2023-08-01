#include "MeanFilter.h"
#include <math.h>

CMeanFilter::CMeanFilter()
{
	setWindowSize(0);
	setLenth(0);
}

CMeanFilter::CMeanFilter(int Window, long lenth)
{
	setWindowSize(Window);
	setLenth(lenth);
}

CMeanFilter::~CMeanFilter()
{
}

void CMeanFilter::setWindowSize(int Window)
{
	windowSize = Window;
}

void CMeanFilter::setLenth(long lenth)
{
	lengthArray = lenth;
}

int CMeanFilter::getWindowSize()
{
	return windowSize;
}

long CMeanFilter::getlenth()
{
	return lengthArray;
}

void CMeanFilter::mean(double* target)
{
	double* buffer = new double[windowSize];		// Speicher für bufferarray reservieren

	int i = 0;
	int m = 0;

	for( ; i < windowSize / 2; i++)		// erste Hälfte des Arrays für das berechnen des ersten Wertes belegen
	{
		buffer = target + i;
		buffer++;
	}

	while (i != lengthArray)
	{
		


	}




	delete[] buffer;
}
