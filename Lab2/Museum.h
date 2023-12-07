#include <vector>
#include <string>
#include "Guide.h"
#include "Section.h"
#include "StaffAdministrator.h"
#include "MuseumAdministrator.h"


#pragma once

class Museum
{
	friend class MuseumBuilder;
	friend class StaffAdministrator;
	friend class MuseumAdministrator;

	MuseumAdministrator Manager;
	std::vector <Section> Chambers;

	StaffAdministrator HR;
	std::vector <Guide> Staff;

	Museum() = default;

public:
	MuseumAdministrator get_Manager();
	StaffAdministrator get_HR();
};

















