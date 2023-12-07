#include "pch.h"
#include "CppUnitTest.h"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestObject
{
	TEST_CLASS(UnitTestObject)
	{
	public:
		
		TEST_METHOD(get_Name)
		{
			Object sword("Sword");

			Assert::AreEqual(sword.get_Name(), string("Sword"));

		}
	};
}
