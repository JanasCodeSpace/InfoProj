/**
 * @file PathBuilder.cpp
 *
 * @brief Source File Segmente zu Pfad
 */

#include "./header/PathBuilder.h"

CPathBuilder::CPathBuilder(void)
{
}


CPathBuilder::~CPathBuilder(void)
{
}

vector<CInputPoint3D>& CPathBuilder::getPath()
{
	return path;
}

void CPathBuilder::createPath(vector<list<CInputPoint3D>>& segments, CLogging log)
{
	CInputPoint3D point; //startpoint
	//path.push_back(point);

	for (size_t s = 0; s < segments.size(); s++) //for all segments
	{
		list<CInputPoint3D>::iterator itr = segments[s].begin();
		/*
		point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ()); //point over start of segment
		point.setTime(itr->getTime());
		point.setEulerMatrix(itr->getEulerMatrix());
		path.push_back(point);
*/
		for (; itr != segments[s].end(); itr++) //for all points in the segment
		{
			point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ());
			point.setTime(itr->getTime());
			point.setEulerMatrix(itr->getEulerMatrix());
			path.push_back(point);
		}

		itr--;
		/*
		point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ()); //point over end of segment
		point.setTime(itr->getTime());
		point.setEulerMatrix(itr->getEulerMatrix());
		path.push_back(point);*/
	}

	point.set(0, 0, 0); //endpoint (== startpoint)
	path.push_back(point);

	log.setStep(4);
	log.logData(path);
}
