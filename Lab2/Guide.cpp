#include "Guide.h"

using namespace std;

bool Guide::operator == (Guide right)
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
	return this->Busy;
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
	this->Busy = true;
}

template <class C>

string Guide::get_Description(C Object)
{
	return Object.Description;
}

void Guide::end_tour()
{
	this->Busy = false;
}