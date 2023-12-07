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
			MuseumBuilder builder;

			builder.set_Manager();
			builder.init_Chambers();

			Museum museum = builder.build();
			Guide teller;
			Section section("Jurassic world", "Jurassic dinos and plants");

			museum.get_Manager().add(museum, section);

			Assert::IsTrue(museum.get_Manager().get_Chambers(museum)[0] == section);
		}

		TEST_METHOD(Remove)
		{
			MuseumBuilder builder;

			builder.set_Manager();
			builder.init_Chambers();

			Museum museum = builder.build();
			Section section;

			museum.get_Manager().add(museum, section);
			museum.get_Manager().remove(museum, section);

			Assert::IsTrue(museum.get_Manager().get_Chambers(museum).empty());
		}

		TEST_METHOD(Change)
		{
			MuseumBuilder builder;

			builder.set_Manager();
			builder.init_Chambers();

			Museum museum = builder.build();
			Guide teller;
			Section oldSection("Old section", "Old description");
			Section newSection("New section", "New description");

			museum.get_Manager().add(museum, oldSection);
			museum.get_Manager().change(museum, oldSection, newSection);

			Assert::IsTrue(museum.get_Manager().get_Chambers(museum)[0] == newSection);
		}

		TEST_METHOD(setANDget_Exhibits)
		{
			MuseumBuilder builder;

			builder.set_Manager();
			builder.init_Chambers();

			Museum museum = builder.build();
			Guide teller;
			Section section("Artworks", "Here had a place popular works of the famous artists");

			vector <Exhibit> artworks = { Exhibit("Winter night", "Painter: Shishkin Ivan Ivanovich (1856)"),
										 Exhibit("La persistencia de la memoria", "Painter: Salvador Dali (1931)") };

			museum.get_Manager().add(museum, section);
			museum.get_Manager().set_Exhibits(museum, section.get_Expo().get_Name(), artworks);

			Assert::IsTrue(museum.get_Manager().get_Exhibits(museum, section.get_Expo().get_Name())[0] == artworks[0]);
			Assert::IsTrue(museum.get_Manager().get_Exhibits(museum, section.get_Expo().get_Name())[1] == artworks[1]);
		}

		TEST_METHOD(get_ExhibitsInvalidArg)
		{
			MuseumBuilder builder;

			builder.set_Manager();
			builder.init_Chambers();

			Museum museum = builder.build();

			try
			{
				museum.get_Manager().get_Exhibits(museum, "non-existent");
			}
			catch (const char exception[])
			{
				Assert::AreEqual(exception, "!This Exposition isn't exist!");
			}

		}

	};
}