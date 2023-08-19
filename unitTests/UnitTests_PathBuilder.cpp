#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathGen/header/PathBuilder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(PathBuilderTests)
    {
    public:
        TEST_METHOD(TestCreatePath)
        {
            CPathBuilder pathBuilder;
            CLogging log;
                        
            std::vector<std::list<CInputPoint3D>> segments;
            // segments füllen

            pathBuilder.createPath(segments, log);

            std::vector<CInputPoint3D>& path = pathBuilder.getPath();
                        
            Assert::IsTrue(path.size() > 0);

            Assert::AreEqual(0.0, path[0].getX());
            Assert::AreEqual(0.0, path[0].getY());
            Assert::AreEqual(0.0, path[0].getZ());

            Assert::AreEqual(0.0, path[path.size() - 1].getX());
            Assert::AreEqual(0.0, path[path.size() - 1].getY());
            Assert::AreEqual(0.0, path[path.size() - 1].getZ());
        }
    };
}