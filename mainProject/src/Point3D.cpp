/**
 * @file Point3D.cpp
 *
 * @brief Source File Punkte
 */

#include "./header/Point3D.h"
#include "./header/Line3D.h"
#include <math.h>


/* initialisieren des Punktes */
CPoint3D::CPoint3D(void)
{
 	x = 0;
	y = 0;
	z = 0;
}

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
	return x;
}

double CPoint3D::getY(void)
{
	return y;
}

double CPoint3D::getZ(void)
{
	return z;
}

void CPoint3D::setX(double X)
{
	x = X;
}

void CPoint3D::setY(double Y)
{
	y = Y;
}

void CPoint3D::setZ(double Z)
{
	z = Z;
}

void CPoint3D::set(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

double CPoint3D::distanceTo(CPoint3D point)
{
	return sqrt(pow((double)(x - (double)point.getX()), 2) + pow((double)(y - (double)point.getY()), 2) + pow((double)(z - (double)point.getZ()), 2));	// Pythagoras 3D
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
	timestamp = 0;
}

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
	orientationMatrix = orientation;
}


void CInputPoint3D::setPoint(double time, double X, double Y, double Z, CEulerMatrix orientation)
{
	setTime(time);
	set(X, Y, Z);
	setEulerMatrix(orientation);
}

void CInputPoint3D::setTime(double time)
{
	timestamp = time;
}

CEulerMatrix CInputPoint3D::getEulerMatrix()
{
	return orientationMatrix;
}

double CInputPoint3D::getTime()
{
	return timestamp;
}

// OutputPoint3D

COutputPoint3D::COutputPoint3D(void) : CPoint3D()
{
	speed = 0;
	a = 0;
	b = 0;
	c = 0;
}

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
	return a;
}

double COutputPoint3D::getB(void)
{
	return b;
}

double COutputPoint3D::getC(void)
{
	return c;
}

double COutputPoint3D::getSpeed(void)
{
	return speed;
}

void COutputPoint3D::setA(double A)
{
	a = A;
}

void COutputPoint3D::setB(double B)
{
	b = B;
}

void COutputPoint3D::setC(double C)
{
	c = C;
}

void COutputPoint3D::setSpeed(double Speed)
{
	speed = Speed;
}