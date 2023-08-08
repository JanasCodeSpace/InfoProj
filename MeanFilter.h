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

	vector<list<CPoint3D>>& getPath();

	list<CPoint3D> calculateMean(list<CPoint3D>& segment);
	void mean(vector<list<CPoint3D>>& sourcePath);

private:
	int windowSize;
	int position;
	double sum;


	vector<list<CPoint3D>> meanPath;
};

