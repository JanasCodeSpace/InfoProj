/**
 * @file: MeanFilter.h
 *
 * @brief: Berechnung des gleitenden Mittelwertfilters
 */

#include <vector>
#include <list>
#include "Point3D.h"

#pragma once

using namespace std;

/**
 * In dieser Klasse werden die eingelesenen Daten mit einem gleitenden Mittelwertfilter mit einstellbarem Fenster gegl�ttet.
 * @brief: Gleitender Mittelwertfilter
 */
class CMeanFilter
{
public:
	/**
	* Initialisiert des Fensters mit 3 als default Wert
	* @brief: Default Konstruktor
	* @see: CMeanFilter(int Window);
	*/
	CMeanFilter();
	/**
	* Initialisiert die Input Daten mit Null
	* @brief: Konstruktor
	* @param: int Window Konstruktor der Klasse mit Fenster
	* @see:CMeanFilter();
	*/
	CMeanFilter(int Window);
	/**
	* @brief: Dekonstruktor
	*/
	~CMeanFilter();

	/**
	* @brief: Setzt das Fenster
	* @param: Window int
	*/
	void setWindowSize(int Window);

	/**
	* @brief: Gibt das gesetzte Fenster zur�ck
	* @return: Window int
	*/
	int getWindowSize();
	/**
	* @brief: Gibt den gegl�tteten Pfad zur�ck
	* @return: vector<list<CInputPoint3D>>
	*/
	vector<list<CInputPoint3D>>& getPath();

	/**
	* Hier wird der Mittelwert der einzelnen Segmente berechnet
	* @brief: Berechnet gleitenden Mittelwert
	* @param: list<CInputPoint3D>& segment bekommt einzelne Segmente
	* @return: list<CInputPoint3D> gibt gel�ttete Segmente zur�ck
	*/
	list<CInputPoint3D> calculateMean(list<CInputPoint3D>& segment);
	/**
	* Hier wird durch die Segmente interiert und f�r jedes die calculate Mean Funktion aufgerufen.
	* Anschliessend werden sie in meanPath abgespeichert.
	* @brief: Ruft calculateMean f�r die einzelnen Segmente auf
	* @param: list<CInputPoint3D>& segment bekommt einzelne Segmente
	*/
	void mean(vector<list<CInputPoint3D>>& sourcePath);

private:
	/**
	* Gr�sse des Fensters des gleitenden Mittelwerts
	*/
	int windowSize;
	/**
	* Hier werden die gegl�tteten Daten gespeichert
	*/
	vector<list<CInputPoint3D>> meanPath;
};

