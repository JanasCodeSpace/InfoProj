#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathGen/header/Point3D.h"
#include "../RobPathGen/header/Line3D.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Point3D
{
    TEST_CLASS(Point3DTests_1)
    {
    public:        
        TEST_METHOD(SetterAndGetter)
        {
            double x = 12.0;
            double y = 144.12;
            double z = 1728.14412;
            double expectedX_testPoint1 = 0;
            double expectedY_testPoint1 = 0;
            double expectedZ_testPoint1 = 0;
            double expectedX_testPoint2 = x;
            double expectedY_testPoint2 = y;
            double expectedZ_testPoint2 = z;
            double expectedX_testPoint3 = x;
            double expectedY_testPoint3 = y;
            double expectedZ_testPoint3 = z;
            double expectedX_testPoint4 = y;
            double expectedY_testPoint4 = z;
            double expectedZ_testPoint4 = x;
            CPoint3D testPoint1;
            CPoint3D testPoint2;
            CPoint3D testPoint3(x, y, z);
            CPoint3D testPoint4(x, y, z);

            testPoint2.setX(x);
            testPoint2.setY(y);
            testPoint2.setZ(z);

            testPoint4.set(y, z, x);

            Assert::AreEqual(expectedX_testPoint1, testPoint1.getX());
            Assert::AreEqual(expectedY_testPoint1, testPoint1.getY());
            Assert::AreEqual(expectedZ_testPoint1, testPoint1.getZ());
            Assert::AreEqual(expectedX_testPoint2, testPoint2.getX());
            Assert::AreEqual(expectedY_testPoint2, testPoint2.getY());
            Assert::AreEqual(expectedZ_testPoint2, testPoint2.getZ());
            Assert::AreEqual(expectedX_testPoint3, testPoint3.getX());
            Assert::AreEqual(expectedY_testPoint3, testPoint3.getY());
            Assert::AreEqual(expectedZ_testPoint3, testPoint3.getZ());
            Assert::AreEqual(expectedX_testPoint4, testPoint4.getX());
            Assert::AreEqual(expectedY_testPoint4, testPoint4.getY());
            Assert::AreEqual(expectedZ_testPoint4, testPoint4.getZ());
        }
        TEST_METHOD(DistanceToPoint)
        {
            CPoint3D point1(-1.0, 2.0, 3.0);
            CPoint3D point2(4.0, -5.0, 6.0);
            double expectedDistance = 9.110434;

            double actualDistance1 = point1.distanceTo(point2);
            double actualDistance2 = point2.distanceTo(point1);
            Assert::AreEqual(expectedDistance, actualDistance1, 1e-6);
            Assert::AreEqual(actualDistance1, actualDistance2, 1e-6);
        }
        TEST_METHOD(DistanceToLine)
        {
            CPoint3D point(-1.0, 2.0, 3.0);
            CPoint3D linePoint1(4.0, 5.0, -6.0);
            CPoint3D linePoint2(7.0, -8.0, 9.0);
            CLine3D line(linePoint1, linePoint2);

            double expectedDistance = 7.229660;

            double actualDistance = point.distanceTo(line);

            Assert::AreEqual(expectedDistance, actualDistance, 1e-6);
        }      
        
    };
    TEST_CLASS(InputPoint3DTests_1)
    {
    public:
        TEST_METHOD(SetterAndGetter)
        {
            double x = 12.0;
            double y = 144.12;
            double z = 1728.14412;
            double timeStamp = 10.0;
            float inputMatrix[3][3] = {
                                            {1.0f, 2.0f, 3.0f},
                                            {4.0f, 5.0f, 6.0f},
                                            {7.0f, 8.0f, 9.0f}
            };
            float outputMatrix[3][3];
            CEulerMatrix inputEulerMatrix, outputEulerMatrix;
            CInputPoint3D testInputPoint1;
            CInputPoint3D testInputPoint2(x, y, z, timeStamp, inputEulerMatrix);
            CInputPoint3D testInputPoint3(x, y, z, timeStamp, inputEulerMatrix);

            inputEulerMatrix.setMatrix(inputMatrix);
            testInputPoint1.setEulerMatrix(inputEulerMatrix);
            testInputPoint1.setTime(timeStamp);
            outputEulerMatrix = testInputPoint1.getEulerMatrix();
            outputEulerMatrix.getMatrix(outputMatrix);

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert::AreEqual(inputMatrix[i][j], outputMatrix[i][j]);
                }
            }
            Assert::AreEqual(timeStamp, testInputPoint1.getTime());

            outputEulerMatrix = testInputPoint2.getEulerMatrix();
            outputEulerMatrix.getMatrix(outputMatrix);
            Assert::AreEqual(x, testInputPoint2.getX());
            Assert::AreEqual(y, testInputPoint2.getY());
            Assert::AreEqual(z, testInputPoint2.getZ());
            Assert::AreEqual(timeStamp, testInputPoint2.getTime());
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert::AreEqual(0.0f, outputMatrix[i][j]);
                }
            }
            
            double add = 2;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    inputMatrix[i][j] = add * inputMatrix[i][j];
                }
            }
            inputEulerMatrix.setMatrix(inputMatrix);
            testInputPoint3.setPoint(timeStamp + add, x + add, y + add, z + add, inputEulerMatrix);
            outputEulerMatrix = testInputPoint3.getEulerMatrix();
            outputEulerMatrix.getMatrix(outputMatrix);

            Assert::AreEqual(timeStamp + add, testInputPoint3.getTime());
            Assert::AreEqual(x + add, testInputPoint3.getX());
            Assert::AreEqual(y + add, testInputPoint3.getY());
            Assert::AreEqual(z + add, testInputPoint3.getZ());
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert::AreEqual(inputMatrix[i][j], outputMatrix[i][j]);
                }
            }
        }
    };
    TEST_CLASS(OutputPoint3DTest_1)
    {
    public:
        TEST_METHOD(SetterAndGetter)
        {
            double speed = 0.5; // muss zwischen 0.1 und 2.0 sein, wegen Firebrand
            double x = 13.9;
            double y = 12312.123;
            double z = 12323.3;
            double a = 1434.5243;
            double b = 3423.41;
            double c = 52.023412;
            COutputPoint3D testOutputPoint1;
            COutputPoint3D testOutputPoint2(speed, x, y, z, a, b, c);

            testOutputPoint1.set(x, y, z);
            testOutputPoint1.setA(a);
            testOutputPoint1.setB(b);
            testOutputPoint1.setC(c);
            testOutputPoint1.setSpeed(speed);

            Assert::AreEqual(testOutputPoint1.getA(), testOutputPoint2.getA());
            Assert::AreEqual(testOutputPoint1.getB(), testOutputPoint2.getB());
            Assert::AreEqual(testOutputPoint1.getC(), testOutputPoint2.getC());
            Assert::AreEqual(testOutputPoint1.getSpeed(), testOutputPoint2.getSpeed());
            Assert::AreEqual(testOutputPoint1.getX(), testOutputPoint2.getX());
            Assert::AreEqual(testOutputPoint1.getY(), testOutputPoint2.getY());
            Assert::AreEqual(testOutputPoint1.getZ(), testOutputPoint2.getZ());
        }
    };
}
