/**
 * @file: SegmentApproximator.h
 *
 * @brief: Berechnung des Douglas Peuker Algorithmusses
 */

#include <vector>
#include <list>
#include <iostream>
#include <math.h>
#include "Point3D.h"

using namespace std;

#pragma once

/**
 * In dieser Klasse wird der Pfad mit hilfe des Douglas-Peuker Algorithmusses ausgedünnt
 * @brief: Ausdünnen des Pfades
 */
class CSegmentApproximator
{
public:
	/**
	* Initialisiert die Input Daten mit Null
	* @brief: Default Konstruktor
	* @see: CInputParameter(double initSpeed, bool initSeepManual, bool initOrientationManual, double initA, double initB, double initC)
	*/
	CSegmentApproximator(void);
	/**
	* @brief: Dekonstruktor
	*/
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