/**
 * @file Logging.cpp
 *
 * @brief Source File Logging
 */

#include "../header/Logging.h"

/* Step mit 0 initialisiren */
CLogging::CLogging(void)
{
	step = 0;
}

/* Path mit Parameter initialisieren*/
CLogging::CLogging(string Path, bool Detailed)
{
	path = Path;
	detailed = Detailed;
}

CLogging::~CLogging(void)
{

}

bool CLogging::getDetailed(void)
{
	return detailed;
}

void CLogging::setStep(int Step)
{
	step = Step;	// Step setzen
}

void CLogging::logData(vector<list<CInputPoint3D>>& sourcePath)
{
	string filepath;			// file Pfad
	float dummyMatrix[3][3];	// dummyMatrix zum Zwischenspeichern
	CEulerMatrix tmpEuler;		// CEulerMatrix zum Zwischenspeichern

	filepath = path + "/" + "0" + std::to_string(step) + "_log.csv";

	FILE* fid = fopen(filepath.c_str(), "w");		// file oeffnen

	if (fid == NULL)
	{
		cerr << "ERROR - Can NOT write to output file!\n";		// Fehler beim file oeffnen
		return;
	}

	for (size_t s = 0; s < sourcePath.size(); s++) //for all segments
	{
		list<CInputPoint3D>::iterator itr = sourcePath[s].begin();

		/* Ausgeben der Punkte mit dummyMatrix */
		for (; itr != sourcePath[s].end(); itr++) //for all points in the segment
		{
			tmpEuler = itr->getEulerMatrix();
			tmpEuler.getMatrix(dummyMatrix);

			fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)itr->getTime(), (double)itr->getX(), (double)itr->getY(), (double)itr->getZ(),
				dummyMatrix[0][0], dummyMatrix[0][1], dummyMatrix[0][2],
				dummyMatrix[1][0], dummyMatrix[1][1], dummyMatrix[1][2],
				dummyMatrix[2][0], dummyMatrix[2][1], dummyMatrix[2][2]);
		}

		itr--;
	}
	fclose(fid);
}

void CLogging::logData(vector<CInputPoint3D>& sourcePath)
{
	string filepath;			// file Pfad
	float dummyMatrix[3][3];	// dummyMatrix zum Zwischenspeichern
	CEulerMatrix tmpEuler;		// CEulerMatrix zum Zwischenspeichern

	filepath = path + "/" + "0" + std::to_string(step) + "_log.csv";

	FILE* fid = fopen(filepath.c_str(), "w");	// file oeffnen

	if (fid == NULL)
	{
		cerr << "ERROR - Can NOT write to output file!\n";	// Fehler beim file oeffnen
		return;
	}

	/* Ausgeben der Punkte mit dummyMatrix */
	for (size_t s = 0; s < sourcePath.size(); s++) //for all points in the vector
	{
		tmpEuler = sourcePath[s].getEulerMatrix();
		tmpEuler.getMatrix(dummyMatrix);

		fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)sourcePath[s].getTime(), 
			(double)sourcePath[s].getX(), (double)sourcePath[s].getY(), (double)sourcePath[s].getZ(),
			dummyMatrix[0][0], dummyMatrix[0][1], dummyMatrix[0][2],
			dummyMatrix[1][0], dummyMatrix[1][1], dummyMatrix[1][2],
			dummyMatrix[2][0], dummyMatrix[2][1], dummyMatrix[2][2]);
	}
	fclose(fid);
}

void CLogging::logData(vector<COutputPoint3D>& sourcePath)
{
	string filepath;			// file Pfad
	float dummyMatrix[3][3];	// dummyMatrix zum Zwischenspeichern
	CEulerMatrix tmpEuler;		// CEulerMatrix zum Zwischenspeichern

	filepath = path + "/" + "0" + std::to_string(step) + "_log.csv";

	FILE* fid = fopen(filepath.c_str(), "w");	// file oeffnen

	if (fid == NULL)
	{
		cerr << "ERROR - Can NOT write to output file!\n";	// Fehler beim file oeffnen
		return;
	}

	/* Ausgeben der Punkte mit dummyMatrix */
	for (size_t s = 0; s < sourcePath.size(); s++) //for all points in the vector
	{
		tmpEuler.getMatrix(dummyMatrix);

		fprintf(fid, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", (double)sourcePath[s].getSpeed(),
			(double)sourcePath[s].getX(), (double)sourcePath[s].getY(), (double)sourcePath[s].getZ(),
			(double)sourcePath[s].getA(), (double)sourcePath[s].getB(), (double)sourcePath[s].getC());
	}
	fclose(fid);
}
