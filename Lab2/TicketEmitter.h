#include "TicketChecker.h"
#include "Ticket.h"
#include "IManagement.h"

#pragma once



static class TicketEmitter : IManagement<TicketChecker, Ticket>
{
public:
	static void add(TicketChecker& checker, Ticket New);
	static void remove(TicketChecker& checker, Ticket Del);
	static void change(TicketChecker& checker, Ticket Old, Ticket New);
};