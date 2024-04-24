#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	ime = nullptr;
	prezime = nullptr;
	playerNumber = jerseyNumber = yearBorn = 0;
}

HashObject::HashObject(int pN,char* i,char*prez,int yB,int jN)
{
	ime = new char[strlen(i) + 1];
	strcpy(ime,i);
	prezime = new char[strlen(prez) + 1];
	strcpy(prezime,prez);

	playerNumber = pN;
	yearBorn = yB;
	jerseyNumber = jN;
}

HashObject::~HashObject()
{
	if (ime)
		delete[] ime;
	if (prezime)
		delete[] prezime;
}

HashObject::HashObject(HashObject const& obj)
{
	ime = strcpy(new char[strlen(obj.ime) + 1], obj.ime);
	prezime = strcpy(new char[strlen(obj.prezime) + 1], obj.prezime);
	yearBorn = obj.yearBorn;
	playerNumber = obj.playerNumber;
	jerseyNumber = obj.jerseyNumber;
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (ime!=nullptr)
			delete[] ime;
		ime = new char[strlen(obj.ime) + 1];
		strcpy(ime, obj.ime);
		if (prezime!=nullptr)
			delete[] prezime;
		prezime = new char[strlen(obj.prezime) + 1];
		strcpy(prezime, obj.prezime);

		yearBorn = obj.yearBorn;
		playerNumber = obj.playerNumber;
		jerseyNumber = obj.jerseyNumber;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->ime, obj.ime) == 0) && (strcmp(this->prezime, obj.prezime) == 0) && playerNumber==obj.playerNumber && jerseyNumber==obj.jerseyNumber&&yearBorn==obj.yearBorn;
}


void HashObject::print()
{
	if(ime!=NULL)
	{ 
		cout << ime;
	}
	if (prezime != NULL)
	{
		cout << "|" << prezime;
	}
	cout << "|" << playerNumber << "|" << yearBorn << "|" << jerseyNumber<<endl;
}