#include "Section.h"

Exposition Section::get_Expo()
{
	return this->Expo;
}

bool Section::operator == (Section right)
{
	return this->get_Expo() == right.get_Expo();
}