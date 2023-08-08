#include <vector>
#include <list>
#include <iostream>
#include "Point3D.h"

using namespace std;

#pragma once
class CPathBuilder
{
public:
	CPathBuilder(void);
	~CPathBuilder(void);

	vector<CPoint3D>& getPath();

	void createPath(vector<list<CPoint3D>>& segments, string filename);

private:
	vector<CPoint3D> path;
};

