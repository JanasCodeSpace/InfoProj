#include "pch.h"
#include "CppUnitTest.h"
#include "../mainProject/header/RobCodeGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RobCodeGenerator
{
	TEST_CLASS(RobCodeGeneratorTests_1)
	{
	public:
		TEST_METHOD(GenerateRobCodeDefault)
		{
			int numberPoints = 10;
			double x = 5.0;
			double y = x * 3;
			double z = y + 5;
			double speedIn = 1.5;
			bool speedManualIn = true;
			bool orientationManualIn = true;			
			auto angles = make_tuple(x, y, z);
			string filePath = "testOutput";
			string fileName = "testFile.src";
			CLogging log;
			
			CRobCodeGenerator DefaultGenerator;
			// CRobCodeGenerator ParamterizedGenerator(speedIn, speedManualIn, orientationManualIn, angles);
						
			vector<list<CInputPoint3D>> segments;
			list<CInputPoint3D> dummyDaten, outputDaten;
			for (int i = 1; i <= numberPoints; i++)
			{
				CInputPoint3D point;
				point.setX(i);
				point.setY(i * 2);
				point.setZ(i * 3);
				point.setTime(i);
				dummyDaten.push_back(point);
			}
			segments.push_back(dummyDaten);

			CInputPoint3D point; // Startpunkt
			vector<CInputPoint3D> points;
			for (size_t s = 0; s < segments.size(); s++) // Über alle Segmente
			{
				list<CInputPoint3D>::iterator itr = segments[s].begin();

				for (; itr != segments[s].end(); itr++) //Über alle Punkte aller Segmente
				{
					point.set((double)itr->getX(), (double)itr->getY(), (double)itr->getZ());
					point.setTime(itr->getTime());
					point.setEulerMatrix(itr->getEulerMatrix());
					points.push_back(point);
				}

				itr--;
			}
			DefaultGenerator.generateRobCode(points, filePath, fileName, log);						
		}
	};
}