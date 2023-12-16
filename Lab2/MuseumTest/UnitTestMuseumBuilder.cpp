#include "pch.h"
#include "CppUnitTest.h"
#include "../Museum.cpp"
#include "../MuseumBuilder.cpp"
#include "../MuseumAdministrator.cpp"
#include "../StaffAdministrator.cpp"
#include "../Guide.cpp"
#include "../Section.cpp"
#include "../Exhibit.cpp"
#include "../Exposition.cpp"
#include "../Person.cpp"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestMuseum
{
	TEST_CLASS(UnitTestMuseumBuilder)
	{
	public:

		TEST_METHOD(Default)
		{
			MuseumBuilder builder;

			builder.set_Manager();
			builder.set_HR();
			builder.init_Chambers();
			builder.init_Staff();

			Museum museum = builder.build();

			Assert::AreEqual(museum.get_Manager().get_Name(), string(""));
			Assert::AreEqual(museum.get_Manager().get_Surname(), string(""));
			Assert::AreEqual(museum.get_Manager().get_MiddleName(), string(""));

			Assert::AreEqual(museum.get_HR().get_Name(), string(""));
			Assert::AreEqual(museum.get_HR().get_Surname(), string(""));
			Assert::AreEqual(museum.get_HR().get_MiddleName(), string(""));

			Assert::IsTrue(museum.get_Manager().get_Chambers(museum).empty());
			Assert::IsTrue(museum.get_HR().get_Staff(museum).empty());
		}

		TEST_METHOD(Parametrized)
		{
			MuseumBuilder builder;

			builder.set_Manager("Tomas", "Adyson", "Kyler");
			builder.set_HR("Ivan", "Ivanov", "Ivanovich");
			builder.init_Chambers();
			builder.init_Staff();

			Museum museum = builder.build();

			Assert::AreEqual(museum.get_Manager().get_Name(), string("Tomas"));
			Assert::AreEqual(museum.get_Manager().get_Surname(), string("Adyson"));
			Assert::AreEqual(museum.get_Manager().get_MiddleName(), string("Kyler"));

			Assert::AreEqual(museum.get_HR().get_Name(), string("Ivan"));
			Assert::AreEqual(museum.get_HR().get_Surname(), string("Ivanov"));
			Assert::AreEqual(museum.get_HR().get_MiddleName(), string("Ivanovich"));

			Assert::IsTrue(museum.get_Manager().get_Chambers(museum).empty());
			Assert::IsTrue(museum.get_HR().get_Staff(museum).empty());
		}
	};
}