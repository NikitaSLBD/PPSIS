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
			Visitor Human;

			Assert::AreEqual(Human.get_Name(), string(""));
			Assert::IsTrue(Human.get_Pass() == Ticket(NULL));

		}

		TEST_METHOD(buy_ticketValid)
		{
			Visitor Human;
			Ticket Pass(12);

			Human.buy_ticket(Pass);

			Assert::IsTrue(Human.get_Pass() == Pass);

		}

		TEST_METHOD(buy_ticketInvalid)
		{
			Visitor Human;
			Ticket Pass(0);

			try
			{
				Human.buy_ticket(Pass);
			}
			catch (const char Exception[])
			{
				Assert::AreEqual(Exception, "!This ticket isn't available!");
			}

		}

		TEST_METHOD(enter)
		{
			Visitor Human;
			TicketChecker Checker;
			Ticket Pass(1);

			Human.buy_ticket(Pass);

			TicketEmitter::add(Checker, Pass);

			Human.enter(Checker);

			Assert::IsTrue(Human.get_Pass() == Ticket(NULL));

		}
	};
}
