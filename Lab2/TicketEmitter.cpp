#include "TicketEmitter.h"



void TicketEmitter::add(TicketChecker& checker, Ticket New)
{
	checker.TicketList.push_back(New);
}

void TicketEmitter::remove(TicketChecker& checker, Ticket Del)
{
	for (int i = 0; i < checker.TicketList.size(); i++)
	{
		if (checker.TicketList[i].Info == Del.Info)
		{
			checker.TicketList.erase(checker.TicketList.begin() + i);
		}
	}
}

void TicketEmitter::change(TicketChecker& checker, Ticket Old, Ticket New)
{
	for (int i = 0; i < checker.TicketList.size(); i++)
	{
		if (checker.TicketList[i].Info == Old.Info)
		{
			checker.TicketList[i] = New;
		}
	}
}