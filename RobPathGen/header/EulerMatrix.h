/**
 * @file EulerMatrix.h
 *
 * @brief Header File handling Euler Matrix
 */

#include <tuple>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

#pragma once

/**
 * Diese Klasse speichert die Euler Matrix und hat Funktionen f�r Berechnungen mit eben jener.
 * @brief Handling und Berechnung Euler Matrix
 */
class CEulerMatrix
{
public:
	/**
	* Initialisiert die Input Daten mit Null
	* @brief Default Konstruktor
	* @see CEulerMatrix(float inputMatrix[3][3])
	*/
	CEulerMatrix(void);
	/**
	* Initialisiert die Input Daten mit Null
	* @brief Default Konstruktor
	* @param float inputMatrix[3][3] initialisiert die Klasse mit einer Euler Matrix
	* @see CEulerMatrix(void)
	*/
	CEulerMatrix(float inputMatrix[3][3]);
	/**
	* @brief Dekonstruktor
	*/
	~CEulerMatrix();

	/**
	* @brief Setzt eine Matrix
	* @param float inputMatrix[3][3] zum setzten einer Matrix
	*/
	void setMatrix(float inputMatrix[3][3]);
	/**
	* @brief Auslesen eine Matrix
	* @return: float inputMatrix[3][3] gibt gespeicherte Matrix zur�ck
	*/
	CEulerMatrix getEulerMatrix(void);

	/**
	* @brief Auslesen eine Matrix
	* @param float* inputMatrix[3][3] Pointer zu einer Matrix
	*/
	void getMatrix(float Matrix[][3]);
	/**
	* @brief Berechnet die neue Umdrehungsmatrix
	* @param A double Winkel a
	* @param B double Winkel b
	* @param C double Winkel c
	* @return: float inputMatrix[3][3] gibt die neu berechnete Matrix zur�ck
	*/
	CEulerMatrix angels2mat(double A, double B, double C);

/**
	* @brief Berechnet die Kuka Wunkel A,B,C
	* @return: tuple<double , double , double> gibt die berechneten Winkel A, B, C zurück
	*/
	tuple<double , double , double> calculateAngels(void);

private:
	/**
	* Gespeicherte Euler Matrix
	*/
	float eulerMatrix[3][3];

};

