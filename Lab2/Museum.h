#include <vector>
#include <string>

#pragma once

//Hierarchy
//	1 Layer
class Museum;
class MuseumBuilder;

//	2 Layer
class MuseumAdministrator;
class StaffAdministrator;
class Guide;

//	3 Layer
class Section;
class Exposition;
class Exhibit;

// Abstract Layer
class Person;
class Object;


//Abstraction
template <class C1, class C2>

class IManagement
{
	virtual void add(C1&, const C2&) = 0;
	virtual void remove(C1&, C2&) = 0;
	virtual void change(C1&, C2&, const C2&) = 0;
};

class Object
{
	friend class MuseumBuilder;

	std::string Name;

public:
	Object(std::string name = "") : Name(name) {};
	virtual std::string get_Name();
};

class Person : public Object
{
	friend class MuseumBuilder;

	std::string Surname;
	std::string MiddleName;

public:
	Person(std::string name = "", std::string surname = "", std::string middlename = "") : Object(name), Surname(surname), MiddleName(middlename) {};
	virtual std::string get_Surname();
	virtual std::string get_MiddleName();
};
//Abstraction


//Lowest Classes
class Exhibit : public Object
{
	friend class Guide;

	std::string Description;

public:
	Exhibit(std::string name = "", std::string description = "") : Object(name), Description(description) {};
	bool operator == (Exhibit& right);
};

class Exposition : public Object
{
	friend class Guide;

	std::string Description;

public:
	Exposition(std::string name = "", std::string description = "") : Object(name), Description(description) {};
	bool operator == (Exposition& right);
};

class Section
{
	friend class MuseumAdministrator;

	Exposition Expo;
	std::vector <Exhibit> Items;

public:
	Section(std::string name = "", std::string description = "") : Expo(name, description) {};
	Exposition get_Expo();
	bool operator == (Section& right);
};
//Lowest Classes


//High Classes
class Guide : public Person
{
	friend class StaffAdministrator;

	bool busy;

	std::string Specialization;
	std::vector <Section> Path;

public:
	Guide(std::string name = "", std::string surname = "", std::string middlename = "", std::string specialization = "", std::vector <Section> path = {}) : Person(name, surname, middlename), busy(false), Specialization(specialization), Path({}) {};
	std::string get_Specialization();
	std::vector <Section> get_Path();
	bool is_busy();
	bool operator == (Guide& right);

	void start_tour();
	void end_tour();

	template <class C>
	std::string get_Description(C& Object);
};

class MuseumAdministrator : public Person, public IManagement <Museum, Section>
{
public:

	std::vector <Section> get_Chambers(Museum& museum);

	void set_Exhibits(Museum& museum, std::string sectionExpoName, std::vector <Exhibit> exhibits = {});
	std::vector <Exhibit> get_Exhibits(Museum& museum, std::string sectionExpoName);

	void add(Museum& museum, const Section& New) override;
	void remove(Museum& museum, Section& Del) override;
	void change(Museum& museum, Section& Old, const Section& New) override;
};

class StaffAdministrator : public Person, public IManagement<Museum, Guide>
{
public:

	void set_Path(Guide& Employer, std::vector <Section> path = {});
	std::vector <Section> get_Path(Guide& Employer);

	std::vector <Guide> get_Staff(Museum& museum);

	void add(Museum& museum, const Guide& New) override;
	void remove(Museum& museum, Guide& Del) override;
	void change(Museum& museum, Guide& Old, const Guide& New) override;
};
//High Classes

//Main Class
class Museum
{
	friend class MuseumBuilder;
	friend class StaffAdministrator;
	friend class MuseumAdministrator;

	MuseumAdministrator Manager;
	std::vector <Section> Chambers;

	StaffAdministrator HR;
	std::vector <Guide> Staff;

	Museum() = default;

public:
	MuseumAdministrator get_Manager();
	StaffAdministrator get_HR();
};

//Main Class Builder
class MuseumBuilder
{
	Museum Construction;

public:
	MuseumBuilder set_Manager(std::string name = "", std::string surname = "", std::string middlename = "");
	MuseumBuilder set_HR(std::string name = "", std::string surname = "", std::string middlename = "");
	MuseumBuilder init_Chambers();
	MuseumBuilder init_Staff();
	Museum build();
};

















