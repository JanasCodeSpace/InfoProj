#include "SegmentApproximator.h"
#include "Point3D.h"
#include "Line3D.h"

CSegmentApproximator::CSegmentApproximator(void)
{
}

CSegmentApproximator::~CSegmentApproximator(void)
{
}

void CSegmentApproximator::approx(const vector<list<CPoint3D>>& segments)
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

	double dist = 0.0, maxDist = 0.0;
	std::list<CPoint3D>::iterator maxItr, itr;

	for (itr = startItr; itr != endItr; itr++)
	{
		CLine3D line = CLine3D(pStart, pEnd);
		// calc distance
		dist = itr->distanceTo(line);
		//dist=calcDist(pStart.getX(), pStart.getY(), pEnd.getX(), pEnd.getY(), itr->getX(), itr->getY());
		if (dist > maxDist) {
			maxDist = dist;
			maxItr = itr;
		}
	}

	if (maxDist <= maxDistance) {

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

double CSegmentApproximator::calcDist(int xS, int yS, int zS, int xE, int yE, int zE, int x, int y, int z)
{
	/*
	xS, yS, zS		== Startpunkt
	xE, yE, zE		== Endpunkt
	x, y, z			== Vermessungspunkt
	*/

	//Crossproduct
	double bx, by, bz, rv_sq, dist, vp1, vp2, vp3;

	/*
	bx, by, bz		== Vektordifferenz
	rv_sq			== Betrag des Linienvektors
	dist			== Distanz von Punkt zu Linie
	vp1, vp2, vp3	== Vektorprodukte
	*/

	int rvx = xS - xE;		// Parameter X des Linienvektor berechnen
	int rvy = yS - yE;		// Parameter Y des Linienvektor berechnen
	int rvz = zS - zE;		// Parameter Z des Linienvektor berechnen

	rv_sq = sqrt((rvx * rvx) + (rvy * rvy) + (rvz * rvz));		// Betrag des Linienvektor berechnen

	bx = x - xS;			// X(Punkt) - X(Aufpunkt)
	by = y - yS;			// Y(Punkt) - Y(Aufpunkt)
	bz = z - zS;			// Z(Punkt) - Z(Aufpunkt)

	vp1 = by * rvz - bz * rvy; 		// Parameter X Vektorprodukt
	vp2 = bz * rvx - bx * rvz; 		// Parameter Y Vektorprodukt
	vp3 = bx * rvy - by * rvx; 		// Parameter Z Vektorprodukt

	dist = sqrt(vp1 * vp1 + vp2 * vp2 + vp3 * vp3) / rv_sq;	// Betrag des Vektors berechnen

	return dist;

}