#include <string>

#pragma once



class MuseumBuilder
{
	Museum Construction;

public:
	void set_Manager(std::string name = "", std::string surname = "", std::string middlename = "");
	void set_HR(std::string name = "", std::string surname = "", std::string middlename = "");
	void init_Chambers();
	void init_Staff();
	Museum build();
};