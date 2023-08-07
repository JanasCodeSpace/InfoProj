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
	bool detectJump(CPoint3D p, double x_prev, double  y_prev,double z_prev);
	vector<list<CPoint3D>>& getPath();

private:
	vector<list<CPoint3D>> initialPath;
	double speed;
	bool speedManual;
	bool orientationManual;
	double A;
	double B;
	double C;
	CEulerMatrix inputMatrix;
	double difference = 20;
};

