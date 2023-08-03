#include "SegmentApproximator.h"
#include "Point3D.h"
#include "Line3D.h"

CSegmentApproximator::CSegmentApproximator(void)
{
}

CSegmentApproximator::~CSegmentApproximator(void)
{
}

void CSegmentApproximator::approx(const vector<list<CPoint3D>>& segments, double maxDistance)
{
	CPoint3D p;

	segmentsApprox = segments;
	
	for (size_t s = 0; s < segments.size(); s++)
	{
		douglasPeuckerRecursive(segmentsApprox[s], segmentsApprox[s].begin(), --(segmentsApprox[s].end()), maxDistance);
	}

}

void CSegmentApproximator::setmaxDistance(double maxDistanceSource)
{
	maxDistance = maxDistanceSource;
}

double CSegmentApproximator::getmaxDistance()
{
	return maxDistance;
}

vector<list<CPoint3D>>& CSegmentApproximator::getSegmentsApproxVector()
{
	return segmentsApprox;
}

void CSegmentApproximator::douglasPeuckerRecursive(list<CPoint3D>& segment, std::list<CPoint3D>::iterator startItr, std::list<CPoint3D>::iterator endItr, double maxDistance)
{
	if (segment.size() < 3) return;
	if (distance(startItr, endItr) == 2) return;
	CPoint3D pStart; CPoint3D pEnd;
	pStart.setX(startItr->getX()); pStart.setY(startItr->getY()); pStart.setZ(startItr->getZ());
	
	//pEnd.x=segment.back().x; pEnd.y = segment.back().y;
	pEnd.setX(endItr->getX()); pEnd.setY(endItr->getY()); pEnd.setZ(endItr->getZ());

	double dist=0.0, maxDist=0.0;
	std::list<CPoint3D>::iterator maxItr, itr;

	for(itr = startItr; itr != endItr; itr++)
	{
		CLine3D line = CLine3D(pStart, pEnd);
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