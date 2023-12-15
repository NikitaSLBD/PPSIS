#include "Object.h"

#pragma once



class Exposition : public Object
{
	friend class Guide;

	std::string Description;

public:
	Exposition(std::string name = "", std::string description = "") : Object(name), Description(description) {};
	bool operator == (Exposition right);
};
