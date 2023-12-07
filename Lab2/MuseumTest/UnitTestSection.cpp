#include "pch.h"
#include "CppUnitTest.h"
#include "../Section.cpp"
#include "../Exposition.cpp"
#include "../Object.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestSection
{
	TEST_CLASS(UnitTestSection)
	{
	public:

		TEST_METHOD(get_Expo)
		{
			Section room("World history");
			Exposition expo("World history");

			Assert::IsTrue(room.get_Expo() == expo);

		}

		TEST_METHOD(Equal)
		{
			Section room1("", "World history");
			Section room2("", "World history");

			Assert::IsTrue(room1 == room2);

		}
	};
}
