#include "IManagement.h"
#include "StaffAdministrator.h"
#include "Museum.h"

using namespace std;

void StaffAdministrator::set_Path(Guide& Employer, vector <Section> path)
{
	Employer.Path = path;
}

vector <Section> StaffAdministrator::get_Path(Guide Employer)
{
	return Employer.get_Path();
}

vector <Guide> StaffAdministrator::get_Staff(Museum museum)
{
	return museum.Staff;
}

void StaffAdministrator::add(Museum& museum, Guide New)
{
	museum.Staff.push_back(New);
}

void StaffAdministrator::remove(Museum& museum, Guide Del)
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

void StaffAdministrator::change(Museum& museum, Guide Old, Guide New)
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