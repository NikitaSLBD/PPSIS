#include "pch.h"
#include "CppUnitTest.h"
#include "../Ticket.cpp"
#include "../Visitor.cpp"
#include "../TicketChecker.cpp"
#include "../TicketEmitter.cpp"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestTicket
{
	TEST_CLASS(UnitTestTicket)
	{
	public:
		
		TEST_METHOD(geters)
		{
			Ticket Pass(23, "Pass Museum");

			Assert::IsTrue(Pass.get_count() == 23);
			Assert::AreEqual(Pass.get_Info(), string("Pass Museum"));
		}

		TEST_METHOD(Equal)
		{
			Ticket Pass1(23);
			Ticket Pass2(23);

			Assert::IsTrue(Pass1 == Pass2);	
		}

		TEST_METHOD(incrANDdecr)
		{
			Ticket Pass(23);
			Visitor Person("Michael");
			TicketChecker Checker;
			
			TicketEmitter::add(Checker, Pass);


			Person.buy_ticket(Pass);

			Assert::IsTrue(Pass.get_count() == 22);

			Person.enter(Checker);

			Assert::IsTrue(Checker.get_TicketList()[0].get_count() == 23);

		}


		
	};
}
