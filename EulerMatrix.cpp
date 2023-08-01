#include "EulerMatrix.h"


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

