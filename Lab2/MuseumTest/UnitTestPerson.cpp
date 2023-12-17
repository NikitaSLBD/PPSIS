#include "pch.h"
#include "CppUnitTest.h"
#include "../Person.cpp"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestPerson
{
	TEST_CLASS(UnitTestPerson)
	{
	public:
		
		TEST_METHOD(get_Surname)
		{
			Person Human("", "Wudra");

			Assert::AreEqual(Human.get_Surname(), string("Wudra"));
		}

		TEST_METHOD(get_MiddleName)
		{
			Person Human("", "", "Loper");

			Assert::AreEqual(Human.get_MiddleName(), string("Loper"));
		}
	};
}
