#include "pch.h"
#include "CppUnitTest.h"
#include "../Exhibit.cpp"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestExhibit
{
	TEST_CLASS(UnitTestExhibit)
	{
	public:
		
		TEST_METHOD(Equal)
		{
			Exhibit Item1("Axe");
			Exhibit Item2("Axe");

			Assert::IsTrue(Item1 == Item2);

		}

		TEST_METHOD(NOTequal)
		{
			Exhibit Item1("Axe");
			Exhibit Item2;

			Assert::IsFalse(Item1 == Item2);

		}
	};
}
