/**
 * @file InputParameter.h
 * 
 * @brief Header File Daten Einlesen
 */

#include "EulerMatrix.h"
#include "Point3D.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <tuple>

using namespace std;

#pragma once

/**
 * In dieser Klasse werden die eingelesenen einstellbaren Daten und das einlesen der Daten aus der Eingabedatei gehandelt.
 * @brief Handling Eingabedaten
 */
class CInputParameter
{
public:
	/**
	* Initialisiert die Input Daten mit Null
	* @brief Default Konstruktor
	* @see CInputParameter(double initSpeed, bool initSeepManual, bool initOrientationManual, double initA, double initB, double initC)
	*/
	CInputParameter(void);
	/**
	* Initialisiert die Input Daten
	* @brief Konstruktor mit Werten
	* @param double initSpeed
	* @param bool initSeepManual
	* @param bool initOrientationManual
	* @param double initA
	* @param double initB
	* @param double initC
	* @see CInputParameter()
	* @see ~CInputParameter()
	* @see CInputParameter(void);
	*/
	CInputParameter(double initSpeed, bool initSeepManual, bool initOrientationManual, double initA, double initB, double initC);
	/**
	* @brief Dekonstruktor
	*/
	~CInputParameter(void);

	/**
	* Setzt ob die Orientierung Händisch eingegeben werden soll und die drei Winkel
	* @brief Setzt Orientierungs Daten
	* @param bool initOrientationManual
	* @param double initA
	* @param double initB
	* @param double initC
	*/
	void setOrientation(bool initOrientationManual, double initA, double initB, double initC);
	/**
	* Setzt ob die Geschwindigkeit Händisch eingegeben werden soll und die Geschwindigkeit in m/s
	* @brief Setzt Geschwindigkeits Daten
	* @param double initSpeed
	* @param bool initSeepManual
	*/
	void setSpeed(double initSpeed, bool initSpeedManual);
	/**
	* Setzt den  gewünschten Offset
	* @brief Setzt den  gewünschten Offset
	* @param double X
	* @param double Y
	* @param double Z
	* @param bool offsetManual
	*/
	void setOffset(double X, double Y, double Z, bool offsetManual);
	/**
	* Setzt ob es ein detailliertes Logging geben soll
	* @brief Setzt ob es ein detailliertes Logging geben soll
	* @param bool initLoggingManual
	*/
	void setLogging(bool initLoggingManual);
	/**
	* Gibt die eingegebene Geschwindigkeit zurück
	* @brief Gibt Geschwindigkeit zurück
	*/
	double getSpeed(void);
	/**
	* Gibt zurück ob händische Geschwindigekit verwendet werden soll, sonst wird sie später berechnet.
	* @brief Gibt zurück ob händische Geschwindigkeit verwendet werden soll
	*/
	bool getSpeedManual(void);
	/**
	* Gibt zurück ob händische Orientierung verwendet werden soll, sonst wird sie später berechnet.
	* @brief Gibt zurück ob händische Orientierung verwendet werden soll
	*/
	bool getOrientationManual(void);
	/**
	* Gibt die eingegebenen Winkel als tuple zurück
	* @brief Gibt Winkel zurück
	* @return: tuple <double double double> angles
	*/
	tuple <double, double, double> getAngles(void);
	/**
	* Gibt zurück ob ein Offset eingestellt werden soll
	* @brief Gibt zurück ob ein Offset eingestellt werden soll
	*/
	bool getOffsetManual(void);
	/**
	* Gibt zurück ob ein detailliertes Logging ausgegeben werden soll
	* @brief Gibt zurück ob ein detailliertes Logging ausgegeben werden soll
	*/
	bool getLoggingManual(void);
	/**
	* Gibt den Offset als tuple zurück
	* @brief Gibt Offset zurück
	* @return: tuple <double double double> offset
	*/
	tuple <double, double, double> getOffset(void);

	/**
	* Liest die Daten aus einen beliebigen File ein und ruft @detectJump auf um zu erkennen ob es mehrere Aufnahmen sind.
	* @brief Liest die Daten aus dem Input File ein
	* @param File Pfad
	*/
	void openFile(std::string path);
	/**
	* Um zu erkennen ob es mehrere Pfade sind wird nach Sprüngen gesucht, bei einem Sprung wird eine neue Liste angefangen.
	* @brief Erkennt Sprünge in den Daten
	* @param CInputPoint3D p den aktuellen Punkt
	* @param double x_prev die vorherige x Position
	* @param double y_prev die vorherige y Position
	* @param double z_prev die vorherige z Position
	*/
	bool detectJump(CInputPoint3D p, double x_prev, double y_prev, double z_prev);
	/**
	* @brief Gibt Pfad zurück
	* @return: vector<list<CInputPoint3D>> den eingelesen Pfad
	*/
	vector<list<CInputPoint3D>>& getPath();

private:
	/**
	* Vector mit Listen an Input Daten
	*/
	vector<list<CInputPoint3D>> initialPath;
	/**
	* User eingegebene Geschwindigkeit
	*/
	double speed;
	/**
	* Auswahl ob berechnete oder eingegebene Geschwindigkeit verwendet werden soll
	*/
	bool speedManual;
	/**
	* Auswahl ob berechnete oder eingegebene Winkel verwendet werden soll
	*/
	bool orientationManual;
	/**
	* User eingegebener Winkel A
	*/
	double A;
	/**
	* User eingegebener Winkel B
	*/
	double B;
	/**
	* User eingegebener Winkel C
	*/
	double C;
	/**
	* Sprung ab dem eine neue Liste angefangen wird
	*/
	double difference = 20;
	/**
	* Auswahl ob ein Offset eingegeben werden soll
	*/
	bool offsetManual;
	/**
	* Offset X
	*/
	double offsetX;
	/**
	* Offset Y
	*/
	double offsetY;
	/**
	* Offset Z
	*/
	double offsetZ;
	/**
	* Auswahl ob ein Offset eingegeben werden soll
	*/
	bool loggingManual;
};

