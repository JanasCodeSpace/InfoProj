#include "Point3D.h"



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
