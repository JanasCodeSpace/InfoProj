#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/InputParameter.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(InputParameterTests)
    {
    private:
        static constexpr double DifferenceThreshold = 0.01;

    public:
        TEST_METHOD(TestConstructorAndGetters)
        {
            CInputParameter inputParam(10.0, true, false, 1.0, 2.0, 3.0);

            Assert::AreEqual(10.0, inputParam.getSpeed());
            Assert::IsTrue(inputParam.getSpeedManual());
            Assert::IsFalse(inputParam.getOrientationManual());

            auto angles = inputParam.getAngles();
            Assert::AreEqual(1.0, std::get<0>(angles));
            Assert::AreEqual(2.0, std::get<1>(angles));
            Assert::AreEqual(3.0, std::get<2>(angles));
        }
        TEST_METHOD(TestSetSpeedAndGetSpeed)
        {
            CInputParameter inputParam;
            inputParam.setSpeed(15.0, true);

            Assert::AreEqual(15.0, inputParam.getSpeed());
            Assert::IsTrue(inputParam.getSpeedManual());
        }
        TEST_METHOD(TestSetOrientationAndGetOrientation)
        {
            CInputParameter inputParam;
            inputParam.setOrientation(true, 1.0, 2.0, 3.0);

            Assert::IsTrue(inputParam.getOrientationManual());
            auto angles = inputParam.getAngles();
            Assert::AreEqual(1.0, std::get<0>(angles));
            Assert::AreEqual(2.0, std::get<1>(angles));
            Assert::AreEqual(3.0, std::get<2>(angles));
        }
        TEST_METHOD(TestOpenFile)
        {
            CInputParameter inputParam;
            inputParam.openFile("../input/path_01.csv"); // Testdateipfad

            vector<list<CInputPoint3D>>& path = inputParam.getPath();

            Assert::IsTrue(!path.empty(), L"Leerer Pfad");
        }

        TEST_METHOD(TestDetectJump)
        {
            CInputParameter inputParam;
            CEulerMatrix Euler;
            Assert::IsFalse(inputParam.detectJump(CInputPoint3D(1.0, 2.0, 3.0, 0.1, Euler), 0.0, 0.0, 0.0));
            Assert::IsFalse(inputParam.detectJump(CInputPoint3D(1.0, 1.0, 1.0, 0.2, Euler), 0.0, 0.0, 0.0));
            
        }
    };
}