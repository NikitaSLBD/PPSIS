#include <string>
#include "Ticket.h"

using namespace std;



bool Ticket::operator == (Ticket right)
{
	return this->get_Info() == right.get_Info();
}

unsigned int Ticket::get_count()
{
	return this->count;
}

string Ticket::get_Info()
{
	return this->Info;
}

void Ticket::count_increment()
{
	this->count++;
}

void Ticket::count_decrement()
{
	this->count--;
}