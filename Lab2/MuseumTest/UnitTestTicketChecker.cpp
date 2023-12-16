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
			TicketChecker checker;

			Assert::IsTrue(checker.get_TicketList().empty());
		}

		TEST_METHOD(is_validFalse)
		{
			TicketChecker checker;
			Ticket pass(34);

			Assert::IsFalse(checker.is_valid(pass));
		}

		TEST_METHOD(is_validTrue)
		{
			TicketChecker checker;
			Ticket pass1(34, "Pass"), pass2(67, "Not pass");

			TicketEmitter::add(checker, pass1);
			TicketEmitter::add(checker, pass2);

			Assert::IsTrue(checker.is_valid(pass2));
		}
	};
}
