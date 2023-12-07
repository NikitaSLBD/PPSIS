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
			Exhibit item1("Axe");
			Exhibit item2("Axe");

			Assert::IsTrue(item1 == item2);

		}
	};
}
