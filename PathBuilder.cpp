#include "PathBuilder.h"

CPathBuilder::CPathBuilder(void)
{
}


CPathBuilder::~CPathBuilder(void)
{
}

vector<CPoint3D>& CPathBuilder::getPath()
{
	return path;
}

void CPathBuilder::createPath(vector<list<CPoint2D>>& segments, string filename)
{

	FILE* fid = fopen(filename.c_str(), "w");

	if (fid == NULL)
	{ 
		cerr << "ERROR - Can NOT write to output file!\n";
		return;
	}

	double zOffset = 1.0;

	CPoint3D point(0,0,zOffset); //startpoint
	path.push_back(point);

	fprintf(fid, "%f %f %f\n", (double)0, (double)0, (double)0 + zOffset);

	for (size_t s = 0; s < segments.size(); s++) //for all segments
	{
		list<CPoint2D>::iterator itr = segments[s].begin();

		point.set((double)itr->getX(), (double)itr->getY(), (double)0 + zOffset); //point over start of segment
		path.push_back(point);

		fprintf(fid, "%f %f %f\n", (double)itr->getX(), (double)itr->getY(), (double)0 + zOffset);
		

		for (; itr != segments[s].end(); itr++) //for all points in the segment
		{
			fprintf(fid, "%f %f %f\n", (double)itr->getX(), (double)itr->getY(), (double)0);

			point.set((double)itr->getX(), (double)itr->getY(), (double)0); 
			path.push_back(point);

		}

		itr--;
		fprintf(fid, "%f %f %f\n", (double)itr->getX(), (double)itr->getY(), (double)0 + zOffset);

		point.set((double)itr->getX(), (double)itr->getY(), (double)0 + zOffset); //point over end of segment
		path.push_back(point);
	}

	fprintf(fid, "%f %f %f\n", (double)0, (double)0, (double)0 + zOffset);

	point.set(0, 0, 0 + zOffset); //endpoint (== startpoint)
	path.push_back(point);
}
