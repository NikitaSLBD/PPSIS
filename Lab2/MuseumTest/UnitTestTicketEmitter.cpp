#include "pch.h"
#include "CppUnitTest.h"
#include "../TicketEmitter.cpp"
#include "../TicketChecker.cpp"
#include "../Ticket.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTicketEmitter
{
	TEST_CLASS(UnitTestTicketEmitter)
	{
	public:

		TEST_METHOD(Add)
		{
			TicketChecker Checker;
			Ticket Pass(15, "Pass to History branch");

			TicketEmitter::add(Checker, Pass);

			Assert::IsTrue(Checker.get_TicketList()[0] == Pass);
		}

		TEST_METHOD(Remove)
		{
			TicketChecker Checker;
			Ticket Pass(15, "Pass to History branch");

			TicketEmitter::add(Checker, Pass);
			TicketEmitter::remove(Checker, Pass);

			Assert::IsTrue(Checker.get_TicketList().empty());
		}

		TEST_METHOD(Change)
		{
			TicketChecker Checker;
			Ticket OldPass(15, "Old Pass");
			Ticket NewPass(12, "New Pass");

			TicketEmitter::add(Checker, OldPass);
			TicketEmitter::change(Checker, OldPass, NewPass);

			Assert::IsTrue(Checker.get_TicketList()[0] == newPass);
		}
	};
}
