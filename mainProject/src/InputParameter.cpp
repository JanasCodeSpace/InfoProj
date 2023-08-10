/**
 * @file: InputParameter.c
 * 
 * @brief: Source File Daten Einlesen
 */

#include "./header/InputParameter.h"
#include "./header/Point3D.h"
#include "./header/EulerMatrix.h"

 /**
  * Initialiserung der Klasse mit allen Werten
  */
CInputParameter::CInputParameter(double initSpeed, bool initSpeedManual, bool initOrientationManual, double initA, double initB, double initC)
{
	speed = initSpeed;
	speedManual = initSpeedManual;
	orientationManual = initOrientationManual;
	A = initA;
	B = initB;
	C = initC;

}
/**
 * Initialiserung der Klasse mit 0
 */
CInputParameter::CInputParameter(void)
{
	speed = 0;
	A = 0;
	B = 0;
	C = 0;
	speedManual = false,
	orientationManual = false;

}
/**
 * Dekonstruktor
 */
CInputParameter::~CInputParameter(void)
{

}

void CInputParameter::setOrientation(bool initOrientationManual, double initA, double initB, double initC)
{
	orientationManual = initOrientationManual;
	A = initA;
	B = initB;
	C = initC;
}

void CInputParameter::setSpeed(double initSpeed, bool initSpeedManual)
{
	speed = initSpeed;
	speedManual = initSpeedManual;
}

vector<list<CInputPoint3D>>& CInputParameter::getPath()
{
	return initialPath;
}

double CInputParameter::getSpeed(void)
{
	return speed;
}

bool CInputParameter::getSpeedManual(void)
{
	return speedManual;
}

bool CInputParameter::getOrientationManual(void)
{
	return orientationManual;
}

tuple <double, double, double> CInputParameter::getAngles(void)
{
	return make_tuple(A, B, C);
}

void CInputParameter::openFile(string path)
{
	ifstream fin(path);
	char delimiter = ' ';
	CInputPoint3D tmpPoint;
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
			initialPath.push_back(list<CInputPoint3D>());
		}

		initialPath[segmentCount].push_back(tmpPoint);

		x_prev = x;
		y_prev = y;
		z_prev = z;
	}
	fin.close();
}

bool CInputParameter::detectJump(CInputPoint3D p, double x_prev, double  y_prev, double z_prev)
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
