/**
 * @file: RobCodeGenerator.h
 *
 * @brief: Erstellung des Roboter Codes
 */

#include <vector>
#include <iostream>
#include "Point3D.h"
#include <tuple>

using namespace std;

#pragma once

#define MAX_SPEED 2.0

class CRobCodeGenerator
{
public:
	CRobCodeGenerator(void);
	CRobCodeGenerator(double speedIn, bool speedManualIn, bool orientationManualIn, tuple<double, double, double> angles);
	~CRobCodeGenerator(void);

	void generateRobCode(vector<CInputPoint3D>& path, string filename);
	void postProcessing(vector<CInputPoint3D>& path);
	double calculateSpeed(CInputPoint3D& p, size_t i, double timePrev);
	void calculateAngles(COutputPoint3D& p, CInputPoint3D& pIn);

private:
	vector<COutputPoint3D> processedPath;
	double speed;
	bool speedManual;
	bool orientationManual;
	double A;
	double B;
	double C;

};

