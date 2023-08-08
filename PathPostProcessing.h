#include <vector>
#include <list>
#include <iostream>
#include "Point3D.h"

using namespace std;

#pragma once

#define MAX_SPEED 2.0

class CPathPostProcessing
{
public:
	CPathPostProcessing(void);
	CPathPostProcessing(double speedIn, bool speedManualIn, bool orientationManualIn, double AIn, double BIn, double CIn);
	~CPathPostProcessing(void);

	vector<CPoint3D>& getProcessedPath(void);

	void postProcessing(vector<CPoint3D>& path);
	void calculateSpeed(CPoint3D& p, size_t i);
	void changeEulerManual(CPoint3D& p);

	void setData(double speed, bool speedManual, bool orientationManual, double A, double B, double C);

private:
	vector<CPoint3D> processedPath;
	double speed;
	bool speedManual;
	bool orientationManual;
	double A;
	double B;
	double C;
};

