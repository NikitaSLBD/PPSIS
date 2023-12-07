#include "pch.h"
#include "CppUnitTest.h"
#include "../Person.cpp"
#include "../Object.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestPerson
{
	TEST_CLASS(UnitTestPerson)
	{
	public:
		
		TEST_METHOD(get_Surname)
		{
			Person human("", "Wudra");

			Assert::AreEqual(human.get_Surname(), string("Wudra"));
		}

		TEST_METHOD(get_MiddleName)
		{
			Person human("", "", "Loper");

			Assert::AreEqual(human.get_MiddleName(), string("Loper"));
		}
	};
}
