#pragma once

#include "EulerMatrix.h"
#include <string>
#include "Point3D.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class CInputParameter
{
public:
	CInputParameter(void);
	~CInputParameter(void);

	vector<CPoint3D>& CInputParameter::getPath();

	void openFile(std::string path, vector<CPoint3D>& point);
private:
	vector<CPoint3D> initialPath;
	double speed;
	bool speedManual;
	bool orientationManual;
	double lengthA;
	double lengthB;
	double lengthC;
	CEulerMatrix inputMatrix;
};

