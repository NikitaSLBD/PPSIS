#include "Section.h"
#include "Person.h"
#include "IManagement.h"

#pragma once


class MuseumAdministrator : public Person, public IManagement <Museum, Section>
{
public:

	std::vector <Section> get_Chambers(Museum museum);

	void set_Exhibits(Museum& museum, std::string sectionExpoName, std::vector <Exhibit> exhibits = {});
	std::vector <Exhibit> get_Exhibits(Museum museum, std::string sectionExpoName);

	void add(Museum& museum, Section New) override;
	void remove(Museum& museum, Section Del) override;
	void change(Museum& museum, Section Old, Section New) override;
};