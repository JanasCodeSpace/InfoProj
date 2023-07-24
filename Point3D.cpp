#include "Point3D.h"
#include "Line3D.h"
#include <math.h>


/* initialisieren des Punktes */
CPoint3D::CPoint3D(void)
{
	x = 0;
	y = 0;
	z = 0;
}

/* setzte X Y Z */
CPoint3D::CPoint3D(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}


CPoint3D::~CPoint3D(void)
{
}

/* setze jeweils X Y Z */
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

/* Ausgabe X Y Z */
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

/* setzte X Y Z */
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