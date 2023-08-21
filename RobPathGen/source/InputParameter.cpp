/**
 * @file InputParameter.cpp
 * 
 * @brief Source File Daten Einlesen
 */

#include "../header/InputParameter.h"
#include "../header/Point3D.h"
#include "../header/EulerMatrix.h"

/* CInputParamameter mir Uebergabewerten initialisieren */ 
CInputParameter::CInputParameter(double initSpeed, bool initSpeedManual, bool initOrientationManual, double initA, double initB, double initC)
{
	speed = initSpeed;
	speedManual = initSpeedManual;
	orientationManual = initOrientationManual;
	A = initA;
	B = initB;
	C = initC;

}

/* CInputParameter mit 0 initialisieren */
CInputParameter::CInputParameter(void)
{
	speed = 0.1;
	A = 0;
	B = 75;
	C = 0;
	speedManual = false,
	orientationManual = false;

}

CInputParameter::~CInputParameter(void)
{

}

/* Einstellung fuer Orientierung und Winkel setzten */
void CInputParameter::setOrientation(bool initOrientationManual, double initA, double initB, double initC)
{
	orientationManual = initOrientationManual;
	A = initA;
	B = initB;
	C = initC;
}

void CInputParameter::setOffset(double X, double Y, double Z, bool initOffsetManual)
{
	offsetManual = initOffsetManual;
	offsetX = X;
	offsetY = Y;
	offsetZ = Z;
}

void CInputParameter::setLogging(bool initLoggingManual)
{
	loggingManual = initLoggingManual;
}

/* Einstellung fuer Geschwindigkeit und Geschwindigkeit setzen */
void CInputParameter::setSpeed(double initSpeed, bool initSpeedManual)
{
	speed = initSpeed;
	speedManual = initSpeedManual;
}

vector<list<CInputPoint3D>>& CInputParameter::getPath()
{
	return initialPath;		// Path zurueck geben
}

double CInputParameter::getSpeed(void)
{
	return speed;			// Geschwindigkeit zurueck geben
}

bool CInputParameter::getSpeedManual(void)
{
	return speedManual;				// Vorgewaehlte Einstellung fuer Geschwindigkeit zurueck geben
}

bool CInputParameter::getOrientationManual(void)
{
	return orientationManual;		// Vorgewaehlte Einstellung fuer Orientierung zurueck geben
}

bool CInputParameter::getOffsetManual(void)
{
	return offsetManual;		// Vorgewaehlte Einstellung fuer den Offset zurueck
}

bool CInputParameter::getLoggingManual(void)
{
	return loggingManual;		// Vorgewaehlte Einstellung fuer das Logging zurueck
}

tuple <double, double, double> CInputParameter::getAngles(void)
{
	return make_tuple(A, B, C);		// Winkel zurueck geben
}

tuple <double, double, double> CInputParameter::getOffset(void)
{
	return make_tuple(offsetX, offsetY, offsetZ);		// Offset zurueck geben
}


/* Eingabedatei oeffnen */ 
void CInputParameter::openFile(string path)
{
	ifstream fin(path);
	CInputPoint3D tmpPoint;		// Zwischenspeicher zum konvertieren von tmpEuler in Point3D
	CEulerMatrix tmpEuler;		// Zwischenspeicher zum konverteiren von DummyMatrix in EulerMatrix
	double x, y, z;				// Punktkoordinaten
	double x_prev = 0, y_prev = 0, z_prev = 0;		// Zwischenspeicher fuer Punktkoordinaten
	double timestamp;			// Zeitstempel
	int segmentCount = -1;		// Segmentzaehler
	float dummyMatrix[3][3];	// DummyMatrix zum speichern


	if (!fin.is_open())
	{
		cerr << "Datei konnte nicht geoeffnet werden" << endl;		// Fehler Datei konnte nicht geoeffnet werden.
	}
	string line;

	while(getline(fin, line))
	{
		std::istringstream sStream (line);
		sStream >> timestamp >> x >> y >> z >> dummyMatrix[0][0] >> dummyMatrix[0][1] >> dummyMatrix[0][2]										// Zeile in die einzelnen Parameter zerlegen 
			>> dummyMatrix[1][0] >> dummyMatrix[1][1] >> dummyMatrix[1][2] >> dummyMatrix[2][0] >> dummyMatrix[2][1] >> dummyMatrix[2][2];		// und in DummyMatrix bzw. Variablen abspeichern

		tmpEuler.setMatrix(dummyMatrix);									// DummyMatrix[3][3] in EulerMatrix speichern							
		tmpPoint.setPoint(timestamp, x, y, z, tmpEuler.getEulerMatrix());	// Variablen und EulerWinkel in CPoint3D speichern

		if (detectJump(tmpPoint, x_prev, y_prev, z_prev)) // if there is a jump in the data, start a new segment 
		{
			segmentCount++;									// neues Segement anlegen
			initialPath.push_back(list<CInputPoint3D>());	// Punkt in Segent speichern
		}

		initialPath[segmentCount].push_back(tmpPoint);		// Punkt in bestehendes Segment abspeichern

		x_prev = x;		// X-Wert zwischenspeichern
		y_prev = y;		// Y-Wert zwischenspeichern
		z_prev = z;		// Z-Wert zwischenspeichern
	}
	fin.close();		// Datei schliessen
}

bool CInputParameter::detectJump(CInputPoint3D p, double x_prev, double  y_prev, double z_prev)
{
	if(abs(p.getX() - x_prev) > difference)				// Abstand zwischen Punkten groesser max Differenz??
		return true;
	else if(abs(p.getY() - y_prev) > difference)		// Abstand zwischen Punkten groesser max Differenz??
		return true;
	else if(abs(p.getZ() - z_prev) > difference)			// Abstand zwischen Punkten groesser max Differenz??
		return true;
	else
		return false;
}
