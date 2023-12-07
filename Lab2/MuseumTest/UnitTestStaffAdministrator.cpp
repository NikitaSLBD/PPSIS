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
			MuseumBuilder builder;

			builder.set_HR();
			builder.init_Staff();


			Museum museum = builder.build();
			vector <Section> path = { Section("Stone age", "First humans in belarussian land"),
									 Section("Cooper age", "First cooper tools in belarussian land"),
									 Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			Guide teller("George", "Polleus", "Sergeyevich", " Early history of Belarus", path);

			museum.get_HR().add(museum, teller);

			Assert::IsTrue(museum.get_HR().get_Staff(museum)[0] == teller);
		}

		TEST_METHOD(Remove)
		{
			MuseumBuilder builder;

			builder.set_HR();
			builder.init_Staff();


			Museum museum = builder.build();
			vector <Section> path = { Section("Stone age", "First humans in belarussian land"),
									  Section("Cooper age", "First cooper tools in belarussian land"),
									  Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			Guide teller("George", "Polleus", "Sergeyevich", " Early history of Belarus", path);

			museum.get_HR().add(museum, teller);
			museum.get_HR().remove(museum, teller);

			Assert::IsTrue(museum.get_HR().get_Staff(museum).empty());
		}

		TEST_METHOD(Change)
		{
			MuseumBuilder builder;

			builder.set_HR();
			builder.init_Staff();


			Museum museum = builder.build();
			vector <Section> oldPath = { Section("Stone age", "First humans in belarussian land"),
									  Section("Cooper age", "First cooper tools in belarussian land"),
									  Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			vector <Section> newPath = { Section("New time", "Belarussian lands as a part of Russian Empire"),
									  Section("WWI", "Belarusian lands during of WWI "),
									  Section("WWII", "USSR during of WWII"),
									  Section("Newest time", "Belarussian statehood") };


			Guide oldTeller("Old name", "Old surname", "Old middlename", " Early history of Belarus", oldPath);
			Guide newTeller("New name", "New surname", "New middlename", "History of Belarus", newPath);

			museum.get_HR().add(museum, oldTeller);
			museum.get_HR().change(museum, oldTeller, newTeller);

			Assert::IsTrue(museum.get_HR().get_Staff(museum)[0] == newTeller);
		}

		TEST_METHOD(set_Path)
		{
			MuseumBuilder builder;

			builder.set_HR();
			builder.init_Staff();


			Museum museum = builder.build();
			vector <Section> path = { Section("Stone age", "First humans in belarussian land"),
									 Section("Cooper age", "First cooper tools in belarussian land"),
									 Section("Iron age and first nations", "First iron tools and towns in belarussian land") };

			Guide teller("");

			museum.get_HR().add(museum, teller);
			museum.get_HR().set_Path(teller, path);

			Assert::IsTrue(museum.get_HR().get_Path(teller)[0] == teller.get_Path()[0]);
			Assert::IsTrue(museum.get_HR().get_Path(teller)[1] == teller.get_Path()[1]);
			Assert::IsTrue(museum.get_HR().get_Path(teller)[2] == teller.get_Path()[2]);
		}

	};
}
