#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/EulerMatrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EulerMatrix
{
    TEST_CLASS(EulerMatrixTests_1)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            CEulerMatrix matrix;

            float testMatrix[3][3];
            matrix.getMatrix(testMatrix);

            for (int i = 0; i < 3; i++)
            {
                for (int m = 0; m < 3; m++)
                {
                    Assert::AreEqual(testMatrix[i][m], 0.0f);
                }
            }
        }

        TEST_METHOD(ParameterizedConstructor)
        {
            float inputMatrix[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
            };
            CEulerMatrix matrix(inputMatrix);

            float testMatrix[3][3];
            matrix.getMatrix(testMatrix);

            for (int i = 0; i < 3; i++)
            {
                for (int m = 0; m < 3; m++)
                {
                    Assert::AreEqual(testMatrix[i][m], inputMatrix[i][m]);
                }
            }
        }

        TEST_METHOD(SetMatrix)
        {
            CEulerMatrix eulerMatrix;
            float inputMatrix[3][3] = {
        {7.0f, 8.0f, 9.0f},
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
            };
            float testMatrix[3][3];

            eulerMatrix.setMatrix(inputMatrix);
            eulerMatrix.getMatrix(testMatrix);

            for (int i = 0; i < 3; i++)
            {
                for (int m = 0; m < 3; m++)
                {
                    Assert::AreEqual(testMatrix[i][m], inputMatrix[i][m]);
                }
            }
        }
        /* Not used
        TEST_METHOD(Angels2Mat)
        {
            CEulerMatrix eulerMatrix;

            float expectedMatrix[3][3] = {
                {0.772361, -0.607127, 0.186697},
                {0.630455, 0.696948, -0.341747},
                {0.077365, 0.381656, 0.921061}
            };

            eulerMatrix = eulerMatrix.angels2mat(0.5, 0.4, 0.2);

            float actualMatrix[3][3];
            eulerMatrix.getMatrix(actualMatrix);
            double tolerance = 0.000001;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert::AreEqual<double>(expectedMatrix[i][j], actualMatrix[i][j]);
                }
            }
        }*/
        TEST_METHOD(CalculateAngels)
        {
            float inputMatrix[3][3] = {
                {0.866, -0.5, 0.0},
                {0.5, 0.866, 0.0},
                {0.0, 0.0, 1.0}
            };
            CEulerMatrix eulerMatrix(inputMatrix);

            double expectedA = 0.523611;
            double expectedB = 0.0;
            double expectedC = 0.0;

            std::tuple<double, double, double> calculatedAngles = eulerMatrix.calculateAngels();

            double epsilon = 0.000001; // Toleranz für Gleitkommavergleich
            
            Assert::IsTrue(abs(expectedA - std::get<0>(calculatedAngles)) < epsilon,
                L"A stimmt nicht überein");
            Assert::IsTrue(abs(expectedB - std::get<1>(calculatedAngles)) < epsilon,
                L"B stimmt nicht überein");
            Assert::IsTrue(abs(expectedC - std::get<2>(calculatedAngles)) < epsilon,
                L"C stimmt nicht überein");
        }

        TEST_METHOD(GetEulerMatrix)
        {
            CEulerMatrix eulerMatrix1;
            CEulerMatrix eulerMatrix2;

            float inputMatrix[3][3] = {
                {1.0, 2.0, 4.0},
                {3.0, 9.0, 27.0},
                {12.0, 144.0, 0.26}
            };
            float testMatrix[3][3];

            eulerMatrix1.setMatrix(inputMatrix);
            eulerMatrix2 = eulerMatrix1.getEulerMatrix();

            eulerMatrix2.getMatrix(testMatrix);

            for (int i = 0; i < 3; i++)
            {
                for (int m = 0; m < 3; m++)
                {
                    Assert::AreEqual(testMatrix[i][m], inputMatrix[i][m]);
                }
            }

        }
    };
}