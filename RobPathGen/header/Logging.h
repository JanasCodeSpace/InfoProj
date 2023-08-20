/**
 * @file Logging.h
 *
 * @brief Logging der Daten
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
  * @brief Gleitender Mittelwertfilter
  */
class CLogging
{
public:
	/**
	* Initialisiert Logging Klasse
	* @brief Default Konstruktor
	* @see CMeanFilter(int Window);
	*/
	CLogging(void);
	/**
	* Initialisiert Logging Klasse
	* @brief Default Konstruktor
	* @see CMeanFilter(int Window);
	*/
	CLogging(string path, bool detailed);
	/**
	* @brief Dekonstruktor
	*/
	~CLogging(void);
	/**
	* @brief Setzt in welchem Schritt wir uns befinden
	* @param int Step
	*/
	void setStep(int Step);
	/**
	* @brief Gibt es ein detailliertes Logging
	* @return bool detailed
	*/
	bool getDetailed(void);
	/**
	* Loggingdaten werden weggespeichert
	* @brief Ruft calculateMean für die einzelnen Segmente auf
	* @param vector<list<CInputPoint3D>>& sourcePath
	*/
	void logData(vector<list<CInputPoint3D>>& sourcePath);
	/**
	* Loggingdaten werden weggespeichert
	* @brief Ruft calculateMean für die einzelnen Segmente auf
	* @param vector<CInputPoint3D>& sourcePath
	*/
	void logData(vector<CInputPoint3D>& sourcePath);
private:
	/**
	* In welchem Schritt sind wir gerade
	*/
	int step;
	/**
	* Speicherpfad
	*/
	string path;
	/**
	* Speicherpfad
	*/
	bool detailed;


};


