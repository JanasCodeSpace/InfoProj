#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathCode/header/Logging.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(LoggingTests)
    {
    public:
        TEST_METHOD(TestLogData)
        {            
            CLogging loggingInstance("../output"); // Pfad zum Testen
            
            loggingInstance.setStep(2);

            std::vector<CInputPoint3D> testPoints;
            for (int i = 0; i < 5; ++i)
            {
                CInputPoint3D point;
                point.setTime(i);
                point.setX(static_cast<float>(i));
                point.setY(static_cast<float>(2 * i));
                point.setZ(static_cast<float>(3 * i));
                testPoints.push_back(point);
            }

            loggingInstance.logData(testPoints);

            std::string expectedFilePath = "../output/02_path.csv"; // Erwarteter PFad
            std::ifstream outputFile(expectedFilePath);
            Assert::IsTrue(outputFile.good(), L"Output file was not created as expected.");
                        
            outputFile.close();
        }

    };
}