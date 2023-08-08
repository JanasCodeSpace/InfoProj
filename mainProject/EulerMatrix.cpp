#include "EulerMatrix.h"
#include <math.h>

CEulerMatrix::CEulerMatrix(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int m = 0; m < 3; m++)
        {
            eulerMatrix[i][m] = 0;                  // eulerMatrix mit 0 initialisieren
        }
    }
}

CEulerMatrix::CEulerMatrix(float inputMatrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int m = 0; m < 3; m++)
        {
            eulerMatrix[i][m] = inputMatrix[i][m];  // eulerMatrix mit Startwerten initialisieren
        }
    }
}

CEulerMatrix::~CEulerMatrix()
{
}


void CEulerMatrix::setMatrix(float inputMatrix[3][3])
{
    for(int i = 0; i < 3; i++)
    { 
        for (int m = 0; m < 3; m++)
        {
            eulerMatrix[i][m] = inputMatrix[i][m];  // eulerMatrix mit Übergabewerten überschreiben
        }
    }
}

CEulerMatrix CEulerMatrix::getMatrix()
{
    return eulerMatrix;
}

CEulerMatrix CEulerMatrix::calculatAngel(double A, double B, double C)
{
    float Matrix[3][3];

    Matrix[0][0] = cos(A) * cos(C) - sin(A) * cos(B) * sin(C);
    Matrix[0][1] = -cos(A) * sin(C) - sin(A) * cos(B) * cos(C);
    Matrix[0][2] = sin(A) * sin(B);

    Matrix[1][0] = sin(A) * cos(C) + cos(A) * cos(B) * sin(C);
    Matrix[1][1] = -sin(A) * sin(C) + cos(A) * cos(B) * cos(C);
    Matrix[1][2] = -cos(A) * sin(B);

    Matrix[2][0] = sin(B) * sin(C);
    Matrix[2][1] = sin(B) * cos(C);
    Matrix[2][2] = cos(B);

    CEulerMatrix buffer(Matrix);
    return buffer;
}

