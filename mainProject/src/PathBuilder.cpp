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

void CPathBuilder::createPath(vector<list<CInputPoint3D>>& segments, string filename)
{

	FILE* fid = fopen(filename.c_str(), "w");

	if (fid == NULL)
	{ 
		cerr << "ERROR - Can NOT write to output file!\n";
		return;
	}

	CInputPoint3D point; //startpoint
	path.push_back(point);

	fprintf(fid, "%f %f %f\n", (double)0, (double)0, (double)0);

	for (size_t s = 0; s < segments.size(); s++) //for all segments
	{
		list<CInputPoint3D>::iterator itr = segments[s].begin();

		point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ()); //point over start of segment
		path.push_back(point);

		fprintf(fid, "%f %f %f\n", (double)itr->getX(), (double)itr->getY(), (double)itr->getZ());
		

		for (; itr != segments[s].end(); itr++) //for all points in the segment
		{
			fprintf(fid, "%f %f %f\n", (double)itr->getX(), (double)itr->getY(), (double)itr->getZ());

			point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ());
			path.push_back(point);

		}

		itr--;
		fprintf(fid, "%f %f %f\n", (double)itr->getX(), (double)itr->getY(), (double)itr->getZ());

		point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ()); //point over end of segment
		path.push_back(point);
	}

	fprintf(fid, "%f %f %f\n", (double)0, (double)0, (double)0);

	point.set(0, 0, 0); //endpoint (== startpoint)
	path.push_back(point);
}
