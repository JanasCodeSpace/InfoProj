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

            int listIndex = 0;
            std::list<CInputPoint3D>& targetList = path[listIndex];
            std::advance(targetList.begin(), path.size());




        }
        TEST_METHOD(DetectJump)
        {
            CInputParameter inputParam;
            CEulerMatrix Euler;
            Assert::IsFalse(inputParam.detectJump(CInputPoint3D(1.0, 2.0, 3.0, 0.1, Euler), 0.0, 0.0, 0.0));
            Assert::IsFalse(inputParam.detectJump(CInputPoint3D(1.0, 1.0, 1.0, 0.2, Euler), 0.0, 0.0, 0.0));
            
        }
    };
}