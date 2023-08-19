/**
 * @file Line3D.h
 *
 * @brief Header File Daten Einlesen
 */

#include "Point3D.h"
#include <math.h>

using namespace std;

#pragma once

/**
 * In dieser Klasse werden alle Berechnungen die zwischen zwei Punken passieren gehandhabt.
 * @brief Berechnung Geraden
 */
class CLine3D
{
public:
	/**
	* Initialisiert die Klasse
	* @brief Default Konstruktor
	* @see CLine3D(CPoint3D P1, CPoint3D P2)
	*/
	CLine3D(void);
	/**
	* Initialisiert die Klasse
	* @brief Konstruktor mit zwei Punkten
	* @see CLine3D(void);
	*/
	CLine3D(CPoint3D P1, CPoint3D P2);
	/**
	* @brief Dekonstruktor
	*/
	~CLine3D(void);

	/**
	* Punkt 1
	*/
	CPoint3D p1;
	/**
	* Punkt 2
	*/
	CPoint3D p2;
};

