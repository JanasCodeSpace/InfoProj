/**
 * @file: Point3D.h
 *
 * @brief: Handling der Punkte
 */

//TODO: Kommentare

#include "EulerMatrix.h"

class CLine3D;

using namespace std;

#pragma once

/**
 * Das ist die Grundklasse eines Punktes, hier lassen sich die Basiswerte 
 * setzten und Abstände zwishen Punkten berechnen.
 * @brief: Grundklasse Punkt
 */
class CPoint3D
{
public:
	CPoint3D(void);
	CPoint3D(double X, double Y, double Z);
	~CPoint3D(void);

	double getX();
	double getY();
	double getZ();

	void setX(double X);
	void setY(double Y);
	void setZ(double Z);

	void set(double X, double Y, double Z);
	double distanceTo(CPoint3D point);
	double distanceTo(CLine3D line);

protected:
	double x, y, z;
};

class CInputPoint3D : public CPoint3D
{	
public:
	CInputPoint3D(void);
	CInputPoint3D(double X, double Y, double Z, double Timestamp, CEulerMatrix Matrix);
	~CInputPoint3D(void);
	
	double getTime();
	CEulerMatrix getEulerMatrix();

	void setTime(double time);	
	void setEulerMatrix(CEulerMatrix orientation);
	void setPoint(double time, double X, double Y, double Z, CEulerMatrix orientation);

private:
	double timestamp;
	CEulerMatrix orientationMatrix;
};

class COutputPoint3D : public CPoint3D
{
public:
	COutputPoint3D(void);
	COutputPoint3D(double Speed, double X, double Y, double Z, double A, double B, double C);
	~COutputPoint3D(void);

	double getSpeed();
	double getA();
	double getB();
	double getC();

	//void setPoint(double speed, double X, double Y, double Z, CEulerMatrix orientation);
	void setSpeed(double speed);
	void setA(double A);
	void setB(double B);
	void setC(double C);
private:
	double a, b, c;
	double speed;
};
