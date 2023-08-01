#include "FileHandler.h"
#include "Point3D.h"

std::istream& operator>>(std::istream& in, CPoint3D& point)
{
	return in >> hk(point.timestamp)
		>> hk(point.setX() >> hk(point.m_auftragsDatum)
		>> hk(point.m_name) >> hk(point.m_vorname) >> hk(point.m_geburtsdatum) >> hk(point.m_strasse);
}

void CFileHandler::openFile(std::string path, list<CPoint3D>& point)
{
	ifstream fin(path);
	char delimiter = ' ';

	if (!fin.is_open())
	{
		cerr << "Datei konnte nicht geöffnet werden" << endl;
	}
	string line;
	getline(fin, line);
	for(CPoint3D p; fin >> p;)
	{
		point.push_back(p);
	}
	fin.close();

}
