#include <valarray>
#include <vector>
#include <list>
#include <iostream>
#include <math.h>

#include "Point2D.h"
#include "Line2D.h"

using namespace std;

#pragma once
class CSegmentApproximator
{
public:
	CSegmentApproximator(void);
	~CSegmentApproximator(void);

	void approx(const vector<list<CPoint2D>>& Segments, double maxDistance);

	vector<list<CPoint2D>>& getSegmentsApproxVector();

private:
	vector<list<CPoint2D>> segmentsApprox;

	double maxDistance;
	void douglasPeuckerRecursive(list<CPoint2D>& segment, std::list<CPoint2D>::iterator startItr, std::list<CPoint2D>::iterator endItr, double maxDistance);
	double calcDist(int xS, int yS, int xE, int yE, int x, int y);

};