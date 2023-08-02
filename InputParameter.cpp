#include "InputParameter.h"
#include "Point3D.h"

CInputParameter::CInputParameter(void)
{

}

CInputParameter::~CInputParameter(void)
{

}

vector<CPoint3D>& CInputParameter::getPath()
{
	return initialPath;
}

void CInputParameter::openFile(std::string path, vector<CPoint3D>& point)
{
	ifstream fin(path);
	char delimiter = ' ';

	if (!fin.is_open())
	{
		cerr << "Datei konnte nicht geöffnet werden" << endl;
	}
	string line;

	while(getline(fin, line))
	{
		
		cout << line << endl;

	}
	fin.close();

}

