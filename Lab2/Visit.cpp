#include "Visit.h"

using namespace std;


//------------------Visitor----------------------//


Ticket Visitor::get_Pass()
{
	return this->Pass;
}

void Visitor::buy_ticket(Ticket& ticket)
{
	this->Pass = ticket;
}

void Visitor::enter(TicketChecker& checker)
{
	if (checker.is_valid(this->Pass.get_Info()))
	{
		Ticket pass(NULL);
		this->Pass = pass;
	}
	else
		throw "You can't enter. Your pass is not valid";
}


//------------------TicketChecker----------------------//


vector <Ticket> TicketChecker::get_TicketList()
{
	return this->TicketList;
}

bool TicketChecker::is_valid(const string pass_info)
{
	for (int i = 0; i < this->get_TicketList().size(); i++)
	{
		if (this->get_TicketList()[i].get_Info() == pass_info)
		{
			return true;
		}
	}

	return false;
}


//------------------Ticket----------------------//


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


//------------------TicketEmitter----------------------//


void TicketEmitter::add(TicketChecker& checker, const Ticket& New)
{
	checker.TicketList.push_back(New);
}

void TicketEmitter::remove(TicketChecker& checker, Ticket& Del)
{
	for (int i = 0; i < checker.TicketList.size(); i++)
	{
		if (checker.TicketList[i].Info == Del.Info)
		{
			checker.TicketList.erase(checker.TicketList.begin() + i);
		}
	}
}

void TicketEmitter::change(TicketChecker& checker, Ticket& Old, const Ticket& New)
{
	for (int i = 0; i <checker.TicketList.size(); i++)
	{
		if (checker.TicketList[i].Info == Old.Info)
		{
			checker.TicketList[i] = New;
		}
	}
}