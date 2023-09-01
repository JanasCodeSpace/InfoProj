/* Niedrige Prio, da Ergebnis bei Integrationstests geprüft wird */
#include "pch.h"
#include "CppUnitTest.h"
#include "../RobPathGen/header/Logging.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Logging
{/*
	TEST_CLASS(LoggingTests_1)
	{
	public:
		TEST_METHOD(LogDataVectorList)
		{
			string outputPath = "../mainProject/output";
			const int rows = 5;
			const int cols = 13;

			CLogging loggingInstance(outputPath);
			loggingInstance.setStep(2);

			std::vector<CInputPoint3D> testPoints;
			for (int i = 0; i < rows; ++i)
			{
				CInputPoint3D point;
				point.setTime((double)i);
				point.setX((double)i);
				point.setY((double)(2 * i));
				point.setZ((double)(3 * i));
				testPoints.push_back(point);
			}

			loggingInstance.logData(testPoints);

			string expectedFilePath = "../mainProject/output/02_path.csv";
			std::ifstream outputFile(expectedFilePath);
			Assert::IsTrue(outputFile.good(), L"Output file was not created as expected.");

			double data[rows][cols];

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					outputFile >> data[i][j];
				}
			}
			double data[rows][cols];

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					outputFile >> data[i][j];
				}
				Assert::AreEqual(data[i][0], testPoints.at(i).getTime());
				Assert::AreEqual(data[i][1], testPoints.at(i).getX());
				Assert::AreEqual(data[i][2], testPoints.at(i).getY());
				Assert::AreEqual(data[i][3], testPoints.at(i).getZ());
				float testMatrix[3][3];
				testPoints.at(i).getEulerMatrix().getMatrix(testMatrix);
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						int tmpcols = 4 + k + l;
						double expectedValue = data[i][tmpcols];
						double actualValue = testMatrix[k][l];
						Assert::AreEqual(expectedValue, actualValue);
					}
				}
			}
			outputFile.close();
		}

	};*/
}
