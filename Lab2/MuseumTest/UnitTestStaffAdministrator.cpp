#include "pch.h"
#include "CppUnitTest.h"
#include "../MuseumAdministrator.cpp"
#include "../StaffAdministrator.cpp"
#include "../MuseumBuilder.cpp"
#include "../Museum.cpp"
#include "../Guide.cpp"
#include "../Person.cpp"
#include "../Object.cpp"
#include "../Section.cpp"
#include "../Exposition.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestStaffAdministrator
{
	TEST_CLASS(UnitTestStaffAdministrator)
	{
	public:

		TEST_METHOD(Add)
		{
			MuseumBuilder Builder;

			Builder.set_HR();
			Builder.init_Staff();


			Museum Museum = Builder.build();
			vector <Section> Path = { Section("Stone age", "First humans in belarussian land"),
									 Section("Cooper age", "First cooper tools in belarussian land"),
									 Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			Guide Teller("George", "Polleus", "Sergeyevich", " Early history of Belarus", Path);

			Museum.get_HR().add(Museum, Teller);

			Assert::IsTrue(Museum.get_HR().get_Staff(Museum)[0] == Teller);
		}

		TEST_METHOD(Remove)
		{
			MuseumBuilder Builder;

			Builder.set_HR();
			Builder.init_Staff();


			Museum Museum = Builder.build();
			vector <Section> Path = { Section("Stone age", "First humans in belarussian land"),
									  Section("Cooper age", "First cooper tools in belarussian land"),
									  Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			Guide Teller("George", "Polleus", "Sergeyevich", " Early history of Belarus", Path);

			Museum.get_HR().add(Museum, Teller);
			Museum.get_HR().remove(Museum, Teller);

			Assert::IsTrue(Museum.get_HR().get_Staff(Museum).empty());
		}

		TEST_METHOD(Change)
		{
			MuseumBuilder Builder;

			Builder.set_HR();
			Builder.init_Staff();


			Museum Museum = Builder.build();
			vector <Section> OldPath = { Section("Stone age", "First humans in belarussian land"),
									  Section("Cooper age", "First cooper tools in belarussian land"),
									  Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			vector <Section> NewPath = { Section("New time", "Belarussian lands as a part of Russian Empire"),
									  Section("WWI", "Belarusian lands during of WWI "),
									  Section("WWII", "USSR during of WWII"),
									  Section("Newest time", "Belarussian statehood") };


			Guide OldTeller("Old name", "Old surname", "Old middlename", " Early history of Belarus", OldPath);
			Guide NewTeller("New name", "New surname", "New middlename", "History of Belarus", NewPath);

			Museum.get_HR().add(Museum, OldTeller);
			Museum.get_HR().change(Museum, OldTeller, NewTeller);

			Assert::IsTrue(Museum.get_HR().get_Staff(Museum)[0] == NewTeller);
		}

		TEST_METHOD(set_Path)
		{
			MuseumBuilder Builder;

			Builder.set_HR();
			Builder.init_Staff();


			Museum Museum = Builder.build();
			vector <Section> Path = { Section("Stone age", "First humans in belarussian land"),
									 Section("Cooper age", "First cooper tools in belarussian land"),
									 Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			Guide Teller("");

			Museum.get_HR().add(Museum, Teller);
			Museum.get_HR().set_Path(Teller, Path);

			Assert::IsTrue(Museum.get_HR().get_Path(Teller)[0] == Teller.get_Path()[0]);
			Assert::IsTrue(Museum.get_HR().get_Path(Teller)[1] == Teller.get_Path()[1]);
			Assert::IsTrue(Museum.get_HR().get_Path(Teller)[2] == Teller.get_Path()[2]);
		}

	};
}
