#include "./header/SegmentApproximator.h"
#include "./header/Point3D.h"
#include "./header/Line3D.h"

CSegmentApproximator::CSegmentApproximator(void)
{
}

CSegmentApproximator::~CSegmentApproximator(void)
{
}

void CSegmentApproximator::approx(const vector<list<CInputPoint3D>>& segments)
{
	CInputPoint3D p;

	segmentsApprox = segments;

	for (size_t s = 0; s < segments.size(); s++)
	{
		douglasPeuckerRecursive(segmentsApprox[s], segmentsApprox[s].begin(), --(segmentsApprox[s].end()));
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

vector<list<CInputPoint3D>>& CSegmentApproximator::getSegmentsApproxVector()
{
	return segmentsApprox;
}

void CSegmentApproximator::douglasPeuckerRecursive(list<CInputPoint3D>& segment, std::list<CInputPoint3D>::iterator startItr, std::list<CInputPoint3D>::iterator endItr)
{
	if (segment.size() < 3) return;
	if (distance(startItr, endItr) == 2) return;
	CInputPoint3D pStart; CInputPoint3D pEnd;
	pStart.setX(startItr->getX()); pStart.setY(startItr->getY()); pStart.setZ(startItr->getZ());

	pEnd.setX(endItr->getX()); pEnd.setY(endItr->getY()); pEnd.setZ(endItr->getZ());

	double dist = 0.0, maxDist = 0.0;
	std::list<CInputPoint3D>::iterator maxItr, itr;

	for (itr = startItr; itr != endItr; itr++)
	{
		CLine3D line = CLine3D(pStart, pEnd);
		// calc distance
		dist = itr->distanceTo(line);
		if (dist > maxDist) {
			maxDist = dist;
			maxItr = itr;
		}
	}

	if (maxDist <= maxDistance) {

		segment.erase((++startItr), endItr);
		return;
	}

	douglasPeuckerRecursive(segment, startItr, maxItr);
	douglasPeuckerRecursive(segment, maxItr, endItr);
}
