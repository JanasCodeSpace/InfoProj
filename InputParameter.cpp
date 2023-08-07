#include "InputParameter.h"
#include "Point3D.h"
#include "EulerMatrix.h"

CInputParameter::CInputParameter(void)
{

}

CInputParameter::~CInputParameter(void)
{

}

vector<list<CPoint3D>>& CInputParameter::getPath()
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
	double x_prev = 0, y_prev = 0, z_prev = 0;
	double timestamp;
	int segmentCount = -1;
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

		if (detectJump(tmpPoint, x_prev, y_prev, z_prev))
		{
			segmentCount++;
			initialPath.push_back(list<CPoint3D>());
		}

		initialPath[segmentCount].push_back(tmpPoint);

		x_prev = x;
		y_prev = y;
		z_prev = z;
	}
	fin.close();
}

bool CInputParameter::detectJump(CPoint3D p, double x_prev, double  y_prev, double z_prev)
{
	if(abs(p.getX() - x_prev) > difference)
		return true;
	else if(abs(p.getY() - y_prev) > difference)
		return true;
	else if(abs(p.getZ() - z_prev) > difference)
		return true;
	else
		return false;
}
