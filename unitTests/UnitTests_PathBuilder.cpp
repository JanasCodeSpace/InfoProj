#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/PathBuilder.h"
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