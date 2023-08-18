/**
 * @file SegmentApproximator.cpp
 *
 * @brief Source File Douglas-Peuker
 */

#include "./header/SegmentApproximator.h"
#include "./header/Point3D.h"
#include "./header/Line3D.h"

CSegmentApproximator::CSegmentApproximator(void)
{
}

CSegmentApproximator::~CSegmentApproximator(void)
{
}

void CSegmentApproximator::approx(const vector<list<CInputPoint3D>>& segments, CLogging log)
{
	CInputPoint3D p;

	segmentsApprox = segments;

	/* Douglas Peucker f�r Segmente aufrufen*/
	for (size_t s = 0; s < segments.size(); s++)
	{
		douglasPeuckerRecursive(segmentsApprox[s], segmentsApprox[s].begin(), --(segmentsApprox[s].end()));
	}

	/*  Logging der Daten*/
	log.setStep(3);
	log.logData(segmentsApprox);
}

void CSegmentApproximator::setmaxDistance(double maxDistanceSource)
{
	maxDistance = maxDistanceSource;		// setze maxDistance
}

double CSegmentApproximator::getmaxDistance()
{
	return maxDistance;		// Rueckgabe von maxDistance
}

vector<list<CInputPoint3D>>& CSegmentApproximator::getSegmentsApproxVector()
{
	return segmentsApprox;		// Rueckgabe der Segmente
}

//TODO: Kommentar
void CSegmentApproximator::douglasPeuckerRecursive(list<CInputPoint3D>& segment, std::list<CInputPoint3D>::iterator startItr, std::list<CInputPoint3D>::iterator endItr)
{
	if (segment.size() < 3) return;  // min Gr��e pro Seg 3
	if (distance(startItr, endItr) == 2) return;		// Zeigerabstand == 2
	CInputPoint3D pStart; CInputPoint3D pEnd;		// Variablen deklarieren


	/* Startpunkt setzen */
	pStart.setX(startItr->getX()); pStart.setY(startItr->getY()); pStart.setZ(startItr->getZ());
	pStart.setTime(startItr->getTime());
	pStart.setEulerMatrix(startItr->getEulerMatrix());

	/* Endpunkt setzen */
	pEnd.setX(endItr->getX()); pEnd.setY(endItr->getY()); pEnd.setZ(endItr->getZ());
	pEnd.setTime(endItr->getTime());
	pEnd.setEulerMatrix(endItr->getEulerMatrix());

	double dist = 0.0, maxDist = 0.0;					// dist und maxDist initialisieren 
	std::list<CInputPoint3D>::iterator maxItr, itr;		// Zeiger bilden


	/* am weitesten Entfernten Punkt suchen */
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

		segment.erase((++startItr), endItr);		// Punkt l�schen
		return;
	}

	/*  Douglas Peucker erneut aufrufen */
	douglasPeuckerRecursive(segment, startItr, maxItr);
	douglasPeuckerRecursive(segment, maxItr, endItr);
}
