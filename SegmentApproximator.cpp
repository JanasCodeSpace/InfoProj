#include "SegmentApproximator.h"

CSegmentApproximator::CSegmentApproximator(void)
{
}

CSegmentApproximator::~CSegmentApproximator(void)
{
}

void CSegmentApproximator::approx(const vector<list<CPoint2D>>& segments, double maxDistance)
{
	CPoint2D p;

	segmentsApprox = segments;
	
	for (size_t s = 0; s < segments.size(); s++)
	{
		douglasPeuckerRecursive(segmentsApprox[s], segmentsApprox[s].begin(), --(segmentsApprox[s].end()), maxDistance);
	}

}

vector<list<CPoint2D>>& CSegmentApproximator::getSegmentsApproxVector()
{
	return segmentsApprox;
}

void CSegmentApproximator::douglasPeuckerRecursive(list<CPoint2D>& segment, std::list<CPoint2D>::iterator startItr, std::list<CPoint2D>::iterator endItr, double maxDistance)
{
	if (segment.size() < 3) return;
	if (distance(startItr, endItr) == 2) return;
	CPoint2D pStart; CPoint2D pEnd;
	pStart.setX(startItr->getX()); pStart.setY(startItr->getY());
	
	//pEnd.x=segment.back().x; pEnd.y = segment.back().y;
	pEnd.setX(endItr->getX()); pEnd.setY(endItr->getY());

	double dist=0.0, maxDist=0.0;
	std::list<CPoint2D>::iterator maxItr, itr;

	for(itr = startItr; itr != endItr; itr++)
	{
		CLine2D line = CLine2D(pStart, pEnd);
		// calc distance
		dist = itr->distanceTo(line);
		//dist=calcDist(pStart.getX(), pStart.getY(), pEnd.getX(), pEnd.getY(), itr->getX(), itr->getY());
		if (dist>maxDist){
			maxDist=dist;
			maxItr=itr;
		}
	}
	
	if(maxDist<=maxDistance){

		segment.erase((++startItr), endItr);
		//for(itr = (++startItr); itr != --(endItr);)
		//{
		//	// erase elements:
		//	itr = segment.erase(itr);
		//}
		return;
	}

	douglasPeuckerRecursive(segment, startItr, maxItr, maxDistance);
	douglasPeuckerRecursive(segment, maxItr, endItr, maxDistance);
}

double CSegmentApproximator::calcDist(int xS, int yS, int xE, int yE, int x, int y)
{

	//Scalarproduct / intersection point
	/*double lambda, rv_sq, dist, cx, cy;

	int rvx=xS-xE;
	int rvy=yS-yE;
	
	rv_sq = (rvx*rvx) + (rvy*rvy);
	
	lambda = (((x-xS)*rvx) + ((y-yS)*rvy))/rv_sq;

	cx = x - (xS + lambda*rvx);
	cy = y - (yS + lambda*rvy);

	dist = sqrt(cx*cx + cy*cy);*/

	//Crossproduct
	double bx,by,rv_sq,dist;

	int rvx=xS-xE;
	int rvy=yS-yE;
	
	rv_sq = (rvx*rvx) + (rvy*rvy);

	bx = x - xS;
	by = y - yS;

	dist = abs((bx*rvy-by*rvx))/sqrt(rv_sq);

	return dist;

}