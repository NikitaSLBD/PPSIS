#include <vector>
#include <string>
#include "Object.h"
#include "IManagement.h"
#include "Ticket.h"
#include "TicketChecker.h"

#pragma once



class Visitor: public Object
{
	Ticket Pass;

public:
	Visitor(std::string name = "") : Object(name), Pass() {}
	Ticket get_Pass();
	void buy_ticket(Ticket& ticket);
	void enter(TicketChecker& checker);
};








