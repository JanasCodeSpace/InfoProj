#include "Point3D.h"
#include <math.h>

using namespace std;

#pragma once
class CLine3D
{
public:
	CLine3D(void);
	CLine3D(CPoint3D P1, CPoint3D P2);
	~CLine3D(void);

	CPoint3D p1;
	CPoint3D p2;
};

