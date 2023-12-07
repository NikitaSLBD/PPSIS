#include "pch.h"
#include "CppUnitTest.h"
#include "../Visitor.cpp"
#include "../TicketEmitter.cpp"
#include "../TicketChecker.cpp"
#include "../Ticket.cpp"
#include "../Object.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestVisitor
{
	TEST_CLASS(UnitTestVisitor)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Visitor human;

			Assert::AreEqual(human.get_Name(), string(""));
			Assert::IsTrue(human.get_Pass() == Ticket(NULL));

		}

		TEST_METHOD(buy_ticketValid)
		{
			Visitor human;
			Ticket pass(12);

			human.buy_ticket(pass);

			Assert::IsTrue(human.get_Pass() == pass);

		}

		TEST_METHOD(buy_ticketInvalid)
		{
			Visitor human;
			Ticket pass(0);

			try
			{
				human.buy_ticket(pass);
			}
			catch (const char exception[])
			{
				Assert::AreEqual(exception, "!This ticket isn't available!");
			}

		}

		TEST_METHOD(enter)
		{
			Visitor human;
			TicketChecker checker;
			Ticket pass(1);

			human.buy_ticket(pass);

			TicketEmitter::add(checker, pass);

			human.enter(checker);

			Assert::IsTrue(human.get_Pass() == Ticket(NULL));

		}
	};
}
