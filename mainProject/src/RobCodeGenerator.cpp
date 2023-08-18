/**
 * @file RobCodeGenerator.cpp
 *
 * @brief Source File Roboter Code Erstellung
 */

#include "./header/RobCodeGenerator.h"
#include "./header/Point3D.h"

CRobCodeGenerator::CRobCodeGenerator(void)
{
	speed = 0;
	speedManual = 0;
	orientationManual = 0;
	A = 0;
	B = 0;
	C = 0;
}

CRobCodeGenerator::CRobCodeGenerator(double Speed, bool SpeedManual, bool OrientationManual, tuple<double, double, double> angles)
{
	speed = Speed;
	speedManual = SpeedManual;
	orientationManual = OrientationManual;
	A = get<0>(angles);
	B = get<1>(angles);
	C = get<2>(angles);
}

CRobCodeGenerator::~CRobCodeGenerator(void)
{
}

void CRobCodeGenerator::generateRobCode(vector<CInputPoint3D>& points, string filename)
{
	postProcessing(points); // Calculates all the necessary values

	errno_t err;
	
	FILE* fid;

	if ((err = fopen_s(&fid, filename.c_str(), "w")) != 0) // Errorhandling for File opening
	{ 
		string msg = "Open file: ";
		msg += filename;
		msg += " failed!";

		throw exception(msg.c_str());
	}

	filename.erase(filename.end()-4,filename.end());
	fprintf(fid, "DEF %s \n", filename.c_str());

	fputs("PTP $POS_ACT\n", fid);

	if (speedManual) // If the speed is set to manual, it will be defined once at the beginning of the file
	{
		fprintf(fid, "$VEL.CP %f\n", speed);
	}

	for (size_t s = 0; s < points.size(); s++)
	{
		if (!speedManual) // If the speed is calculated it needs to be before every LIN command
			fprintf(fid, "&VEL.CP %f\n", (float)processedPath[s].getSpeed());
		fprintf(fid, "LIN {X %f, Y %f, Z %f, A %f, B %f, C %f}\n", round(processedPath[s].getX() * 10.0) / 10.0, round(processedPath[s].getY() * 10.0) / 10.0, 
			round(processedPath[s].getZ() * 10.0) / 10.0, round(processedPath[s].getA() * 10.0) / 10.0, round(processedPath[s].getB() * 10.0) / 10.0, 
			round(processedPath[s].getC() * 10.0) / 10.0);
	}

	fputs("END", fid);
}

void CRobCodeGenerator::postProcessing(vector<CInputPoint3D>& path)
{
	COutputPoint3D p;
	CInputPoint3D  pIn;
	double timePrev = 1;

	for (size_t s = 0; s < path.size(); s++) // Für jeden Punkt in dem Vector
	{
		p.set(path[s].getX(), path[s].getY(), path[s].getZ());
		if (speedManual)
		{
			if (speed > MAX_SPEED) //Wenn maximale Geschwindigkeit �berschritten wird, Geschwindigkeit begrenzen
				speed = MAX_SPEED;
		}
		else
		{
			if (s == 0)
				p.setSpeed(1); //Der erste Punkt(0) wird mit Standardgeschwindigkeit 1m/s angefahren.

			else
				p.setSpeed(calculateSpeed(path[s], s, timePrev)); //Die Geschwindigkeit zwischen den weiteren Punkten wird berechnet.
		}

		if (orientationManual) // Wenn der Winkel vorgegeben ist diesen setzten
		{
			p.setA(A);
			p.setB(B);
			p.setC(C);
		}
		else // Sonst den Winkel berechnen
			calculateAngles(p, path[s]);
		timePrev = path[s].getTime();
		processedPath.push_back(p);
	}

}

double CRobCodeGenerator::calculateSpeed(CInputPoint3D& p, size_t s, double timePrev)
{
	double distance = 0;
	double time = 0;

	distance = processedPath[s - 1].distanceTo(p); //Strecke zwischen p und dem Punkt zuvor
	time = p.getTime() - timePrev; //Zeit zwischen p-1 und p

	speed = distance / time; // Berechnug Geschwindigkeit zwischen zwei Punkten

	if (speed > MAX_SPEED) //Begrenzung auf maximale Geschwindigkeit, falls Trackerdaten h�heren Wert aufweisen
		speed = MAX_SPEED;

	return speed; //Zuweisung der Geschwindigkeit
}

void CRobCodeGenerator::calculateAngles(COutputPoint3D& p, CInputPoint3D& pIn)
{
	// Funktion in Eulermatrix aufrufen die a/b/c neu berechnet

	CEulerMatrix matrix = pIn.getEulerMatrix();
	tuple<double, double, double> abc;

	abc = matrix.calculateAngels();

	p.setA(get<0>(abc));
	p.setB(get<1>(abc));
	p.setC(get<2>(abc));
}
