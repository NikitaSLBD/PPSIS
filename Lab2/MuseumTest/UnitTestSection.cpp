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
			Section Room("World history");
			Exposition Expo("World history");

			Assert::IsTrue(Room.get_Expo() == Expo);

		}

		TEST_METHOD(Equal)
		{
			Section Room1("", "World history");
			Section Room2("", "World history");

			Assert::IsTrue(Room1 == Room2);

		}
	};
}
