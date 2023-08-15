#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/Point3D.h"
#include "../mainProject/header/SegmentApproximator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(SegmentApproximatorTests)
    {
    public:
        TEST_METHOD(TestDouglasPeuckerRecursive)
        {
            CSegmentApproximator approximator;
            CEulerMatrix Euler;

            std::list<CInputPoint3D> testSegment;
            testSegment.emplace_back(CInputPoint3D(0.0, 0.0, 0.0, 0.1, Euler));
            testSegment.emplace_back(CInputPoint3D(1.0, 1.0, 1.0, 0.2, Euler));
            testSegment.emplace_back(CInputPoint3D(2.0, 2.0, 2.0, 0.3, Euler));
            
            approximator.douglasPeuckerRecursive(testSegment, testSegment.begin(), --testSegment.end());

            Assert::AreEqual<size_t>(2, testSegment.size());
                        
            Assert::AreEqual<double>(0.0, testSegment.front().getX(), L"X-Koordinate des ersten Punktes stimmt nicht überein");
            Assert::AreEqual<double>(0.0, testSegment.front().getY(), L"Y-Koordinate des ersten Punktes stimmt nicht überein");
            Assert::AreEqual<double>(0.0, testSegment.front().getZ(), L"Z-Koordinate des ersten Punktes stimmt nicht überein");

            Assert::AreEqual<double>(2.0, testSegment.back().getX(), L"X-Koordinate des letzten Punktes stimmt nicht überein");
            Assert::AreEqual<double>(2.0, testSegment.back().getY(), L"Y-Koordinate des letzten Punktes stimmt nicht überein");
            Assert::AreEqual<double>(2.0, testSegment.back().getZ(), L"Z-Koordinate des letzten Punktes stimmt nicht überein");
        }
    };
}