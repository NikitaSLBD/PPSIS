#include <vector>
#include <string>
#include "Section.h"
#include "Person.h"

#pragma once

class Guide : public Person
{
	friend class StaffAdministrator;

	bool Busy;

	std::string Specialization;
	std::vector <Section> Path;

public:
	Guide(std::string name = "", std::string surname = "", std::string middlename = "", std::string specialization = "", std::vector <Section> path = {}) : Person(name, surname, middlename), busy(false), Specialization(specialization), Path({}) {};
	std::string get_Specialization();
	std::vector <Section> get_Path();
	bool is_busy();
	bool operator == (Guide right);

	void start_tour();
	void end_tour();

	template <class C>
	std::string get_Description(C Object);
};