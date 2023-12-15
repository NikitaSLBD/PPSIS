#include "pch.h"
#include "CppUnitTest.h"
#include "../Museum.cpp"
#include "../Museum.cpp"
#include "../Visit.cpp"

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

	TEST_CLASS(UnitTestManager)
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

			vector <Exhibit> artworks = {Exhibit("Winter night", "Painter: Shishkin Ivan Ivanovich (1856)"),
										 Exhibit("La persistencia de la memoria", "Painter: Salvador Dali (1931)")};

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

	TEST_CLASS(UnitTestHR)
	{
	public:

		TEST_METHOD(Add)
		{
			MuseumBuilder builder;

			builder.set_HR();
			builder.init_Staff();


			Museum museum = builder.build();
			vector <Section> path = {Section("Stone age", "First humans in belarussian land"),
									 Section("Cooper age", "First cooper tools in belarussian land"),
									 Section("Iron age and first nations", "First iron tools and towns in belarussian land")};

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
									  Section("Newest time", "Belarussian statehood")};


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

	TEST_CLASS(UnitTestGuide)
	{
	public:

		TEST_METHOD(startANDend_tour)
		{
			Guide teller;

			teller.start_tour();
			Assert::IsTrue(teller.is_busy());

			teller.end_tour();
			Assert::IsFalse(teller.is_busy());
		}
	};
}

namespace UnitTestVisit
{
	TEST_CLASS(UnitTestVisitor)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Visitor human;

			Assert::AreEqual(human.get_Name(), string(""));
			Assert::IsTrue(human.get_Pass() == Ticket(NULL));
			
		}

		TEST_METHOD(buy_ticketValid)
		{
			Visitor human;
			Ticket pass(12);
			
			human.buy_ticket(pass);
		
			Assert::IsTrue(human.get_Pass() == pass);

		}

		TEST_METHOD(buy_ticketInvalid)
		{
			Visitor human;
			Ticket pass(0);

			try
			{
				human.buy_ticket(pass);
			}
			catch (const char exception[])
			{
				Assert::AreEqual(exception, "!This ticket isn't available!");
			}

		}

		TEST_METHOD(enter)
		{
			Visitor human;
			TicketChecker checker;
			Ticket pass(1);

			human.buy_ticket(pass);

			TicketEmitter::add(checker, pass);

			human.enter(checker);

			Assert::IsTrue(human.get_Pass() == Ticket(NULL));

		}
	};

	TEST_CLASS(UnitTestTicketEmitter)
	{
	public:

		TEST_METHOD(Add)
		{
			TicketChecker checker;
			Ticket pass(15, "Pass to History branch");

			TicketEmitter::add(checker, pass);

			Assert::IsTrue(checker.get_TicketList()[0] == pass);
		}

		TEST_METHOD(Remove)
		{
			TicketChecker checker;
			Ticket pass(15, "Pass to History branch");

			TicketEmitter::add(checker, pass);
			TicketEmitter::remove(checker, pass);

			Assert::IsTrue(checker.get_TicketList().empty());
		}

		TEST_METHOD(Change)
		{
			TicketChecker checker;
			Ticket oldPass(15, "Old pass");
			Ticket newPass(12, "New pass");

			TicketEmitter::add(checker, oldPass);
			TicketEmitter::change(checker, oldPass, newPass);

			Assert::IsTrue(checker.get_TicketList()[0] == newPass);
		}
	};
}
