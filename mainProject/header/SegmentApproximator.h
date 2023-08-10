/**
 * @file: SegmentApproximator.h
 *
 * @brief: Berechnung des Douglas Peuker Algorithmusses
 */

//TODO: Kommentare

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
	* Initialisiert die KLasse
	* @brief: Default Konstruktor
	*/
	CSegmentApproximator(void);
	/**
	* @brief: Dekonstruktor
	*/
	~CSegmentApproximator(void);

	/**
	* 
	* @brief: 
	* @param: Segments const vector<list<CInputPoint3D>>&
	*/
	void approx(const vector<list<CInputPoint3D>>& Segments);
	/**
	*
	* @brief:
	* @param: maxDistanceSource double
	*/
	void setmaxDistance(double maxDistanceSource);
	/**
	*
	* @brief:
	* @param: maxDistanceSource double
	*/
	double getmaxDistance();

	/**
	* @brief: Gibt den bereinigten Pfad zurück
	* @return: vector<list<CInputPoint3D>>&
	*/
	vector<list<CInputPoint3D>>& getSegmentsApproxVector();

private:
	/**
	* Bereinigten Pfad
	*/
	vector<list<CInputPoint3D>> segmentsApprox;
	/**
	* Einstellbare Distanz für den Douglas-Peuker-Algorithmus
	*/
	double maxDistance;

	/**
	* 
	* @brief: 
	* @param: list<CInputPoint3D>& segment
	* @param: std::list<CInputPoint3D>::iterator startIt
	* @param: std::list<CInputPoint3D>::iterator endItr
	*/
	void douglasPeuckerRecursive(list<CInputPoint3D>& segment, std::list<CInputPoint3D>::iterator startItr, std::list<CInputPoint3D>::iterator endItr);
	/**
	*
	* @brief:
	* @param: int xS
	* @param: int yS
	* @param: int zS
	* @param: int xE
	* @param: int yE
	* @param: int zE
	* @param: int x
	* @param: int y
	* @param: int z
	* @return: double
	*/
	double calcDist(int xS, int yS, int zS, int xE, int yE, int zE, int x, int y, int z);

};