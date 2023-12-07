#include <string>

#pragma once



class Object
{
	friend class MuseumBuilder;

	std::string Name;

public:
	Object(std::string name = "") : Name(name) {};
	virtual std::string get_Name();
};