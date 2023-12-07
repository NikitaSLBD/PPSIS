#include "Visitor.h"
#include "TicketChecker.h"
#include "Ticket.h"

using namespace std;



Ticket Visitor::get_Pass()
{
	return this->Pass;
}

void Visitor::buy_ticket(Ticket& ticket)
{
	if (ticket.get_count())
	{
		this->Pass = ticket;
		ticket.count_decrement();
	}
	else
		throw "!This ticket isn't available!";
	
}

void Visitor::enter(TicketChecker& checker)
{
	if (checker.is_valid(this->Pass))
	{
		this->Pass.count_increment();
		Ticket pass(NULL);
		this->Pass = pass;
	}
	else
		throw "You can't enter. Your pass is not valid";
}


