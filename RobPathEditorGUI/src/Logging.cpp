#include "header/Logging.h"

CLogging::CLogging(void)
{
	step = 0;
}

CLogging::CLogging(string Path)
{
	path = Path;
}

CLogging::~CLogging(void)
{

}

void CLogging::setStep(int Step)
{
	step = Step;
}

void CLogging::logData(vector<list<CInputPoint3D>>& sourcePath)
{
	string filepath;
	float dummyMatrix[3][3];
	CEulerMatrix tmpEuler;

	filepath = path + "/" + "0" + std::to_string(step) + "_path.csv";

	FILE* fid = fopen(filepath.c_str(), "w");

	if (fid == NULL)
	{
		cerr << "ERROR - Can NOT write to output file!\n";
		return;
	}

	fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", 
		(double)0, (double)0, (double)0, (double)0, (float)0, (float)0, (float)0,
		(float)0, (float)0, (float)0, (float)0, (float)0, (float)0);

	for (size_t s = 0; s < sourcePath.size(); s++) //for all segments
	{
		list<CInputPoint3D>::iterator itr = sourcePath[s].begin();

		tmpEuler = itr->getEulerMatrix();
		tmpEuler.getMatrix(dummyMatrix);

		fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)itr->getTime(), (double)itr->getX(), (double)itr->getY(), (double)itr->getZ(),
			dummyMatrix[0][0], dummyMatrix[0][1], dummyMatrix[0][2], dummyMatrix[1][0],
			dummyMatrix[1][1], dummyMatrix[1][2], dummyMatrix[2][0], dummyMatrix[2][1],
			dummyMatrix[2][2]);


		for (; itr != sourcePath[s].end(); itr++) //for all points in the segment
		{
			fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)itr->getTime(), (double)itr->getX(), (double)itr->getY(), (double)itr->getZ(),
				dummyMatrix[0][0], dummyMatrix[0][1], dummyMatrix[0][2], dummyMatrix[1][0],
				dummyMatrix[1][1], dummyMatrix[1][2], dummyMatrix[2][0], dummyMatrix[2][1],
				dummyMatrix[2][2]);
		}

		itr--;
		fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)itr->getTime(), (double)itr->getX(), (double)itr->getY(), (double)itr->getZ(),
			dummyMatrix[0][0], dummyMatrix[0][1], dummyMatrix[0][2], dummyMatrix[1][0],
			dummyMatrix[1][1], dummyMatrix[1][2], dummyMatrix[2][0], dummyMatrix[2][1],
			dummyMatrix[2][2]);
	}

	fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n",
		(double)0, (double)0, (double)0, (double)0, (float)0, (float)0, (float)0,
		(float)0, (float)0, (float)0, (float)0, (float)0, (float)0);
}

void CLogging::logData(vector<CInputPoint3D>& sourcePath)
{
	string filepath;
	float dummyMatrix[3][3];
	CEulerMatrix tmpEuler;

	filepath = path + "/" + "0" + std::to_string(step) + "_path.csv";

	FILE* fid = fopen(filepath.c_str(), "w");

	if (fid == NULL)
	{
		cerr << "ERROR - Can NOT write to output file!\n";
		return;
	}

	fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n",
		(double)0, (double)0, (double)0, (double)0, (float)0, (float)0, (float)0,
		(float)0, (float)0, (float)0, (float)0, (float)0, (float)0);

	for (size_t s = 0; s < sourcePath.size(); s++) //for all segments
	{
		tmpEuler.getMatrix(dummyMatrix);

		fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)sourcePath[s].getTime(), 
			(double)sourcePath[s].getX(), (double)sourcePath[s].getY(), (double)sourcePath[s].getZ(),
			dummyMatrix[0][0], dummyMatrix[0][1], dummyMatrix[0][2], dummyMatrix[1][0],
			dummyMatrix[1][1], dummyMatrix[1][2], dummyMatrix[2][0], dummyMatrix[2][1],
			dummyMatrix[2][2]);
	}

	fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n",
		(double)0, (double)0, (double)0, (double)0, (float)0, (float)0, (float)0,
		(float)0, (float)0, (float)0, (float)0, (float)0, (float)0);
}
