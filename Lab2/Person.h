#include <string>
#include "Object.h"

#pragma once



class Person : public Object
{
	friend class MuseumBuilder;

	std::string Surname;
	std::string MiddleName;

public:
	Person(std::string name = "", std::string surname = "", std::string middlename = "") : Object(name), Surname(surname), MiddleName(middlename) {};
	virtual std::string get_Surname();
	virtual std::string get_MiddleName();
};