#include "Point3D.h"
#include "Line3D.h"
#include <math.h>



CPoint3D::CPoint3D(void)
{
	timestamp = 0;
	x = 0;
	y = 0;
	z = 0;
}

CPoint3D::CPoint3D(double time, double X, double Y, double Z)
{
	timestamp = time;
	x = X;
	y = Y;
	z = Z;
}

CPoint3D::~CPoint3D(void)
{
}


double CPoint3D::getTime()
{
	return timestamp;
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

CEulerMatrix CPoint3D::getEulerMatrix()
{
	return orientationMatrix;
}



void CPoint3D::setTime(double time)
{
	timestamp = time;
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

void CPoint3D::setEulerMatrix(CEulerMatrix orientation)
{
	orientationMatrix = orientation;
}


void CPoint3D::setPoint(double time, double X, double Y, double Z, CEulerMatrix orientation)
{
	setTime(time);
	set(X, Y, Z);
	setEulerMatrix(orientation);
}

void CPoint3D::set(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}


double CPoint3D::distanceTo(CPoint3D point)
{
	return sqrt(pow((double)(x - (double)point.getX()), 2) + pow((double)(y - (double)point.getY()), 2));
}

double CPoint3D::distanceTo(CLine3D line)
{
	double bx, by, bz, rv_sq, dist;

	int rvx = line.p1.x - line.p2.x;
	int rvy = line.p1.y - line.p2.y;
	int rvz = line.p1.z - line.p2.z;

	rv_sq = ((double)rvx * (double)rvx) + ((double)rvy * (double)rvy);

	bx = x - (double)line.p1.x;
	by = y - (double)line.p1.y;
	bz = z - (double)line.p1.z;

	dist = fabs((bx * rvy - by * rvx)) / sqrt(rv_sq);

	return dist;
}