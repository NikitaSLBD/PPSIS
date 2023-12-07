#include <vector>
#include "Ticket.h"

#pragma once



class TicketChecker
{
	friend void enter(TicketChecker checker);
	friend class TicketEmitter;

	std::vector <Ticket> TicketList;

public:
	std::vector <Ticket> get_TicketList();
	TicketChecker() : TicketList({}) {}
	bool is_valid(Ticket pass);
};