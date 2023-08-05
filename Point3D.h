#include "EulerMatrix.h"

class CLine3D;

using namespace std;

#pragma once
class CPoint3D
{
public:
	CPoint3D(void);
	CPoint3D(double X, double Y, double Z);
	CPoint3D(double time, double X, double Y, double Z);
	~CPoint3D(void);

	double getTime();
	double getX();
	double getY();
	double getZ();
	CEulerMatrix getEulerMatrix();

	void setTime(double time);
	void setSpeed(double speedIn);
	void setX(double X);
	void setY(double Y);
	void setZ(double Z);
	void setEulerMatrix(CEulerMatrix orientation);

	void setPoint(double time, double X, double Y, double Z, CEulerMatrix orientation);
	void set(double X, double Y, double Z);
	double distanceTo(CPoint3D point);
	double distanceTo(CLine3D line);

private:
	double x, y, z;
	double timestamp;
	double speed;
	CEulerMatrix orientationMatrix;

};

