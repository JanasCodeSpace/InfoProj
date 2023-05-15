

#pragma once
class CPoint3D
{
public:
	CPoint3D(void);
	CPoint3D(double x, double y, double z);
	~CPoint3D(void);

	double getX();
	double getY();
	double getZ();

	void setX(double X);
	void setY(double Y);
	void setZ(double Z);

	void set(double X, double Y, double Z);

private:
	double x, y, z;
};

