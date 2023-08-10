#include "header/Logging.h"

CLogging::CLogging(void)
{
	step = 0;
}

CLogging::CLogging(int Step)
{
	step = Step;
}

CLogging::~CLogging(void)
{

}

void CLogging::logData(string Path, vector<list<CInputPoint3D>>& sourcePath)
{

}

void CLogging::logData(string Path, vector<CInputPoint3D>& sourcePath)
{

}
