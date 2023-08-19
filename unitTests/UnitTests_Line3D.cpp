#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathGen/header/Line3D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(Line3DTests)
    {
    public:
        TEST_METHOD(Constructor_Default)
        {
            CLine3D line;

            Assert::IsTrue(line.p1.getX() == 0 && line.p1.getY() == 0 && line.p1.getZ() == 0);
            Assert::IsTrue(line.p2.getX() == 0 && line.p2.getY() == 0 && line.p2.getZ() == 0);
        }

        TEST_METHOD(Constructor_WithPoints)
        {
            CPoint3D point1(0, 0, 0);
            CPoint3D point2(1, 1, 1);
            CLine3D line(point1, point2);

            // Überprüfung, ob der Konstruktor mit Punkten ordnungsgemäß arbeitet
            Assert::AreEqual(line.p1.getX(), point1.getX());
            Assert::AreEqual(line.p2.getX(), point2.getX());
            Assert::AreEqual(line.p1.getY(), point1.getY());
            Assert::AreEqual(line.p2.getY(), point2.getY());
        }

        TEST_METHOD(Destructor)
        {
            CPoint3D point1(0, 0, 0);
            CPoint3D point2(1, 1, 1);
            CLine3D* line = new CLine3D(point1, point2);

            delete line;

            // Hier könnten weitere Überprüfungen auf die Destruktion durchgeführt werden,
            // abhängig von den Funktionalitäten der Klasse und dem gewünschten Testumfang.
        }
    };
}