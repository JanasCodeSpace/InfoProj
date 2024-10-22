/**
 * @file RobCodeGenerator.h
 *
 * @brief Erstellung des Roboter Codes
 */
#pragma once

#include <vector>
#include <iostream>
#include "Point3D.h"
#include "Logging.h"
#include "InputParameter.h"
#include <tuple>

using namespace std;

#define MAX_SPEED 2.0

/**
 * In dieser Klasse wird die Nachbearbeitung der Daten mit den einstellbaren Daten durchgefuehrt.
 *
 * @brief Klasse zum erstellen des Roboter Codes
 */
class CRobCodeGenerator
{
public:
	/**
	* Initialisiert der Daten
	* @brief Default Konstruktor
	* @see CRobCodeGenerator(double speedIn, bool speedManualIn, bool orientationManualIn, tuple<double, double, double> angles)
	*/
	CRobCodeGenerator(void);
	/**
	* Initialisiert der Daten
	* @brief Konstruktor
	* @param initSpeed double
	* @param initSpeedManual bool
	* @param initOrientationManual bool
	* @param initA double
	* @param initB double
	* @param initC double
	* @see CRobCodeGenerator(void)
	*/
	CRobCodeGenerator(CInputParameter inputParam);
	/**
	* @brief Dekonstruktor
	*/
	~CRobCodeGenerator(void);

	/**
	* Ruft das Postprocessing auf und speichert die bearbeiteten Daten als .src File ab
	* @brief Erstellt Roboter Code File
	* @param vector<CInputPoint3D>& path
	* @param string filename
	*/
	void generateRobCode(vector<CInputPoint3D>& path, string filepath, string filename, CLogging log);
	/**
	* Integration der Manuellen Eingabedaten in die eingelesenen und bearbeiteten Daten
	* Hier werden calculateSpeed und calculateAngles aufgerufen.
	* @brief Nachbearbeitung der Daten
	* @param vector<CInputPoint3D>& path
	*/
	void postProcessing(vector<CInputPoint3D>& path);
	/**
	* @brief Berechnet die Geschwindigkeit zwischen zwei Punkten
	* @param CInputPoint3D& p aktueller Punkt
	* @param size_t i Position im processedPath
	* @param double timePrev Zeitstempel des vorherigen Punkts
	* @return double
	*/
	double calculateSpeed(CInputPoint3D& p, size_t i, double timePrev);
	/**
	* @brief Berechnet die Geschwindigkeit zwischen zwei Punkten
	* @param COutputPoint3D& p
	* @param CInputPoint3D& pIn
	*/
	void calculateAngles(COutputPoint3D& p, CInputPoint3D& pIn);

private:
	/**
	* Fertig bearbeiteter Pfad
	*/
	vector<COutputPoint3D> processedPath;
	/**
	* User eingegebene Geschwindigkeit
	*/
	CInputParameter input;

};

