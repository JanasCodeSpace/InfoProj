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

	vector<CInputPoint3D>& getPath();

	void createPath(vector<list<CInputPoint3D>>& segments, string filename);

private:
	vector<CInputPoint3D> path;
};

