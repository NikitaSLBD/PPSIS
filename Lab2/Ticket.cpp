#include <string>
#include "Ticket.h"

using namespace std;



bool Ticket::operator == (Ticket right)
{
	return this->get_Info() == right.get_Info();
}

unsigned int Ticket::get_Count()
{
	return this->Count;
}

string Ticket::get_Info()
{
	return this->Info;
}

void Ticket::count_increment()
{
	this->Count++;
}

void Ticket::count_decrement()
{
	this->Count--;
}