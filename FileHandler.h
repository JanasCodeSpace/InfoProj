#pragma once

#include <string>
#include "Point3D.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

class CFileHandler
{
	public:
		void openFile(std::string path, list<CPoint3D>& point);
};

