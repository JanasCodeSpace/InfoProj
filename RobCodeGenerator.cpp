#include "RobCodeGenerator.h"
#include "Point3D.h"


CRobCodeGenerator::CRobCodeGenerator(void)
{
}


CRobCodeGenerator::~CRobCodeGenerator(void)
{
}

void CRobCodeGenerator::generateRobCode(vector<CPoint3D>& points, string filename)
{
	FILE* fid = fopen(filename.c_str(), "w");

	if (fid == NULL)
	{ 
		string msg = "Open file: ";
		msg += filename;
		msg += " failed!";

		throw exception(msg.c_str());
	}

	CPoint3D currentPoint;

	filename.erase(filename.end()-4,filename.end());
	fprintf(fid, "DEF %s \n", filename.c_str());

	fputs("PTP $POS_ACT\n", fid);

	for (size_t s = 0; s < points.size(); s++)
	{
		currentPoint.set(points[s].getX() * scaleX + offsetX,points[s].getY() * scaleY + offsetY,points[s].getZ() * scaleZ + offsetZ);
		
		//currentPoint = Transformation * currentPoint; //Here wee need a transformationmatrix containing public parameters scaleX,offsetX...

		fprintf(fid, "LIN {X %f, Y %f, Z %f, A %f, B %f, C %f}\n", currentPoint.getX(), currentPoint.getY(), currentPoint.getZ(), 0.0, 180.0, 0.0); //A = 0, B = 180, C = 0 (Works for "usual" pen tool perpendicular to "usual" table)
	}

	fputs("END", fid);
}
