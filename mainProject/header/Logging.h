/**
 * @file: Logging.h
 *
 * @brief: Logging der Daten
 */

#include "EulerMatrix.h"
#include "Point3D.h"

#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <list>

#pragma once
 /**
  * In dieser Klasse werden die eingelesenen Daten mit einem gleitenden Mittelwertfilter mit einstellbarem Fenster geglättet.
  * @brief: Gleitender Mittelwertfilter
  */
class CLogging
{
public:
	/**
	* Initialisiert Logging Klasse
	* @brief: Default Konstruktor
	* @see: CMeanFilter(int Window);
	*/
	CLogging(void);
	/**
	* Initialisiert Logging Klasse
	* @brief: Default Konstruktor
	* @see: CMeanFilter(int Window);
	*/
	CLogging(int Step);
	/**
	* @brief: Dekonstruktor
	*/
	~CLogging(void);

	/**
	* Loggingdaten werden weggespeichert
	* @brief: Ruft calculateMean für die einzelnen Segmente auf
	* @param: string Name
	* @param: string Path
	* @param: vector<list<CInputPoint3D>>& sourcePath
	*/
	void logData(string Path, vector<list<CInputPoint3D>>& sourcePath);
	/**
	* Loggingdaten werden weggespeichert
	* @brief: Ruft calculateMean für die einzelnen Segmente auf
	* @param: string Name
	* @param: string Path
	* @param: vector<CInputPoint3D>& sourcePath
	*/
	void logData(string Path, vector<CInputPoint3D>& sourcePath);
private:
	/**
	* In welchem Schritt sind wir gerade
	*/
	int step;
};


