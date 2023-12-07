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
			Exposition expo1("History");
			Exposition expo2("History");

			Assert::IsTrue(expo1 == expo2);

		}
	};
}
