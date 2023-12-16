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
			Ticket pass(23, "Pass Museum");

			Assert::IsTrue(pass.get_count() == 23);
			Assert::AreEqual(pass.get_Info(), string("Pass Museum"));
		}

		TEST_METHOD(Equal)
		{
			Ticket pass1(23);
			Ticket pass2(23);

			Assert::IsTrue(pass1 == pass2);	
		}

		TEST_METHOD(incrANDdecr)
		{
			Ticket pass(23);
			Visitor person("Michael");
			TicketChecker checker;
			
			TicketEmitter::add(checker, pass);


			person.buy_ticket(pass);

			Assert::IsTrue(pass.get_count() == 22);

			person.enter(checker);

			Assert::IsTrue(checker.get_TicketList()[0].get_count() == 23);

		}


		
	};
}
