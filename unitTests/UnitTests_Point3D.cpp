#include "pch.h"
#include "CppUnitTest.h"
#include "../header/Point3D.h"
#include "../header/Line3D.h"
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

            double expectedDistance = 32.392477;

            double actualDistance = point.distanceTo(line);

            Assert::AreEqual(expectedDistance, actualDistance, 1e-6);
        }
    };
}
