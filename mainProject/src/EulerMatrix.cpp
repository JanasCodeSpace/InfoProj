/**
 * @file EulerMatrix.cpp
 *
 * @brief Source Code der Euler Matrix
 */

#include "../header/EulerMatrix.h"
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

CEulerMatrix CEulerMatrix::getEulerMatrix()
{
    return eulerMatrix;         // EulerMatrix zurück geben
}

void CEulerMatrix::getMatrix(float Matrix[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int m = 0; m < 3; m++)
        {
            Matrix[i][m] = eulerMatrix[i][m];  // eulerMatrix mit �bergabewerten �berschreiben
        }
    }
}

//TODO: Kommentar
CEulerMatrix CEulerMatrix::angels2mat(double A, double B, double C)
{
    float Matrix[3][3];     // DummyMatrix erstellen

    /* Berechnung der Matrix */

    Matrix[0][0] = cos(A) * cos(C) - sin(A) * cos(B) * sin(C);
    Matrix[0][1] = -cos(A) * sin(C) - sin(A) * cos(B) * cos(C);
    Matrix[0][2] = sin(A) * sin(B);

    Matrix[1][0] = sin(A) * cos(C) + cos(A) * cos(B) * sin(C);
    Matrix[1][1] = -sin(A) * sin(C) + cos(A) * cos(B) * cos(C);
    Matrix[1][2] = -cos(A) * sin(B);

    Matrix[2][0] = sin(B) * sin(C);
    Matrix[2][1] = sin(B) * cos(C);
    Matrix[2][2] = cos(B);

    CEulerMatrix buffer(Matrix);        // DummyMatrix in DummyEulerMatrix schreiben
    return buffer;                      // Matrix zurück geben
}

//TODO: Kommentar
tuple<double , double , double> CEulerMatrix::calculateAngels(void)
{
    double a, b, c, sin_a, cos_a, sin_b, abs_cos_b, sin_c, cos_c;

    /*
    a == Winkel Alpha
    b == Winkel Beta
    c == Winkel Gamma

    sin_a == sinus alpha
    cos_a == cosinus alpha
    sin_b == Matrix[2][0] * -1
    abs_cos_b == ??
    sin_c == sinus gamma
    cos_c == cosinus gamma
    */


    /* Berechnung von alpha*/
    a = atan2(eulerMatrix[1][0], eulerMatrix[0][0]);

    /* Berechung von beta */
    sin_a = sin(a);
    cos_a = cos(a);
    sin_b = eulerMatrix[2][0] * -1;
    abs_cos_b = cos(a) * eulerMatrix[0][0] + sin(a) * eulerMatrix[1][0];

    b = atan2 (sin_b, abs_cos_b);

    /* Berechung von gamma */
    sin_c =  sin_a * eulerMatrix[0][2] - cos_a * eulerMatrix[1][2];
    cos_c = -sin_a * eulerMatrix[0][1] + cos_a * eulerMatrix[1][1];

    c = atan2(sin_c, cos_c);

    /* Bogenmass in Gradmass umrechnen */
    a = a * 180 / M_PI;
    b = b * 180 / M_PI;
    c = c * 180 / M_PI;


    return make_tuple(a, b, c);     // Rückgabe der Winkel
}

