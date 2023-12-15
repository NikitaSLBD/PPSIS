#include "Object.h"

#pragma once



class Exhibit : public Object
{
	friend class Guide;

	std::string Description;

public:
	Exhibit(std::string name = "", std::string description = "") : Object(name), Description(description) {};
	bool operator == (Exhibit right);
};