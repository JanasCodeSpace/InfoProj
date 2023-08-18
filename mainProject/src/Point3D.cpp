/**
 * @file Point3D.cpp
 *
 * @brief Source File Punkte
 */

#include "./header/Point3D.h"
#include "./header/Line3D.h"
#include <math.h>


/* initialisieren des Punktes mit 0-Werten */
CPoint3D::CPoint3D(void)
{
	x = 0;
	y = 0;
	z = 0;
}

/* initialiseren des Punktes mit Koordinaten */
CPoint3D::CPoint3D(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

CPoint3D::~CPoint3D(void)
{
}

double CPoint3D::getX(void)
{
	return x;	// X-Koordinate zurück geben
}

double CPoint3D::getY(void)
{
	return y;	// Y-Koordinate zurück geben
}

double CPoint3D::getZ(void)
{
	return z;	// Z-Koordinate zurück geben
}

void CPoint3D::setX(double X)
{
	x = X;	// X-Koordinate setzen
}

void CPoint3D::setY(double Y)
{
	y = Y;	// Y-Koordinate setzen
}

void CPoint3D::setZ(double Z)
{
	z = Z;	// Z-Koordinate setzen
}

/* X-, Y- und Z-Koordinate setzen */
void CPoint3D::set(double X, double Y, double Z)
{
	x = X;	// X-Koordinate setzen
	y = Y;	// Y-Koordinate setzen
	z = Z;	// Z-Koordinate setzen
}	

/* Distanz zwischen Punkt und übergebenen Punkt berechnen */
double CPoint3D::distanceTo(CPoint3D point)
{
	return sqrt(pow((double)(x - (double)point.getX()), 2) + pow((double)(y - (double)point.getY()), 2) + pow((double)(z - (double)point.getZ()), 2));	//  Pythagoras 3D
}

double CPoint3D::distanceTo(CLine3D line)
{
	double bx, by, bz, rv_sq, dist, vp1, vp2, vp3;			// Variablen Anlegen

	/*
	Vermessen wird der Punkt selbst

	bx, by, bz 		== Vektordifferenz
	rv_sq 			== Betrag des Linienvektors
	dist 			== Distanz von Punkt zu Linie
	vp1, vp2, vp3	== Vektorprodukte
	*/

	int rvx = line.p1.x - line.p2.x;		// Parameter X des Linienvektor berechnen
	int rvy = line.p1.y - line.p2.y;		// Parameter Y des Linienvektor berechnen
	int rvz = line.p1.z - line.p2.z;		// Parameter Z des Linienvektor berechnen

	rv_sq = sqrt(((double)rvx * (double)rvx) + ((double)rvy * (double)rvy) + ((double)rvz * (double)rvz));		// Betrag des Linienvektor berechnen

	bx = x - (double)line.p1.x;				// X(Punkt) - X(Aufpunkt) 
	by = y - (double)line.p1.y;				// Y(Punkt) - Y(Aufpunkt)
	bz = z - (double)line.p1.z;				// Z(Punkt) - Z(Aufpunkt)

	vp1 = by * rvz - bz * rvy; 				// Parameter X Vektorprodukt
	vp2 = bz * rvx - bx * rvz; 				// Parameter Y Vektorprodukt
	vp3 = bx * rvy - by * rvx; 				// Parameter Z Vektorprodukt

	dist = sqrt(vp1 * vp1 + vp2 * vp2 + vp3 * vp3) / rv_sq;	// Betrag des Vektors berechnen

	return dist;
}

// InputPoint3D

CInputPoint3D::CInputPoint3D(void) : CPoint3D()
{
	timestamp = 0;		// Zeitstempel mit 0 initialisieren
}

/* Initialisieren des Punktes mit Parameter */
CInputPoint3D::CInputPoint3D(double X, double Y, double Z, double Timestamp, CEulerMatrix Matrix)
{
	x = X;
	y = Y;
	z = Z;
	timestamp = Timestamp;
	orientationMatrix = Matrix;
}

CInputPoint3D::~CInputPoint3D(void)
{
}

void CInputPoint3D::setEulerMatrix(CEulerMatrix orientation)
{
	orientationMatrix = orientation;	// EulerMatrix setzen
}


void CInputPoint3D::setPoint(double time, double X, double Y, double Z, CEulerMatrix orientation)
{
	setTime(time);	// Zeitstempel setzen
	set(X, Y, Z);	// setze Punkt-Koordinaten
	setEulerMatrix(orientation); // EulerMatrix setzen
}

void CInputPoint3D::setTime(double time)
{
	timestamp = time;	// Zeitstempel setzen
}

CEulerMatrix CInputPoint3D::getEulerMatrix()
{
	return orientationMatrix;	// Rückgabe der EulerMatrix
}

double CInputPoint3D::getTime()
{
	return timestamp;		// Rückgabe des Zeitstempel
}

// OutputPoint3D
/* Punkt mit 0 initialisieren */
COutputPoint3D::COutputPoint3D(void) : CPoint3D()
{
	speed = 0;
	a = 0;
	b = 0;
	c = 0;
}

/* Punkt mit Parameter initialisieren*/
COutputPoint3D::COutputPoint3D(double Speed, double X, double Y, double Z, double A, double B, double C)
{
	speed = Speed;
	a = A;
	b = B;
	c = C;
	x = X;
	y = Y;
	z = Z;
}

COutputPoint3D::~COutputPoint3D(void)
{

}

double COutputPoint3D::getA(void)
{
	return a;	// Rückgabe Winkel alpha
}

double COutputPoint3D::getB(void)
{
	return b;	// Rückgabe Winkel beta
}

double COutputPoint3D::getC(void)
{
	return c;	// Rückgabe Winkel gamma
}

double COutputPoint3D::getSpeed(void)
{
	return speed;	// Rückgabe Geschwindigkeit
}

void COutputPoint3D::setA(double A)
{
	a = A;		// setze Winkel alpha
}

void COutputPoint3D::setB(double B)
{
	b = B;		// setze Winkel beta
}

void COutputPoint3D::setC(double C)
{
	c = C;		// setze Winkel gamma
}

void COutputPoint3D::setSpeed(double Speed)
{
	speed = Speed;		// setze Geschwindigkeit
}