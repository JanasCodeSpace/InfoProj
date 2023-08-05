#include "PathPostProcessing.h"


CPathPostProcessing::CPathPostProcessing(void)
{
}

CPathPostProcessing::CPathPostProcessing(double speedIn, bool speedManualIn, bool orientationManualIn, double AIn, double BIn, double CIn)
{
	speed = speedIn;
	speedManual = speedManualIn;
	orientationManual = orientationManualIn;
	A = AIn;
	B = BIn;
	C = CIn;
}

CPathPostProcessing::~CPathPostProcessing(void)
{
}

void CPathPostProcessing::setData(double speedIn, bool speedManualIn, bool orientationManualIn, double AIn, double BIn, double CIn)
{
	speed = speedIn;
	speedManual = speedManualIn;
	orientationManual = orientationManualIn;
	A = AIn;
	B = BIn;
	C = CIn;
}

vector<CPoint3D>& CPathPostProcessing::getProcessedPath(void)
{
	return processedPath;
}

void CPathPostProcessing::postProcessing(vector<CPoint3D>& processedPath)
{
	CPoint3D p;

	for (size_t s = 0; s < processedPath.size(); s++)
	{
		p.setPoint(processedPath[s].getTime(), processedPath[s].getX(), processedPath[s].getY(), processedPath[s].getZ(), processedPath[s].getEulerMatrix());
		if (speedManual)
			changeSpeedManual(p);
		else
			calculateSpeed(p);
		if (orientationManual)
			changeEulerManual(p);

		processedPath.push_back(p);
	}

}

void CPathPostProcessing::changeSpeedManual(CPoint3D p)
{
	double speed = 0;
	
	p.setSpeed(speed);
}

void CPathPostProcessing::calculateSpeed(CPoint3D p)
{
	double speed = 0;

	p.setSpeed(speed);
}

void CPathPostProcessing::changeEulerManual(CPoint3D p)
{
	//Hier kommt das überschreiben der Eulermatrix rein
}