#pragma once
class CEulerMatrix
{
public:
	CEulerMatrix(void);
	CEulerMatrix(float inputMatrix[3][3]);
	~CEulerMatrix();

	float eulerMatrix[3][3];

	void setMatrix(float inputMatrix[3][3]);
	CEulerMatrix getMatrix();
};

