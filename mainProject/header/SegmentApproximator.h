#include <valarray>
#include <vector>
#include <list>
#include <iostream>
#include <math.h>
#include "Point3D.h"

using namespace std;

#pragma once
class CSegmentApproximator
{
public:
	CSegmentApproximator(void);
	~CSegmentApproximator(void);

	void approx(const vector<list<CInputPoint3D>>& Segments);
	void setmaxDistance(double maxDistanceSource);
	double getmaxDistance();

	vector<list<CInputPoint3D>>& getSegmentsApproxVector();

private:
	vector<list<CInputPoint3D>> segmentsApprox;

	double maxDistance;
	void douglasPeuckerRecursive(list<CInputPoint3D>& segment, std::list<CInputPoint3D>::iterator startItr, std::list<CInputPoint3D>::iterator endItr, double maxDistance);
	double calcDist(int xS, int yS, int zS, int xE, int yE, int zE, int x, int y, int z);

};