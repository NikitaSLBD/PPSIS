#include "pch.h"
#include "CppUnitTest.h"
#include "../Exposition.cpp"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestExposition
{
	TEST_CLASS(UnitTestExposition)
	{
	public:
		
		TEST_METHOD(Equal)
		{
			Exposition Expo1("History");
			Exposition Expo2("History");

			Assert::IsTrue(Expo1 == Expo2);

		}

		TEST_METHOD(NOTequal)
		{
			Exposition Expo1("History");
			Exposition Expo2;

			Assert::IsFalse(Expo1 == Expo2);

		}
	};
}
