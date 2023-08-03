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

	void approx(const vector<list<CPoint3D>>& Segments);
	void setmaxDistance(double maxDistanceSource);
	double getmaxDistance();

	vector<list<CPoint3D>>& getSegmentsApproxVector();

private:
	vector<list<CPoint3D>> segmentsApprox;

	double maxDistance;
	void douglasPeuckerRecursive(list<CPoint3D>& segment, std::list<CPoint3D>::iterator startItr, std::list<CPoint3D>::iterator endItr, double maxDistance);
	double calcDist(int xS, int yS, int xE, int yE, int x, int y);

};