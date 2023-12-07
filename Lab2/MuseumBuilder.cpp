#include "MuseumBuilder.h"

using namespace std;

void MuseumBuilder::set_Manager(string name, string surname, string middlename)
{
	Construction.Manager.Name = name;
	Construction.Manager.Surname = surname;
	Construction.Manager.MiddleName = middlename;
}

void MuseumBuilder::set_HR(string name, string surname, string middlename)
{
	Construction.HR.Name = name;
	Construction.HR.Surname = surname;
	Construction.HR.MiddleName = middlename;
}

void MuseumBuilder::init_Chambers()
{
	Construction.Chambers = {};
}

void MuseumBuilder::init_Staff()
{
	Construction.Staff = {};
}

Museum MuseumBuilder::build()
{
	return Construction;
}