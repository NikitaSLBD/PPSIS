#include "TicketChecker.h"
#include <vector>

using namespace std;



vector <Ticket> TicketChecker::get_TicketList()
{
	return this->TicketList;
}

bool TicketChecker::is_valid(Ticket pass)
{
	for (int i = 0; i < this->get_TicketList().size(); i++)
	{
		if (this->get_TicketList()[i] == pass)
		{
			return true;
		}
	}

	return false;
}