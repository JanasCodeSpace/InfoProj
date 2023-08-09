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

	vector<list<CInputPoint3D>>& getPath();

	list<CInputPoint3D> calculateMean(list<CInputPoint3D>& segment);
	void mean(vector<list<CInputPoint3D>>& sourcePath);

private:
	int windowSize;
	int position;
	double sum;

	vector<list<CInputPoint3D>> meanPath;
};

