#include "pch.h"
#include "CppUnitTest.h"
#include "../Guide.cpp"
#include "../Section.cpp"
#include "../Exposition.cpp"
#include "../Person.cpp"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGuide
{
	TEST_CLASS(UnitTestGuide)
	{
	public:

		TEST_METHOD(startANDend_tour)
		{
			Guide teller;

			teller.start_tour();
			Assert::IsTrue(teller.is_busy());

			teller.end_tour();
			Assert::IsFalse(teller.is_busy());
		}

		TEST_METHOD(getters)
		{
			Guide teller("George", "Polleus", "Sergeyevich", "Early history of Belarus");

			Assert::IsTrue(teller.get_Name() == string("George"));
			Assert::IsTrue(teller.get_Surname() == string("Polleus"));
			Assert::IsTrue(teller.get_MiddleName() == string("Sergeyevich"));
			Assert::IsTrue(teller.get_Specialization() == string("Early history of Belarus"));
		}

		TEST_METHOD(equals)
		{
			Guide teller1("George", "Polleus", "Sergeyevich", "Early history of Belarus");
			Guide teller2("George", "Polleus", "Sergeyevich", "Early history of Belarus");

			Assert::IsTrue(teller1 == teller2);
		}

		TEST_METHOD(NOTequals)
		{
			Guide teller1("George", "Polleus", "Sergeyevich", "Early history of Belarus");
			Guide teller2;

			Assert::IsFalse(teller1 == teller2);
		}
	};
}
