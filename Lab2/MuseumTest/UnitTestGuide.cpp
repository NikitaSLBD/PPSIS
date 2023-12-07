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
	};
}
