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
	windowsize = Window;
}

void CMeanFilter::setLenth(long lenth)
{
	lenthofarray = lenth;
}

int CMeanFilter::getWindowSize()
{
	return windowsize;
}

long CMeanFilter::getlenth()
{
	return lenthofarray;
}

void CMeanFilter::mean(double* target)
{
	double* buffer = new double[lenthofarray];		// Speicher f�r bufferarray reservieren

	int i = 0;
	int m = 0;

	for( ; i < windowsize / 2; i++)		// erste H�lfte des Arrays f�r das ererchnen des ersten Wertes belegen
	{
		buffer = target + i;
		buffer++;
	}

	while (i != lenthofarray)
	{
		


	}




	delete[] buffer;
}
