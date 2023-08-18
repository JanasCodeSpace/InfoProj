#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/InputParameter.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InputParameter
{
    TEST_CLASS(InputParameterTests_1)
    {
    public:
        TEST_METHOD(DefaultConstructorAndSettersAndGetters)
        {
            CInputParameter inputParam;
            bool testOrientationManual = false;
            double testA = 0.0;
            double testB = 2.0;
            double testC = 5.0;
            bool testSpeedManual = true;
            double testSpeed = 10.0;

            inputParam.setOrientation(testOrientationManual, testA, testB, testC);
            inputParam.setSpeed(testSpeed, testSpeedManual);

            Assert::AreEqual(testOrientationManual, inputParam.getOrientationManual());
            Assert::AreEqual(testA, std::get<0>(inputParam.getAngles()));
            Assert::AreEqual(testB, std::get<1>(inputParam.getAngles()));
            Assert::AreEqual(testC, std::get<2>(inputParam.getAngles()));
            Assert::AreEqual(testSpeedManual, inputParam.getSpeedManual());
            Assert::AreEqual(testSpeed, inputParam.getSpeed());

        }
        TEST_METHOD(ParameterizedConstructorAndGetters)
        {
            bool testOrientationManual = true;
            double testA = 5.0;
            double testB = 102.0;
            double testC = 34.0;
            bool testSpeedManual = false;
            double testSpeed = 222.2;

            CInputParameter inputParam(testSpeed, testSpeedManual, testOrientationManual, testA, testB, testC);

            Assert::AreEqual(testSpeed, inputParam.getSpeed());
            Assert::AreEqual(testSpeedManual, inputParam.getSpeedManual());
            Assert::AreEqual(testOrientationManual, inputParam.getOrientationManual());
                        
            Assert::AreEqual(testA, std::get<0>(inputParam.getAngles()));
            Assert::AreEqual(testB, std::get<1>(inputParam.getAngles()));
            Assert::AreEqual(testC, std::get<2>(inputParam.getAngles()));
        }
        TEST_METHOD(SetSpeedAndGetSpeed)
        {
            CInputParameter inputParam;
            inputParam.setSpeed(15.0, true);

            Assert::AreEqual(15.0, inputParam.getSpeed());
            Assert::IsTrue(inputParam.getSpeedManual());
        }
        TEST_METHOD(SetOrientationAndGetOrientation)
        {
            CInputParameter inputParam;
            inputParam.setOrientation(true, 1.0, 2.0, 3.0);

            Assert::IsTrue(inputParam.getOrientationManual());
            Assert::AreEqual(1.0, std::get<0>(inputParam.getAngles()));
            Assert::AreEqual(2.0, std::get<1>(inputParam.getAngles()));
            Assert::AreEqual(3.0, std::get<2>(inputParam.getAngles()));
        }
        TEST_METHOD(OpenFile)
        {
            CInputParameter inputParam;
            string testPath = "../input/path_01.csv";

            inputParam.openFile(testPath);

            vector<list<CInputPoint3D>>& path = inputParam.getPath();

            Assert::IsTrue(!path.empty(), L"Leerer Pfad");

            // Überprüfung der ersten Eingabedatenzeile
            float dummyMatrix[3][3] = {
                                            {-0.130535, -0.984082, 0.120599},
                                            {-0.977709, 0.147948, 0.148988},
                                            {-0.164459, -0.098463, -0.981457}
            };
            float testMatrix[3][3];
            CInputPoint3D inputPoint3D;
            double timestamp = 13261.420898;
            double x = 1021.710788;
            double y = -547.198540;
            double z = 632.801115; 
            CEulerMatrix eulerMatrix(dummyMatrix);
            int listIndex = 0;
            int elementIndex = 0;

            inputPoint3D.setPoint(timestamp, x, y, z, eulerMatrix);
            list<CInputPoint3D>& targetList = path[listIndex];            
            auto elementIter = targetList.begin();
            advance(elementIter, elementIndex);
            CInputPoint3D testInputPoint3D = *elementIter;

            Assert::AreEqual(inputPoint3D.getTime(), testInputPoint3D.getTime());
            Assert::AreEqual(inputPoint3D.getX(), testInputPoint3D.getX());
            Assert::AreEqual(inputPoint3D.getY(), testInputPoint3D.getY());
            Assert::AreEqual(inputPoint3D.getZ(), testInputPoint3D.getZ());
            eulerMatrix.getMatrix(testMatrix);
            for (int i = 0; i < 3; i++)
            {
                for (int m = 0; m < 3; m++)
                {
                    Assert::AreEqual(testMatrix[i][m], dummyMatrix[i][m]);
                }
            }
        }
        TEST_METHOD(DetectJump)
        {
            CInputParameter inputParam;
            CEulerMatrix Euler;
            CInputPoint3D p1(1.0, 2.0, 3.0, 0.1, Euler);
            CInputPoint3D p2(2.0, 1.0, 1.0, 0.2, Euler);
            CInputPoint3D p3(3.0, 200.0, 1.0, 0.2, Euler);
            CInputPoint3D p4(4.0, 30.0, 1.0, 340.2, Euler);

            Assert::IsFalse(inputParam.detectJump(p1, 0.0, 0.0, 0.0));
            Assert::IsFalse(inputParam.detectJump(p2, 0.0, 0.0, 0.0));
            Assert::IsTrue(inputParam.detectJump(p3, 0.0, 0.0, 0.0));
            Assert::IsTrue(inputParam.detectJump(p4, 0.0, 0.0, 0.0));            
        }
    };
}