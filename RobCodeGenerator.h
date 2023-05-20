#include <vector>
#include <list>
#include <iostream>
#include "Point3D.h"

using namespace std;

#pragma once
class CRobCodeGenerator
{
public:
	CRobCodeGenerator(void);
	~CRobCodeGenerator(void);

	void generateRobCode(vector<CPoint3D>& path, string filename);

	double scaleX;
	double scaleY;
	double scaleZ;

	double offsetX;
	double offsetY;
	double offsetZ;
};

