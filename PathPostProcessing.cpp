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
			p.setSpeed(speed);
		else
		{
			if (s == 0)
				p.setSpeed(1); //Der erste Punkt(0) wird mit Standardgeschwindigkeit 1m/s angefahren.

			else
				calculateSpeed(p, s); //Die Geschwindigkeit zwischen den weiteren Punkten wird berechnet.
		}
			
		if (orientationManual)
			changeEulerManual(p);

		processedPath.push_back(p);
	}

}

void CPathPostProcessing::calculateSpeed(CPoint3D p, size_t s)
{
	double distance = 0;
	double time = 0;

	distance = processedPath[s-1].distanceTo(p); //Strecke zwischen p und dem Punkt zuvor
	time = p.getTime() - processedPath[s-1].getTime(); //Zeit zwischen p-1 und p

	speed = distance/time; // Berechnug Geschwindigkeit zwischen zwei Punkten
	p.setSpeed(speed); //Zuweisung der Geschwindigkeit zwis
}

void CPathPostProcessing::changeEulerManual(CPoint3D p)
{
	//Hier kommt das �berschreiben der Eulermatrix rein
}