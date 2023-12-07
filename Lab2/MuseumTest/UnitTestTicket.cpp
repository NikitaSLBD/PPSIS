#include "pch.h"
#include "CppUnitTest.h"
#include "../Ticket.cpp"

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
		
	};
}
