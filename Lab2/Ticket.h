#include <string>

#pragma once



class Ticket
{
	friend class Visitor;
	friend class TicketEmitter;

	unsigned int count;
	std::string Info;

	void count_increment();
	void count_decrement();

public:
	Ticket(unsigned int num = 0, std::string info = "") : count(num), Info(info) {}
	unsigned int get_count();
	bool operator == (Ticket right);
	std::string get_Info();

};