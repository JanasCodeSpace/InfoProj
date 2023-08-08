#include "Line3D.h"
#include "Point3D.h"

CLine3D::CLine3D(void)
{
}

CLine3D::CLine3D(CPoint3D P1, CPoint3D P2)
{
	p1 = P1;
	p2 = P2;
}

CLine3D::~CLine3D(void)
{
}
