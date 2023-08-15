#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/EulerMatrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(EulerMatrixTests)
    {
    public:
        TEST_METHOD(TestDefaultConstructor)
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

        TEST_METHOD(TestParameterizedConstructor)
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
        /*
        TEST_METHOD(TestSetMatrix)
        {
            CEulerMatrix eulerMatrix;
            float inputMatrix[3][3] = {
        {7.0f, 8.0f, 9.0f},
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
            };
            eulerMatrix.setMatrix(inputMatrix);
                        
            Assert::AreEqual(inputMatrix[0][0], eulerMatrix.getEulerMatrix()[0][0]);
            Assert::AreEqual(inputMatrix[1][1], eulerMatrix.getEulerMatrix()[1][1]);
            Assert::AreEqual(inputMatrix[2][2], eulerMatrix.getEulerMatrix()[2][2]);
            // ...
        }

        TEST_METHOD(TestAngels2Mat)
        {
            CEulerMatrix eulerMatrix = CEulerMatrix::angels2mat(0.5, 0.4, 0.2);
            float expectedMatrix[3][3] = {
                {0.888075, 0.216529, 0.408082},
                {0.457920, 0.744418, - 0.484291},
                {-0.0498453, 0.632051, 0.77389}
            };
            float actualMatrix[3][3];
            eulerMatrix.getMatrix(actualMatrix);

            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert::AreEqual(expectedMatrix[i][j], actualMatrix[i][j]);
                }
            }
        }
        */
        TEST_METHOD(TestCalculateAngels)
        {
            float inputMatrix[3][3] = {
                {0.866, -0.5, 0.0},
                {0.5, 0.866, 0.0},
                {0.0, 0.0, 1.0}
            };
            CEulerMatrix eulerMatrix(inputMatrix);

            double expectedA = 1.047; // 60 Grad in Bogenmaß
            double expectedB = 0.785; // 45 Grad in Bogenmaß
            double expectedC = 0.523; // 30 Grad in Bogenmaß
                        
            std::tuple<double, double, double> calculatedAngles = eulerMatrix.calculateAngels();
                        
            double epsilon = 0.001; // Toleranz für Gleitkommavergleich

            Assert::IsTrue(abs(expectedA - std::get<0>(calculatedAngles)) < epsilon,
                L"A stimmt nicht überein");
            Assert::IsTrue(abs(expectedB - std::get<1>(calculatedAngles)) < epsilon,
                L"B stimmt nicht überein");
            Assert::IsTrue(abs(expectedC - std::get<2>(calculatedAngles)) < epsilon,
                L"C stimmt nicht überein");
        }
    };
}