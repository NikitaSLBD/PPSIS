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
			MuseumBuilder Builder;

			Builder.set_Manager();
			Builder.set_HR();
			Builder.init_Chambers();
			Builder.init_Staff();

			Museum Museum = Builder.build();

			Assert::AreEqual(Museum.get_Manager().get_Name(), string(""));
			Assert::AreEqual(Museum.get_Manager().get_Surname(), string(""));
			Assert::AreEqual(Museum.get_Manager().get_MiddleName(), string(""));

			Assert::AreEqual(Museum.get_HR().get_Name(), string(""));
			Assert::AreEqual(Museum.get_HR().get_Surname(), string(""));
			Assert::AreEqual(Museum.get_HR().get_MiddleName(), string(""));

			Assert::IsTrue(Museum.get_Manager().get_Chambers(Museum).empty());
			Assert::IsTrue(Museum.get_HR().get_Staff(Museum).empty());
		}

		TEST_METHOD(Parametrized)
		{
			MuseumBuilder Builder;

			Builder.set_Manager("Tomas", "Adyson", "Kyler");
			Builder.set_HR("Ivan", "Ivanov", "Ivanovich");
			Builder.init_Chambers();
			Builder.init_Staff();

			Museum Museum = Builder.build();

			Assert::AreEqual(Museum.get_Manager().get_Name(), string("Tomas"));
			Assert::AreEqual(Museum.get_Manager().get_Surname(), string("Adyson"));
			Assert::AreEqual(Museum.get_Manager().get_MiddleName(), string("Kyler"));

			Assert::AreEqual(Museum.get_HR().get_Name(), string("Ivan"));
			Assert::AreEqual(Museum.get_HR().get_Surname(), string("Ivanov"));
			Assert::AreEqual(Museum.get_HR().get_MiddleName(), string("Ivanovich"));

			Assert::IsTrue(Museum.get_Manager().get_Chambers(Museum).empty());
			Assert::IsTrue(Museum.get_HR().get_Staff(Museum).empty());
		}
	};
}