#pragma once

#include "EulerMatrix.h"
#include <string>
#include "Point3D.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

class CInputParameter
{
	float speed;
	bool speedManual;
	bool orientationManual;
	float lengthA;
	float lengthB;
	float lengthC;
	CEulerMatrix inputMatrix;

public:
	void openFile(std::string path, list<CPoint3D>& point);
};

