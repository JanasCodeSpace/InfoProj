#pragma once

#include "EulerMatrix.h"
#include <string>
#include "Point3D.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <tuple>

using namespace std;

#pragma once
class CInputParameter
{
public:
	CInputParameter(void);
	CInputParameter(double initSpeed, bool initSeepManual, bool initOrientationManual, double initA, double initB, double initC);
	~CInputParameter(void);

	void setOrientation(bool initOrientationManual, double initA, double initB, double initC);
	void setSpeed(double initSpeed, bool initSpeedManual);

	double getSpeed(void);
	bool getSpeedManual(void);
	bool getOrientationManual(void);
	tuple <double, double, double> getAngles(void);

	void openFile(std::string path);
	bool detectJump(CInputPoint3D p, double x_prev, double  y_prev,double z_prev);
	vector<list<CInputPoint3D>>& getPath();

private:
	vector<list<CInputPoint3D>> initialPath;
	double speed;
	bool speedManual;
	bool orientationManual;
	double A;
	double B;
	double C;
	double difference = 20;
};

