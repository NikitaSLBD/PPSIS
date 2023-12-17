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
#include "../Exhibit.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTestMuseumAdministrator
{
	TEST_CLASS(UnitTestMuseumAdministrator)
	{
	public:

		TEST_METHOD(Add)
		{
			MuseumBuilder Builder;

			Builder.set_Manager();
			Builder.init_Chambers();

			Museum Museum = Builder.build();
			Guide Teller;
			Section Section("Jurassic world", "Jurassic dinos and plants");

			Museum.get_Manager().add(Museum, Section);

			Assert::IsTrue(Museum.get_Manager().get_Chambers(Museum)[0] == Section);
		}

		TEST_METHOD(Remove)
		{
			MuseumBuilder Builder;

			Builder.set_Manager();
			Builder.init_Chambers();

			Museum Museum = Builder.build();
			Section Section;

			Museum.get_Manager().add(Museum, Section);
			Museum.get_Manager().remove(Museum, Section);

			Assert::IsTrue(Museum.get_Manager().get_Chambers(Museum).empty());
		}

		TEST_METHOD(Change)
		{
			MuseumBuilder Builder;

			Builder.set_Manager();
			Builder.init_Chambers();

			Museum Museum = Builder.build();
			Guide Teller;
			Section OldSection("Old Section", "Old description");
			Section NewSection("New Section", "New description");

			Museum.get_Manager().add(Museum, OldSection);
			Museum.get_Manager().change(Museum, OldSection, NewSection);

			Assert::IsTrue(Museum.get_Manager().get_Chambers(Museum)[0] == NewSection);
		}

		TEST_METHOD(setANDget_Exhibits)
		{
			MuseumBuilder Builder;

			Builder.set_Manager();
			Builder.init_Chambers();

			Museum Museum = Builder.build();
			Guide Teller;
			Section Section("Artworks", "Here had a place popular works of the famous artists");

			vector <Exhibit> Artworks = { Exhibit("Winter night", "Painter: Shishkin Ivan Ivanovich (1856)"),
										 Exhibit("La persistencia de la memoria", "Painter: Salvador Dali (1931)") };

			Museum.get_Manager().add(Museum, Section);
			Museum.get_Manager().set_Exhibits(Museum, Section.get_Expo().get_Name(), Atworks);

			Assert::IsTrue(Museum.get_Manager().get_Exhibits(Museum, Section.get_Expo().get_Name())[0] == Artworks[0]);
			Assert::IsTrue(Museum.get_Manager().get_Exhibits(Museum, Section.get_Expo().get_Name())[1] == Artworks[1]);
		}

		TEST_METHOD(get_ExhibitsInvalidArg)
		{
			MuseumBuilder Builder;

			Builder.set_Manager();
			Builder.init_Chambers();

			Museum Museum = Builder.build();

			try
			{
				Museum.get_Manager().get_Exhibits(Museum, "non-existent");
			}
			catch (const char Exception[])
			{
				Assert::AreEqual(Exception, "!This Exposition isn't exist!");
			}

		}

	};
}