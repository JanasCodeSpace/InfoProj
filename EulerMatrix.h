using namespace std;

#pragma once
class CEulerMatrix
{
public:
	CEulerMatrix(void);
	CEulerMatrix(float inputMatrix[3][3]);
	~CEulerMatrix();

	void setMatrix(float inputMatrix[3][3]);
	CEulerMatrix getMatrix();

private:
	float eulerMatrix[3][3];
};

