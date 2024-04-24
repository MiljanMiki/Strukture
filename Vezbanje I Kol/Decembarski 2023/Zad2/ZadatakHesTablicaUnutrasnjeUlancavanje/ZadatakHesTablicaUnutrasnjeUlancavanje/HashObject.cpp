#include "HashObject.h"

using std::cout;
using std::endl;


HashObject::HashObject()
{
	key = 0;
	ime = nullptr;
	prezime = nullptr;
	godUpisa  = 0;
}

HashObject::HashObject( int index, char* im, char* prez,int gU)
{
	key = index;
	ime = new char[strlen(im) + 1];
	prezime = new char[strlen(prez) + 1];
	strcpy(prezime, prez);
	strcpy(ime, im);

	godUpisa = gU;
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
	key = obj.key;
	ime = strcpy(new char[strlen(obj.ime) + 1], obj.ime);
	prezime = strcpy(new char[strlen(obj.prezime) + 1], obj.prezime);
	godUpisa = obj.godUpisa;

}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		key = obj.key;
		if (ime)
			delete[] ime;
		ime = new char[strlen(obj.ime) + 1];
		strcpy(ime, obj.ime);

		if (prezime)
			delete[] prezime;
		prezime = new char[strlen(obj.prezime) + 1];
		strcpy(prezime, obj.prezime);

		godUpisa = obj.godUpisa;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return key==obj.key && (strcmp(this->ime, obj.ime) == 0) && (strcmp(prezime, obj.prezime) == 0) && godUpisa == obj.godUpisa;
}


void HashObject::print()
{
	cout << key;
	if (ime != NULL)
	{
		std::cout << "|" << ime;
	}
	if (prezime != NULL)
	{
		std::cout << "|" << prezime;
	}
	cout << "|" << godUpisa << "|";
}