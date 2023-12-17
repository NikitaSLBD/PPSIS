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
			Guide Teller;

			Teller.start_tour();
			Assert::IsTrue(Teller.is_busy());

			Teller.end_tour();
			Assert::IsFalse(Teller.is_busy());
		}

		TEST_METHOD(getters)
		{
			Guide Teller("George", "Polleus", "Sergeyevich", "Early history of Belarus");

			Assert::IsTrue(Teller.get_Name() == string("George"));
			Assert::IsTrue(Teller.get_Surname() == string("Polleus"));
			Assert::IsTrue(Teller.get_MiddleName() == string("Sergeyevich"));
			Assert::IsTrue(Teller.get_Specialization() == string("Early history of Belarus"));
		}

		TEST_METHOD(equals)
		{
			Guide Teller1("George", "Polleus", "Sergeyevich", "Early history of Belarus");
			Guide Teller2("George", "Polleus", "Sergeyevich", "Early history of Belarus");

			Assert::IsTrue(Teller1 == Teller2);
		}

		TEST_METHOD(NOTequals)
		{
			Guide Teller1("George", "Polleus", "Sergeyevich", "Early history of Belarus");
			Guide Teller2;

			Assert::IsFalse(Teller1 == Teller2);
		}
	};
}
