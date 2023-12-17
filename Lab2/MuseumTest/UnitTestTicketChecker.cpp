#include "pch.h"
#include "CppUnitTest.h"
#include "../TicketEmitter.cpp"
#include "../TicketChecker.cpp"
#include "../Ticket.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTicketChecker
{
	TEST_CLASS(UnitTestTicketChecker)
	{
	public:
		
		TEST_METHOD(geter)
		{
			TicketChecker Checker;

			Assert::IsTrue(Checker.get_TicketList().empty());
		}

		TEST_METHOD(is_validFalse)
		{
			TicketChecker Checker;
			Ticket Pass(34);

			Assert::IsFalse(Checker.is_valid(Pass));
		}

		TEST_METHOD(is_validTrue)
		{
			TicketChecker Checker;
			Ticket Pass1(34, "Pass"), Pass2(67, "Not Pass");

			TicketEmitter::add(Checker, Pass1);
			TicketEmitter::add(Checker, Pass2);

			Assert::IsTrue(Checker.is_valid(Pass2));
		}
	};
}
