#include <vector>
#include <list>


#pragma once
#include "Point3D.h"

using namespace std;


#pragma once
class CSegmentSequencer
{
public:
	CSegmentSequencer(void);
	~CSegmentSequencer(void);

	vector<list<CPoint3D>>& getSegmentsSortedVector();

	void sortSegments(const vector<list<CPoint3D>>& segments);

private:
	
	vector<list<CPoint3D>> segmentsSorted;

};

