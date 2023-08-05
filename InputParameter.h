#pragma once

#include "EulerMatrix.h"
#include <string>
#include "Point3D.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream> 

using namespace std;

#pragma once
class CInputParameter
{
public:
	CInputParameter(void);
	~CInputParameter(void);

	void openFile(std::string path);
	list<CPoint3D>& getPath();

private:
	list<CPoint3D> initialPath;
	double speed;
	bool speedManual;
	bool orientationManual;
	double A;
	double B;
	double C;
	CEulerMatrix inputMatrix;
};

