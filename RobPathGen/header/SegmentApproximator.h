/**
 * @file SegmentApproximator.h
 *
 * @brief Berechnung des Douglas Peuker Algorithmusses
 */

#include <vector>
#include <list>
#include <iostream>
#include <math.h>
#include "Point3D.h"
#include "Logging.h"

using namespace std;

#pragma once

/**
 * In dieser Klasse wird der Pfad mit hilfe des Douglas-Peuker Algorithmusses ausgeduennt
 * @brief Ausduennen des Pfades
 */
class CSegmentApproximator
{
public:
	/**
	* Initialisiert die Klasse
	* @brief Default Konstruktor
	*/
	CSegmentApproximator(void);
	/**
	* @brief Dekonstruktor
	*/
	~CSegmentApproximator(void);

	/**
	* Iteriert durch die Listen im Vektor und ruft die Douglas-Peuker-Funktion auf
	* @brief Ruft die Douglas-Peuker Funktion auf
	* @param Segments const vector<list<CInputPoint3D>>&
	* @param CLogging log fuer das Logging
	*/
	void approx(const vector<list<CInputPoint3D>>& Segments, CLogging log);
	/**
	* @brief Setzt die maximale Abweichung
	* @param maxDistanceSource double
	*/
	void setmaxDistance(double maxDistanceSource);
	/**
	* @brief Gibt die maximale Abweichung zurueck
	* @return maxDistanceSource double
	*/
	double getmaxDistance();

	/**
	* @brief Gibt den bereinigten Pfad zurueck
	* @return vector<list<CInputPoint3D>>&
	*/
	vector<list<CInputPoint3D>>& getSegmentsApproxVector();

private:
	/**
	* Bereinigten Pfad
	*/
	vector<list<CInputPoint3D>> segmentsApprox;
	/**
	* Einstellbare Distanz fuer den Douglas-Peuker-Algorithmus
	*/
	double maxDistance;

	/**
	* Rekursive Funktion die durch das Segment geht und Punkte aus dem Pfad loescht wenn
	* ihr Abstand zu gross wird.
	* @brief Rekursive Douglas Peuker Funktion
	* @param list<CInputPoint3D>& segment
	* @param std::list<CInputPoint3D>::iterator startIt
	* @param std::list<CInputPoint3D>::iterator endItr
	*/
	void douglasPeuckerRecursive(list<CInputPoint3D>& segment, std::list<CInputPoint3D>::iterator startItr, std::list<CInputPoint3D>::iterator endItr);
};