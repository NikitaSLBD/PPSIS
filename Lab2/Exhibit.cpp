#include "Exhibit.h"

bool Exhibit::operator == (Exhibit right)
{
	return this->get_Name() == right.get_Name() &&
		this->Description == right.Description;
}
