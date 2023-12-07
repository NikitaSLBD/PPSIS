#include "Museum.h"

using namespace std;

vector <Section> MuseumAdministrator::get_Chambers(Museum museum)
{
	return museum.Chambers;
}

void MuseumAdministrator::set_Exhibits(Museum& museum, string ExpoName, const vector <Exhibit> exhibits)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].Expo.get_Name() == ExpoName)
		{
			museum.Chambers[i].Items = exhibits;
		}
	}
}

vector <Exhibit> MuseumAdministrator::get_Exhibits(Museum museum, string ExpoName)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].Expo.get_Name() == ExpoName)
		{
			return museum.Chambers[i].Items;
		}
	}

	throw "!This Exposition isn't exist!";
}

void MuseumAdministrator::add(Museum& museum, Section New)
{
	museum.Chambers.push_back(New);
}

void MuseumAdministrator::remove(Museum& museum, Section Del)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].get_Expo().get_Name() == Del.get_Expo().get_Name())
		{
			museum.Chambers.erase(museum.Chambers.begin() + i);
		}
	}
}

void MuseumAdministrator::change(Museum& museum, Section Old, Section New)
{
	for (int i = 0; i < museum.Chambers.size(); i++)
	{
		if (museum.Chambers[i].get_Expo().get_Name() == Old.get_Expo().get_Name())
		{
			museum.Chambers[i] = New;
		}
	}
}