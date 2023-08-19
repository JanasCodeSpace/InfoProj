#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/MeanFilter.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeanFilter
{
    TEST_CLASS(MeanFilterTests_1)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            CMeanFilter filter;
            Assert::AreEqual(3, filter.getWindowSize());
        }

        TEST_METHOD(ParamterizedConstructor)
        {
            int windowSize = 5;
            CMeanFilter filter(windowSize);
            Assert::AreEqual(windowSize, filter.getWindowSize());
        }

        TEST_METHOD(SetterAndGetter)
        {
            CMeanFilter filter;
            int windowSize = 7;
            filter.setWindowSize(windowSize);
            Assert::AreEqual(windowSize, filter.getWindowSize());
        }
        TEST_METHOD(Mean)
        {
            CMeanFilter filter;

        }

        TEST_METHOD(GetPath)
        {
            CMeanFilter filter;
            vector<list<CInputPoint3D>>& path = filter.getPath();
            Assert::IsTrue(path.empty());
        }

        TEST_METHOD(CalculateMean)
        {
            CMeanFilter filter;
            list<CInputPoint3D> inputSegment;
                        
            for (int i = 1; i <= 5; i++)
            {
                CInputPoint3D point;
                point.setX(i);
                point.setY(i * 2);
                point.setZ(i * 3);
                inputSegment.push_back(point);
            }

            list<CInputPoint3D> result = filter.calculateMean(inputSegment);

            Assert::AreEqual(inputSegment.size() - filter.getWindowSize(), result.size());

            list<CInputPoint3D>::iterator it = inputSegment.begin();
            for (size_t i = 0; i < inputSegment.size() - filter.getWindowSize(); i++)
            {
                double sumX = 0, sumY = 0, sumZ = 0;
                int div = 0;
                for (size_t j = i; j < i + filter.getWindowSize(); j++)
                {
                    sumX += it->getX();
                    sumY += it->getY();
                    sumZ += it->getZ();
                    div++;
                    it++;
                }
                for (size_t index = filter.getWindowSize(); index > 0; index--) // Pain, the iterator has to be set back
                {
                    it--;
                }
                if (it != inputSegment.end())
                    it++;
                double expectedMeanX = sumX / div;
                double expectedMeanY = sumY / div;
                double expectedMeanZ = sumZ / div;

                CInputPoint3D calculatedPoint = result.front();
                result.pop_front();

                Assert::AreEqual(expectedMeanX, calculatedPoint.getX());
                Assert::AreEqual(expectedMeanY, calculatedPoint.getY());
                Assert::AreEqual(expectedMeanZ, calculatedPoint.getZ());
            }
        }
    };
}