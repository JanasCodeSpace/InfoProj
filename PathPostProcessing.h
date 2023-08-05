#include <vector>
#include <list>
#include <iostream>
#include "Point3D.h"

using namespace std;

#pragma once

class CPathPostProcessing
{
public:
	CPathPostProcessing(void);
	CPathPostProcessing(double speedIn, bool speedManualIn, bool orientationManualIn, double AIn, double BIn, double CIn);
	~CPathPostProcessing(void);

	vector<CPoint3D>& getProcessedPath(void);

	void postProcessing(vector<CPoint3D>& processedPath);
	void changeSpeedManual(CPoint3D p);
	void calculateSpeed(CPoint3D p);
	void changeEulerManual(CPoint3D p);

	void setData(double speed, bool speedManual, bool orientationManual, double A, double B, double C);

private:
	vector<CPoint3D> processedPath;
	float maxSpeed = 2.0;
	double speed;
	bool speedManual;
	bool orientationManual;
	double A;
	double B;
	double C;
};

