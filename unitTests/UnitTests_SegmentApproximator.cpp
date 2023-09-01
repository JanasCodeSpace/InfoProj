#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathGen/header/Point3D.h"
#include "../RobPathGen/header/SegmentApproximator.h"

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

			Assert::AreEqual(maxDistance, segmentApproximator.getmaxDistance());
		}
		TEST_METHOD(ApproxIncludingDouglasPeuckerRecursive)
		{
			CSegmentApproximator approximator;
			CEulerMatrix Euler;
			CLogging log("../output", true); // Pfad zum Testen
			vector<list<CInputPoint3D>> outputVector;
			double maxDistance = 1.0;

			log.setStep(2);
			approximator.setmaxDistance(maxDistance);
			vector<list<CInputPoint3D>> testVector;
			list<CInputPoint3D> testList;

			//Mindestens vier Punkte in Liste!
			testList.push_back(CInputPoint3D(0.0, 0.0, 0.0, 0.1, Euler));
			testList.push_back(CInputPoint3D(1.0, 1.5, 1.0, 0.2, Euler));
			testList.push_back(CInputPoint3D(5.0, 5.0, 5.0, 0.5, Euler));
			testList.push_back(CInputPoint3D(6.0, 6.0, 6.0, 0.6, Euler));

			testVector.push_back(testList);

			approximator.approx(testVector, log);

			outputVector = approximator.getSegmentsApproxVector();

			Assert::AreEqual<size_t>(2, outputVector[0].size());

			Assert::AreEqual(0.0, outputVector[0].front().getX(), L"X-Koordinate des ersten Punktes stimmt nicht überein");
			Assert::AreEqual(0.0, outputVector[0].front().getY(), L"Y-Koordinate des ersten Punktes stimmt nicht überein");
			Assert::AreEqual(0.0, outputVector[0].front().getZ(), L"Z-Koordinate des ersten Punktes stimmt nicht überein");

			Assert::AreEqual(6.0, outputVector[0].back().getX(), L"X-Koordinate des letzten Punktes stimmt nicht überein");
			Assert::AreEqual(6.0, outputVector[0].back().getY(), L"Y-Koordinate des letzten Punktes stimmt nicht überein");
			Assert::AreEqual(6.0, outputVector[0].back().getZ(), L"Z-Koordinate des letzten Punktes stimmt nicht überein");
		}
	};
}