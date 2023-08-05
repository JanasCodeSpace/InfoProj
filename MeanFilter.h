#include <vector>
#include <list>
#include "Point3D.h"

#pragma once

using namespace std;


class CMeanFilter
{
public:
	CMeanFilter();
	CMeanFilter(int Window, long lenth);
	~CMeanFilter();

	void setWindowSize(int Window);

	int getWindowSize();

	vector<CPoint3D>& getPath();

	void calculateMean(vector<CPoint3D>& sourcePath);

private:
	int windowSize;
	int position;

	vector<CPoint3D> path;
};

