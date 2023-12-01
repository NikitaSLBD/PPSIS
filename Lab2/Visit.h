#pragma once
#include "Museum.h"

//Hierarchy
//	1 Layer
class Visitor;

//	2 Layer
class TicketEmitter;
class TicketChecker;

//	3 Layer
class Ticket;

//	Abstract Layer
class Person;
class Object;



//Lowest Class
class Ticket
{
	friend class TicketEmitter;

	unsigned int count;
	std::string Info;

	void count_increment();
	void count_decrement();

public:
	Ticket(unsigned int num = 0, std::string info = "") : count(num), Info(info) {}
	unsigned int get_count();
	std::string get_Info();

};
//Lowest Class

//High Classes
class TicketChecker
{
	friend void enter(TicketChecker& checker);
	friend class TicketEmitter;

	std::vector <Ticket> TicketList;

public:
	std::vector <Ticket> get_TicketList();
	TicketChecker() : TicketList({}) {}
	bool is_valid(const string pass_info);
};

class TicketEmitter : IManagement<TicketChecker, Ticket>
{
	void add(TicketChecker& checker, const Ticket& New) override;
	void remove(TicketChecker& checker, Ticket& Del) override;
	void change(TicketChecker& checker, Ticket& Old, const Ticket& New) override;
};
//High Classes

//Main Class
class Visitor: public Object
{
	Ticket Pass;

	Ticket get_Pass();
	void buy_ticket(Ticket& ticket);
	void enter(TicketChecker& checker);

	Visitor(std::string name) : Object(name), Pass(NULL) {}
};








