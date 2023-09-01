/**
 * @file Point3D.h
 *
 * @brief Verarbeitung der Punkte
 */
#pragma once

#include "EulerMatrix.h"

class CLine3D;

using namespace std;

/**
 * Das ist die Grundklasse eines Punktes, hier lassen sich die Basiswerte
 * setzten und Abstaende zwishen Punkten berechnen.
 * @brief Grundklasse Punkt
 */
class CPoint3D
{
public:
	/**
	* Initialisiert des Punktes mit Null
	* @brief Default Konstruktor
	* @see CPoint3D(double X, double Y, double Z)
	*/
	CPoint3D(void);
	/**
	* Initialisiert des Punktes mit Null
	* @brief Default Konstruktor
	* @param double X
	* @param double Y
	* @param double Z
	* @see CPoint3D(void)
	*/
	CPoint3D(double X, double Y, double Z);
	/**
	* @brief Dekonstruktor
	*/
	~CPoint3D(void);

	/**
	* @brief Gibt X zurueck
	* @return double
	*/
	double getX();
	/**
	* @brief Gibt Y zurueck
	* @return double
	*/
	double getY();
	/**
	* @brief Gibt Z zurueck
	* @return double
	*/
	double getZ();

	/**
	* @brief Setzt X
	* @param double X
	*/
	void setX(double X);
	/**
	* @brief Setzt Y
	* @param double Y
	*/
	void setY(double Y);
	/**
	* @brief Setzt Z
	* @param double Z
	*/
	void setZ(double Z);

	/**
	* @brief Setzt X, Y und Z
	* @param double X
	* @param double Y
	* @param double Z
	*/
	void set(double X, double Y, double Z);
	/**
	* @brief Berechnet die Distanz zu einem anderen Punkt
	* @param CPoint3D point
	* @return double Distanz
	*/
	double distanceTo(CPoint3D point);
	/**
	* @brief Berechnet die Distanz zu einer Linie
	* @param CLine3D line
	* @return double Distanz
	*/
	double distanceTo(CLine3D line);

protected:
	/**
	* Koordinaten des Punkts
	*/
	double x, y, z;
};

/**
 * Kind der Punkt Grundklasse, erweitert um den Timestamp und die Eulermatrix
 * @brief Input Punkt
 */
class CInputPoint3D : public CPoint3D
{
public:
	/**
	* Initialisiert des eingelesenen Punktes mit Null
	* @brief Default Konstruktor
	* @see CInputPoint3D(double X, double Y, double Z, double Timestamp, CEulerMatrix Matrix)
	*/
	CInputPoint3D(void);
	/**
	* Initialisiert des eingelesenen Punktes mit Null
	* @brief Default Konstruktor
	* @param double X
	* @param double Y
	* @param double Z
	* @param double Timestamp
	* @param CEulerMatrix Matrix
	* @see CInputPoint3D(double X, double Y, double Z, double Timestamp, CEulerMatrix Matrix)
	*/
	CInputPoint3D(double X, double Y, double Z, double Timestamp, CEulerMatrix Matrix);
	/**
	* @brief Dekonstruktor
	*/
	~CInputPoint3D(void);

	/**
	* @brief Gibt den Zeitstempel zurueck
	* @return double Zeitstempel
	*/
	double getTime();
	/**
	* @brief Gibt die gespeicherte Eulermatrix zurueck
	* @return CEulerMatrix
	*/
	CEulerMatrix getEulerMatrix();

	/**
	* @brief Setzt den Zeitstempel
	* @param double time
	*/
	void setTime(double time);
	/**
	* @brief Setzt die Eulermatrix
	* @param CEulerMatrix orientation
	*/
	void setEulerMatrix(CEulerMatrix orientation);
	/**
	* @brief Setzt einen Input Punkt
	* @param double time
	* @param double X
	* @param double Y
	* @param double Z
	* @param CEulerMatrix orientation
	*/
	void setPoint(double time, double X, double Y, double Z, CEulerMatrix orientation);

private:
	/**
	* Zeitstempel
	*/
	double timestamp;
	/**
	* Eulermatrix des Punktes
	*/
	CEulerMatrix orientationMatrix;
};

/**
 * Kind der Punkt Grundklasse, erweitert um die Geschwindigkeit und die Drehwinkel
 * @brief Output Punkt
 */
class COutputPoint3D : public CPoint3D
{
public:
	/**
	* Initialisiert des fertig bearbeiteten Punktes mit Null
	* @brief Default Konstruktor
	* @see COutputPoint3D(double Speed, double X, double Y, double Z, double A, double B, double C);
	*/
	COutputPoint3D(void);
	/**
	* Initialisiert des eingelesenen Punktes mit Null
	* @brief Default Konstruktor
	* @param double Speed
	* @param double X
	* @param double Y
	* @param double Z
	* @param double A
	* @param double B
	* @param double C
	* @see CInputPoint3D(double X, double Y, double Z, double Timestamp, CEulerMatrix Matrix)
	*/
	COutputPoint3D(double Speed, double X, double Y, double Z, double A, double B, double C);
	/**
	* @brief Dekonstruktor
	*/
	~COutputPoint3D(void);

	/**
	* @brief Gibt die Geschwindigkeit zurueck
	* @return: double Geschwindigkeit
	*/
	double getSpeed();
	/**
	* @brief Gibt A zurueck
	* @return: double A
	*/
	double getA();
	/**
	* @brief Gibt B zurueck
	* @return: double B
	*/
	double getB();
	/**
	* @brief Gibt C zurueck
	* @return: double C
	*/
	double getC();

	/**
	* @brief Setzt die Geschwindigkeit
	* @param double speed
	*/
	void setSpeed(double speed);
	/**
	* @brief Setzt A
	* @param double A
	*/
	void setA(double A);
	/**
	* @brief Setzt B
	* @param double B
	*/
	void setB(double B);
	/**
	* @brief Setzt C
	* @param double C
	*/
	void setC(double C);
private:
	/**
	* Drehwinkel des Punktes
	*/
	double a, b, c;
	/**
	* Geschwindigkeit zum Punkt hin? TODO: ueberpruefen
	*/
	double speed;
};
