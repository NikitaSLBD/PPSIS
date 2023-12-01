#include "Museum.h"

using namespace std;


//------------------Abstraction----------------------//


string Object::get_Name()
{
	return this->Name;
}

string Person::get_Surname()
{
	return this->Surname;
}

string Person::get_MiddleName()
{
	return this->MiddleName;
}

//------------------MuseumBuilder----------------------//


MuseumBuilder MuseumBuilder::set_Manager(string name, string surname, string middlename)
{
	Construction.Manager.Name = name;
	Construction.Manager.Surname = surname;
	Construction.Manager.MiddleName = middlename;

	return *this;
}

MuseumBuilder MuseumBuilder::set_HR(string name, string surname, string middlename)
{
	Construction.HR.Name = name;
	Construction.HR.Surname = surname;
	Construction.HR.MiddleName = middlename;

	return *this;
}

MuseumBuilder MuseumBuilder::init_Chambers()
{
	Construction.Chambers = {};

	return *this;
}

MuseumBuilder MuseumBuilder::init_Staff()
{
	Construction.Staff = {};

	return *this;
}

Museum MuseumBuilder::build()
{
	return Construction;
}


//------------------Museum----------------------//

MuseumAdministrator Museum::get_Manager()
{
	return this->Manager;
}

StaffAdministrator Museum::get_HR()
{
	return this->HR;
}


//------------------MuseumAdministrator----------------------//


vector <Section> MuseumAdministrator::get_Chambers(Museum& museum)
{
	return museum.Chambers;
}

void MuseumAdministrator::set_Exhibits(Museum& museum, string ExpoName, const vector <Exhibit> exhibits)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].Expo.get_Name() == ExpoName)
		{
			museum.Chambers[i].Items = exhibits;
		}
	}
}

vector <Exhibit> MuseumAdministrator::get_Exhibits(Museum& museum, string ExpoName)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].Expo.get_Name() == ExpoName)
		{
			return museum.Chambers[i].Items;
		}
	}

	throw "!This Exposition isn't exist!";
}

void MuseumAdministrator::add(Museum& museum, const Section& New)
{
	museum.Chambers.push_back(New);
}

void MuseumAdministrator::remove(Museum& museum, Section& Del)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].get_Expo().get_Name() == Del.get_Expo().get_Name())
		{
			museum.Chambers.erase(museum.Chambers.begin() + i);
		}
	}
}

void MuseumAdministrator::change(Museum& museum, Section& Old, const Section& New)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].get_Expo().get_Name() == Old.get_Expo().get_Name())
		{
			museum.Chambers[i] = New;
		}
	}
}


//------------------Section----------------------//

Exposition Section::get_Expo()
{
	return this->Expo;
}

bool Section::operator == (Section& right)
{
	for (int i = 0; i < this->Items.size(); i++)
	{
		if (!(this->Items[i] == right.Items[i]))
			return false;
	}

	return this->get_Expo() == right.get_Expo();
}

//------------------Exposition----------------------//

bool Exposition::operator == (Exposition& right)
{
	return this->get_Name() == right.get_Name() &&
		   this->Description == right.Description;
}


//------------------Exhibit----------------------//

bool Exhibit::operator == (Exhibit& right)
{
	return this->get_Name() == right.get_Name() &&
		this->Description == right.Description;
}


//------------------StaffAdministrator----------------------//


void StaffAdministrator::set_Path(Guide& Employer, vector <Section> path)
{
	Employer.Path = path;
}

vector <Section> StaffAdministrator::get_Path(Guide& Employer)
{
	return Employer.get_Path();
}

vector <Guide> StaffAdministrator::get_Staff(Museum& museum)
{
	return museum.Staff;
}

void StaffAdministrator::add(Museum& museum, const Guide& New)
{
	museum.Staff.push_back(New);
}

void StaffAdministrator::remove(Museum& museum, Guide& Del)
{
	for (int i = 0; i < museum.Staff.size(); i++)
	{
		if (museum.Staff[i].get_Specialization() == Del.get_Specialization() &&
			museum.Staff[i].get_Surname() == Del.get_Surname())
		{
			museum.Staff.erase(museum.Staff.begin() + i);
		}
	}
}

void StaffAdministrator::change(Museum& museum, Guide& Old, const Guide& New)
{
	for (int i = 0; i < museum.Staff.size(); i++)
	{
		if (museum.Staff[i].get_Specialization() == Old.get_Specialization() && 
			museum.Staff[i].get_Surname() == Old.get_Surname())
		{
			museum.Staff[i] = New;
		}
	}
}


//------------------Guide----------------------//

bool Guide::operator == (Guide& right)
{
	for (int i = 0; i < this->get_Path().size(); i++)
	{
		if (!(this->get_Path()[i] == right.get_Path()[i]))
			return false;
	}

	return this->get_Name() == right.get_Name() &&
		   this->get_Surname() == right.get_Surname() &&
		   this->get_MiddleName() == right.get_MiddleName() &&
		   this->get_Specialization() == right.get_Specialization();
}

bool Guide::is_busy()
{
	return this->busy;
}

string Guide::get_Specialization()
{
	return this->Specialization;
}

vector <Section> Guide::get_Path()
{
	return this->Path;
}

void Guide::start_tour()
{
	this->busy = true;
}

template <class C>

string Guide::get_Description(C& Object)
{
	return Object.Description;
}

void Guide::end_tour()
{
	this->busy = false;
}












