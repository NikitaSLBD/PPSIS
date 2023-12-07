#include <vector>
#include "Exposition.h"
#include "Exhibit.h"

#pragma once

class Section
{
	friend class MuseumAdministrator;

	Exposition Expo;
	std::vector <Exhibit> Items;

public:
	Section(std::string name = "", std::string description = "") : Expo(name, description) {};
	Exposition get_Expo();
	bool operator == (Section right);
};