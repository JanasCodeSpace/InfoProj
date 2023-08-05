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

	list<CPoint3D>& getPath();

	void calculateMean(vector<list<CPoint3D>>& sourcePath);

private:
	int windowSize;
	int position;

	list<CPoint3D> path;
};

