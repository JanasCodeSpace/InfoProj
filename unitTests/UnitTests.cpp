#include "pch.h"
#include "CppUnitTest.h"
#include "Point3D.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestTimeStamp)
		{
			CPoint3D Test1;
			
			double timestamp = Test1.getTime();

			Assert::AreEqual(0.0, timestamp);
		}
	};
}
