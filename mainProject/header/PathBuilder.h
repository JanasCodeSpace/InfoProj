/**
 * @file: PathBuilder.h
 *
 * @brief: Setzt die einzelnen Segmente zu einem Vector zusammen
 */

#include <vector>
#include <list>
#include <iostream>
#include "Point3D.h"

using namespace std;

#pragma once

/**
 * In dieser Klasse wird aus den Segmenten ein zusammenh�ngender Pfad erstellt
 * @brief: Zusammensetzten des Pfades
 */
class CPathBuilder
{
public:
	/**
	* Initialisiert der Klasse
	* @brief: Default Konstruktor
	*/
	CPathBuilder(void);
	/**
	* @brief: Dekonstruktor
	*/
	~CPathBuilder(void);

	/**
	* @brief: Gibt Pfad zur�ck
	* @return: vector<CInputPoint3D> zusammengesetzter Pfad
	*/
	vector<CInputPoint3D>& getPath();
	/**
	* @brief: Gibt Pfad zur�ck
	* @param: segments vector<list<CInputPoint3D>>& Pfad aus Segmenten
	* @param: filename string Pfad f�r Logging Datei
	*/
	void createPath(vector<list<CInputPoint3D>>& segments, string filename);

private:
	/**
	* Vector mit den zusammengesetzten Pfad Daten
	*/
	vector<CInputPoint3D> path;
};

