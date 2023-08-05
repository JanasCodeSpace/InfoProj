#include "InputParameter.h"
#include "Point3D.h"
#include "EulerMatrix.h"

CInputParameter::CInputParameter(void)
{

}

CInputParameter::~CInputParameter(void)
{

}

list<CPoint3D>& CInputParameter::getPath()
{
	return initialPath;
}

void CInputParameter::openFile(string path)
{
	ifstream fin(path);
	char delimiter = ' ';
	CPoint3D tmpPoint;
	CEulerMatrix tmpEuler;
	double x, y, z;
	double timestamp;
	float dummyMatrix[3][3];


	if (!fin.is_open())
	{
		cerr << "Datei konnte nicht geöffnet werden" << endl;
	}
	string line;

	while(getline(fin, line))
	{
		std::istringstream sStream (line);
		sStream >> timestamp >> x >> y >> z >> dummyMatrix[0][0] >> dummyMatrix[0][1] >> dummyMatrix[0][2]
			>> dummyMatrix[1][0] >> dummyMatrix[1][1] >> dummyMatrix[1][2] >> dummyMatrix[2][0] >> dummyMatrix[2][1] >> dummyMatrix[2][2];
		
		tmpEuler.setMatrix(dummyMatrix);
		tmpPoint.setPoint(timestamp, x, y, z, tmpEuler.getMatrix());

		initialPath.push_back(tmpPoint);

	}
	fin.close();

}
