#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/Point3D.h"
#include "../mainProject/header/SegmentApproximator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SegmentApproximator
{
    TEST_CLASS(SegmentApproximatorTests)
    {
    public:
        TEST_METHOD(SetterAndGetter)
        {
            CSegmentApproximator segmentApproximator;
            double maxDistance = 12.002;
            segmentApproximator.setmaxDistance(maxDistance);

            Assert::AreEqual(maxDistance, segmentApproximator. getmaxDistance());
        }
        TEST_METHOD(ApproxIncludingDouglasPeuckerRecursive)
        {
            CSegmentApproximator approximator;
            CEulerMatrix Euler;
            CLogging log("../output"); // Pfad zum Testen
            std::vector<list<CInputPoint3D>> outputVector;
            
            log.setStep(2);

            vector<list<CInputPoint3D>> testVector;

            testVector.push_back(list<CInputPoint3D>());

            testVector[0].push_back(CInputPoint3D(0.0, 0.0, 0.0, 0.1, Euler));
            testVector[0].push_back(CInputPoint3D(1.0, 2.0, 1.0, 0.2, Euler));
            testVector[0].push_back(CInputPoint3D(2.0, 2.0, 2.0, 0.3, Euler));

            approximator.approx(testVector, log);

            outputVector = approximator.getSegmentsApproxVector();

            Assert::AreEqual<size_t>(2, outputVector[0].size());
                        
            Assert::AreEqual(0.0, outputVector[0].front().getX(), L"X-Koordinate des ersten Punktes stimmt nicht überein");
            Assert::AreEqual(0.0, outputVector[0].front().getY(), L"Y-Koordinate des ersten Punktes stimmt nicht überein");
            Assert::AreEqual(0.0, outputVector[0].front().getZ(), L"Z-Koordinate des ersten Punktes stimmt nicht überein");

            Assert::AreEqual(2.0, outputVector[0].back().getX(), L"X-Koordinate des letzten Punktes stimmt nicht überein");
            Assert::AreEqual(2.0, outputVector[0].back().getY(), L"Y-Koordinate des letzten Punktes stimmt nicht überein");
            Assert::AreEqual(2.0, outputVector[0].back().getZ(), L"Z-Koordinate des letzten Punktes stimmt nicht überein");
        }
    };
}