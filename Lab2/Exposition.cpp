#include "Exposition.h"

bool Exposition::operator == (Exposition right)
{
	return this->get_Name() == right.get_Name() &&
		this->Description == right.Description;
}