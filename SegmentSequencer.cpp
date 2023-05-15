#include "SegmentSequencer.h"

CSegmentSequencer::CSegmentSequencer(void)
{
}


CSegmentSequencer::~CSegmentSequencer(void)
{
}


vector<list<CPoint2D>>& CSegmentSequencer::getSegmentsSortedVector()
{
	return segmentsSorted;
}

void CSegmentSequencer::sortSegments(const vector<list<CPoint2D>>& segments)
{
	vector<list<CPoint2D>> segmentsCopy = segments;

	CPoint2D currPoint = CPoint2D(0,0); //Start at x = 0, y = 0

	double dist, minDist;
	size_t minIndex; 
	bool reverse = false;

	while (segmentsCopy.size() > 0) //until all segments are sorted
	{
		minDist = numeric_limits<double>::max();

		for (size_t s = 0; s < segmentsCopy.size(); s++) //for all segments
		{
			dist = segmentsCopy.at(s).begin()->distanceTo(currPoint); //get distance to start of segment

			if (dist < minDist) 
			{
				minDist = dist;
				minIndex = s;
				reverse = false;
			}

			dist = (--segmentsCopy.at(s).end())->distanceTo(currPoint); //get distance to end of segment

			if (dist < minDist) 
			{
				minDist = dist;
				minIndex = s;
				reverse = true;
			}
		}

		if (reverse)
		{
			segmentsCopy[minIndex].reverse(); //reverse direction of segment
		}

		segmentsSorted.push_back(segmentsCopy[minIndex]); //store segment with minimum distance 

		currPoint.setX((--(--segmentsSorted.end())->end())->getX()); //store end of segment as current Point
		currPoint.setY((--(--segmentsSorted.end())->end())->getY());

		segmentsCopy.erase(segmentsCopy.begin() + minIndex); //delete segment 

	}
}
