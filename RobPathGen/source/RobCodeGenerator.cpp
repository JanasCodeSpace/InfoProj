/**
 * @file RobCodeGenerator.cpp
 *
 * @brief Source File Roboter Code Erstellung
 */

#include "../header/RobCodeGenerator.h"

/* CRobCodeGenerator mit 0 initialiseren */
CRobCodeGenerator::CRobCodeGenerator(void)
{
}

/* CRobCodeGenerator mit Uebergabewerten initialisieren */
CRobCodeGenerator::CRobCodeGenerator(CInputParameter inputParam)
{
	input = inputParam;
}

CRobCodeGenerator::~CRobCodeGenerator(void)
{
}

void CRobCodeGenerator::generateRobCode(vector<CInputPoint3D>& points, string filepath, string inputPath, CLogging log)
{
	string filename;
	
	postProcessing(points); // Calculates all the necessary values

	log.setStep(4);
	log.logData(processedPath);

	errno_t err;
	
	FILE* fid;

	filename = inputPath.substr(inputPath.find_last_of("/\\") + 1);
	filename.erase(filename.end() - 4, filename.end());
	filename = filename + ".src";

	string fullPath = filepath + "/" + filename;

	if ((err = fopen_s(&fid, fullPath.c_str(), "w")) != 0) // Errorhandling for File opening
	{ 
		string msg = "Open file: ";
		msg += filename;
		msg += " failed!";

		throw exception(msg.c_str());
	}

	filename.erase(filename.end()-4,filename.end());		// loescht .src
	fprintf(fid, "DEF %s \n", filename.c_str());			// DEF in file schreiben

	fputs("PTP $POS_ACT\n", fid);							// PTP zur aktuellen Position in file schreiben

	if (input.getSpeedManual()) // If the speed is set to manual, it will be defined once at the beginning of the file
	{
		fprintf(fid, "$VEL.CP = %f\n", input.getSpeed());		// Geschwindigkeit ein file schreiben
	}

	tuple <double, double, double> offset = input.getOffset();

	for (size_t s = 0; s < points.size(); s++)
	{
		if (!input.getSpeedManual()) // If the speed is calculated it needs to be before every LIN command
			fprintf(fid, "$VEL.CP = %f\n", (float)processedPath[s].getSpeed());
		fprintf(fid, "LIN {X %f, Y %f, Z %f, A %f, B %f, C %f}\n", processedPath[s].getX() + get<0>(offset), processedPath[s].getY() + get<1>(offset),
			processedPath[s].getZ() + get<2>(offset), processedPath[s].getA(), processedPath[s].getB(),
			processedPath[s].getC());
	}

	fputs("END", fid);
}

void CRobCodeGenerator::postProcessing(vector<CInputPoint3D>& path)
{
	COutputPoint3D p;
	double timePrev = 1;

	for (size_t s = 0; s < path.size(); s++) // Fuer jeden Punkt in dem Vector
	{
		p.set(path[s].getX(), path[s].getY(), path[s].getZ());
		if (input.getSpeedManual())
		{
			if (input.getSpeed() > MAX_SPEED) //Wenn maximale Geschwindigkeit ueberschritten wird, Geschwindigkeit begrenzen
				input.setSpeed(MAX_SPEED, true);
		}
		else
		{
			if (s == 0)
				p.setSpeed(1); //Der erste Punkt(0) wird mit Standardgeschwindigkeit 1m/s angefahren.

			else
				p.setSpeed(calculateSpeed(path[s], s, timePrev)); //Die Geschwindigkeit zwischen den weiteren Punkten wird berechnet.
		}

		if (input.getOrientationManual()) // Wenn der Winkel vorgegeben ist diesen setzten
		{
			tuple <double, double, double> angles;
			angles = input.getAngles();
			p.setA(get<0>(angles));
			p.setB(get<1>(angles));
			p.setC(get<2>(angles));
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
	double speed;

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
