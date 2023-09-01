/**
 * @file MeanFilter.h
 *
 * @brief Berechnung des gleitenden Mittelwertfilters
 */
#pragma once

#include <vector>
#include <list>
#include <string>
#include "Point3D.h"
#include "Logging.h"

using namespace std;

/**
 * In dieser Klasse werden die eingelesenen Daten mit einem gleitenden Mittelwertfilter mit einstellbarem Fenster geglaettet.
 * @brief Gleitender Mittelwertfilter
 */
class CMeanFilter
{
public:
	/**
	* Initialisiert des Fensters mit 3 als default Wert
	* @brief Default Konstruktor
	* @see CMeanFilter(int Window);
	*/
	CMeanFilter();
	/**
	* Initialisiert die Input Daten mit Null
	* @brief Konstruktor
	* @param int Window Konstruktor der Klasse mit Fenster
	* @seeCMeanFilter();
	*/
	CMeanFilter(int Window);
	/**
	* @brief Dekonstruktor
	*/
	~CMeanFilter();

	/**
	* @brief Setzt das Fenster
	* @param Window int
	*/
	void setWindowSize(int Window);

	/**
	* @brief Gibt das gesetzte Fenster zurueck
	* @return: Window int
	*/
	int getWindowSize();
	/**
	* @brief Gibt den geglaetteten Pfad zurueck
	* @return: vector<list<CInputPoint3D>>
	*/
	vector<list<CInputPoint3D>>& getPath();

	/**
	* Hier wird der Mittelwert der einzelnen Segmente berechnet
	* @brief Berechnet gleitenden Mittelwert
	* @param list<CInputPoint3D>& segment bekommt einzelne Segmente
	* @return: list<CInputPoint3D> gibt gelaettete Segmente zurueck
	*/
	list<CInputPoint3D> calculateMean(list<CInputPoint3D>& segment);
	/**
	* Hier wird durch die Segmente interiert und fuer jedes die calculate Mean Funktion aufgerufen.
	* Anschliessend werden sie in meanPath abgespeichert.
	* @brief Ruft calculateMean fuer die einzelnen Segmente auf
	* @param list<CInputPoint3D>& segment bekommt einzelne Segmente
	* @param CLogging log fuer das Logging
	*/
	void mean(vector<list<CInputPoint3D>>& sourcePath, CLogging log);

private:
	/**
	* Groesse des Fensters des gleitenden Mittelwerts
	*/
	int windowSize;
	/**
	* Hier werden die geglaetteten Daten gespeichert
	*/
	vector<list<CInputPoint3D>> meanPath;
};

