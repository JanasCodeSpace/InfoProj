#pragma once

#include"EulerMatrix.h"

class CInputParameter
{
	float speed;
	bool speedManual;
	bool orientationManual;
	float lengthA;
	float lengthB;
	float lengthC;
	CEulerMatrix inputMatrix;
};

