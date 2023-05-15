#include <vector>
#include <list>
#include "Point2D.h"

using namespace std;

#pragma once
class CSegmentSequencer
{
public:
	CSegmentSequencer(void);
	~CSegmentSequencer(void);

	vector<list<CPoint2D>>& getSegmentsSortedVector();

	void sortSegments(const vector<list<CPoint2D>>& segments);

private:
	
	vector<list<CPoint2D>> segmentsSorted;

};

