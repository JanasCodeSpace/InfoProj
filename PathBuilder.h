#include <vector>
#include <list>
#include <iostream>
#include "Point2D.h"
#include "Point3D.h"

using namespace std;

#pragma once
class CPathBuilder
{
public:
	CPathBuilder(void);
	~CPathBuilder(void);

	vector<CPoint3D>& CPathBuilder::getPath();

	void createPath(vector<list<CPoint2D>>& segments, string filename);

private:
	vector<CPoint3D> path;
};

