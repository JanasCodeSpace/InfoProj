/**
 * @file Line3D.cpp
 *
 * @brief Source File Line3D
 */

#include "../header/Line3D.h"
#include "../header/Point3D.h"

CLine3D::CLine3D(void)
{
}

/* initialisieren mit 2 Punkten*/
CLine3D::CLine3D(CPoint3D P1, CPoint3D P2)
{
	p1 = P1;
	p2 = P2;
}

CLine3D::~CLine3D(void)
{
}
