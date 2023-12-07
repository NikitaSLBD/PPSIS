#include "Guide.h"
#include "Section.h"
#include "IManagement.h"

#pragma once

class Museum;

class StaffAdministrator : public Person, public IManagement<Museum, Guide>
{
public:

	void set_Path(Guide& Employer, std::vector <Section> path = {});
	std::vector <Section> get_Path(Guide Employer);

	std::vector <Guide> get_Staff(Museum museum);

	void add(Museum& museum, Guide New) override;
	void remove(Museum& museum, Guide Del) override;
	void change(Museum& museum, Guide Old, Guide New) override;
};