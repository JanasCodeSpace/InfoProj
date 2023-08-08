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

void CPathPostProcessing::setData(double speedIn, bool speedManualIn, bool orientationManualIn, tuple <double, double, double> angles)
{
	speed = speedIn;
	speedManual = speedManualIn;
	orientationManual = orientationManualIn;
	A = get<0>(angles);
	B = get<1>(angles);
	C = get<2>(angles);
}

vector<CPoint3D>& CPathPostProcessing::getProcessedPath(void)
{
	return processedPath;
}

void CPathPostProcessing::postProcessing(vector<CPoint3D>& path)
{
	CPoint3D p;

	for (size_t s = 0; s < path.size(); s++)
	{
		p.setPoint(path[s].getTime(), path[s].getX(), path[s].getY(), path[s].getZ(), path[s].getEulerMatrix());
		if (speedManual)
		{
			if (speed > MAX_SPEED) //Wenn maximale Geschwindigkeit überschritten wird, Geschwindigkeit begrenzen
			speed = MAX_SPEED;

			p.setSpeed(speed);
		}
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

void CPathPostProcessing::calculateSpeed(CPoint3D& p, size_t s)
{
	double distance = 0;
	double time = 0;

	distance = processedPath[s-1].distanceTo(p); //Strecke zwischen p und dem Punkt zuvor
	time = p.getTime() - processedPath[s-1].getTime(); //Zeit zwischen p-1 und p

	speed = distance/time; // Berechnug Geschwindigkeit zwischen zwei Punkten

	if (speed > MAX_SPEED) //Begrenzung auf maximale Geschwindigkeit, falls Trackerdaten höheren Wert aufweisen
	speed = MAX_SPEED;

	p.setSpeed(speed); //Zuweisung der Geschwindigkeit
}

void CPathPostProcessing::changeEulerManual(CPoint3D& p)
{
	//Hier kommt das �berschreiben der Eulermatrix rein
}