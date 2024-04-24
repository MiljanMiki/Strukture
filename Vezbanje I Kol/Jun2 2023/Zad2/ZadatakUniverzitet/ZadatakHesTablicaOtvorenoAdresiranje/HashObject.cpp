#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = NULL;
	ime = nullptr;
	prezime = nullptr;
	godUpisa = prosekOcena = indeks = 0;
}

HashObject::HashObject(char* k, int index,char* im,char* prez,int gU,float p)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	ime = new char[strlen(im) + 1];
	prezime = new char[strlen(prez) + 1];
	strcpy(prezime,prez);
	strcpy(ime,im);

	indeks = index;
	godUpisa = gU;
	prosekOcena = p;
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
	if (ime)
		delete[] ime;
	if (prezime)
		delete[] prezime;
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
	ime = strcpy(new char[strlen(obj.ime) + 1], obj.ime);
	prezime = strcpy(new char[strlen(obj.prezime) + 1], obj.prezime);
	indeks = obj.indeks;
	godUpisa = obj.godUpisa;
	prosekOcena = obj.prosekOcena;

}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key)
			delete[] key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);
		if (ime)
			delete[] ime;
		ime = new char[strlen(obj.ime) + 1];
		strcpy(ime, obj.ime);

		if (prezime)
			delete[] prezime;
		prezime = new char[strlen(obj.prezime) + 1];
		strcpy(prezime, obj.prezime);

		indeks = obj.indeks;
		prosekOcena = obj.prosekOcena;
		godUpisa = obj.godUpisa;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0) && (strcmp(this->ime, obj.ime) == 0) && (strcmp(prezime,obj.prezime)==0) && indeks==obj.indeks&&godUpisa==obj.godUpisa && prosekOcena==obj.prosekOcena;
}


void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (ime != NULL)
	{
		cout << "|" << ime;
	}
	if (prezime != NULL)
	{
		cout << "|" << prezime;
	}
	cout << "|" << indeks << "|" << godUpisa << "|" << prosekOcena;
	cout << endl;
}