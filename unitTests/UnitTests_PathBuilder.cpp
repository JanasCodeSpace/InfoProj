#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathGen/header/PathBuilder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathBuilder
{
    TEST_CLASS(PathBuilderTests_1)
    {
    public:
        TEST_METHOD(TestCreatePath)
        {
            CPathBuilder pathBuilder;
            CLogging log;
            int numberPoints = 10;
                        
            vector<list<CInputPoint3D>> segments;
            list<CInputPoint3D> dummyDaten, outputDaten;
            for (int i = 1; i <= numberPoints; i++)
            {
                CInputPoint3D point;
                point.setX(i);
                point.setY(i * 2);
                point.setZ(i * 3);
                dummyDaten.push_back(point);
            }
            segments.push_back(dummyDaten);

            pathBuilder.createPath(segments, log);

            std::vector<CInputPoint3D>& path = pathBuilder.getPath();
                        
            Assert::IsTrue(path.size() > 0);

            Assert::AreEqual(1.0, path[0].getX());
            Assert::AreEqual(2.0, path[0].getY());
            Assert::AreEqual(3.0, path[0].getZ());

            Assert::AreEqual(10.0, path[path.size() - 1].getX());
            Assert::AreEqual(20.0, path[path.size() - 1].getY());
            Assert::AreEqual(30.0, path[path.size() - 1].getZ());
        }
    };
}