#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathCode/header/Point3D.h"
#include "../RobPathCode/header/Line3D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(Point3DTests)
    {
    public:
        TEST_METHOD(TestDistanceTo)
        {
            CPoint3D point1(1.0, 2.0, 3.0);
            CPoint3D point2(4.0, 5.0, 6.0);
            CLine3D line(point1, point2);

            double expectedDistance = sqrt(27.0);

            double actualDistance = point1.distanceTo(point2);

            Assert::AreEqual(expectedDistance, actualDistance, 1e-6);
        }

        TEST_METHOD(TestDistanceToLine)
        {
            CPoint3D point(1.0, 2.0, 3.0);
            CPoint3D linePoint1(4.0, 5.0, 6.0);
            CPoint3D linePoint2(7.0, 8.0, 9.0);
            CLine3D line(linePoint1, linePoint2);

            double expectedDistance = sqrt(27.0);

            double actualDistance = point.distanceTo(line);

            Assert::AreEqual(expectedDistance, actualDistance, 1e-6);
        }
    };
}
