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
			TicketChecker checker;
			Ticket pass(15, "Pass to History branch");

			TicketEmitter::add(checker, pass);

			Assert::IsTrue(checker.get_TicketList()[0] == pass);
		}

		TEST_METHOD(Remove)
		{
			TicketChecker checker;
			Ticket pass(15, "Pass to History branch");

			TicketEmitter::add(checker, pass);
			TicketEmitter::remove(checker, pass);

			Assert::IsTrue(checker.get_TicketList().empty());
		}

		TEST_METHOD(Change)
		{
			TicketChecker checker;
			Ticket oldPass(15, "Old pass");
			Ticket newPass(12, "New pass");

			TicketEmitter::add(checker, oldPass);
			TicketEmitter::change(checker, oldPass, newPass);

			Assert::IsTrue(checker.get_TicketList()[0] == newPass);
		}
	};
}
