#include "pch.h"
#include "CppUnitTest.h"
#include "../../TicTacToe.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTTT
{
	TEST_CLASS(UnitTestTTT)
	{
	public:

		TEST_METHOD(get_contentTest)
		{
			TicTacToe TTT;

			Assert::AreEqual(TTT.get_content(0), '_');
			Assert::AreEqual(TTT.get_content(1), '_');
			Assert::AreEqual(TTT.get_content(2), '_');
			Assert::AreEqual(TTT.get_content(3), '_');
			Assert::AreEqual(TTT.get_content(4), '_');
			Assert::AreEqual(TTT.get_content(5), '_');
			Assert::AreEqual(TTT.get_content(6), '_');
			Assert::AreEqual(TTT.get_content(7), '_');
			Assert::AreEqual(TTT.get_content(8), '_');
		}

		TEST_METHOD(get_playerTest)
		{
			TicTacToe TTT;

			Assert::IsTrue(TTT.get_player());
		}

		TEST_METHOD(switch_playerTest)
		{
			TicTacToe TTT;
			TTT.switch_player();

			Assert::IsFalse(TTT.get_player());
		}

		TEST_METHOD(operatTest_validmove)
		{
			TicTacToe TTT;
			TTT[0];

			Assert::AreEqual(TTT.get_content(0), 'X');
		}

		TEST_METHOD(operatTest_invalidmove)
		{
			TicTacToe TTT;
			TTT[0];
			TTT.switch_player();

			try
			{
				TTT[0];
			}
			catch (const char exception[])
			{
				Assert::AreEqual(exception, "This cell is filled");
			}
		}

		TEST_METHOD(switch_playerTest_after_invalidmove)
		{
			TicTacToe TTT;
			TTT[0];
			TTT.switch_player();

			try
			{
				TTT[0];
			}
			catch (...)
			{
				Assert::IsTrue(TTT.get_player());
			}
		}

		TEST_METHOD(is_winTest_notwin)
		{
			TicTacToe TTT;

			Assert::IsFalse(TTT.is_win());
		}

		TEST_METHOD(is_winTest_win)
		{
			TicTacToe TTT;
			TTT[0];
			TTT[1];
			TTT[2];

			Assert::IsTrue(TTT.is_win());
		}

		TEST_METHOD(is_dryTest_notdry)
		{
			TicTacToe TTT;

			Assert::IsFalse(TTT.is_dry());
		}

		TEST_METHOD(is_dryTest_dry)
		{
			TicTacToe TTT;
			TTT[0];
			TTT[1];
			TTT[4];
			TTT[5];
			TTT[6];
			TTT.switch_player();
			TTT[2];
			TTT[3];
			TTT[7];
			TTT[8];

			Assert::IsTrue(TTT.is_dry());
		}

		TEST_METHOD(is_dryTest_dryandwin)
		{
			TicTacToe TTT;
			TTT[2];
			TTT[4];
			TTT[7];
			TTT[8];
			TTT.switch_player();
			TTT[5];
			TTT[1];
			TTT[0];
			TTT[3];
			TTT[6];

			Assert::IsFalse(TTT.is_dry());
			Assert::IsTrue(TTT.is_win());
		}
	};
}
