#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	jmbg = brojKarte = brojSedista = datum = nullptr;
	brojVeceri = 0;
}

HashObject::HashObject(char* k, char* bK, char* bS, char* dat, unsigned int bV)
{
	jmbg = new char[strlen(k) + 1];
	strcpy(jmbg, k);

	brojKarte = new char[strlen(bK) + 1];
	strcpy(brojKarte,bK);

	brojSedista = new char[strlen(bS) + 1];
	strcpy(brojSedista, bS);

	datum = new char[strlen(dat) + 1];
	strcpy(datum,dat);

	brojVeceri = bV;
}

HashObject::~HashObject()
{
	if (jmbg)
		delete[] jmbg;
	if (brojKarte)
		delete[] brojKarte;
	if (brojSedista)
		delete[] brojSedista;
	if (datum)
		delete[] datum;
}

HashObject::HashObject(HashObject const& obj)
{
	jmbg = strcpy(new char[strlen(obj.jmbg) + 1], obj.jmbg);
	brojKarte = strcpy(new char[strlen(obj.brojKarte) + 1], obj.brojKarte);
	brojSedista = strcpy(new char[strlen(obj.brojSedista) + 1], obj.brojSedista);
	datum = strcpy(new char[strlen(obj.datum) + 1], obj.datum);
	brojVeceri = obj.brojVeceri;
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (jmbg)
			delete jmbg;
		jmbg = new char[strlen(obj.jmbg) + 1];
		strcpy(jmbg, obj.jmbg);
		if (brojKarte)
			delete brojKarte;
		brojKarte = new char[strlen(obj.brojKarte) + 1];
		strcpy(brojKarte, obj.brojKarte);

		if (brojSedista)
			delete[] brojSedista;
		if (datum)
			delete[] datum;
		brojSedista = strcpy(new char[strlen(obj.brojSedista) + 1], obj.brojSedista);
		datum = strcpy(new char[strlen(obj.datum) + 1], obj.datum);
		brojVeceri = obj.brojVeceri;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->jmbg, obj.jmbg) == 0) && (strcmp(this->brojKarte, obj.brojKarte) == 0) && (strcmp(brojSedista,obj.brojSedista)==0) && (strcmp(datum,obj.datum))==0 && brojVeceri==obj.brojVeceri;
}

void HashObject::print()
{
	if(jmbg!=NULL)
	{ 
		cout << jmbg;
	}
	if (brojKarte != NULL)
	{
		cout << "|" << brojKarte;
	}
	if (brojSedista != NULL)
	{
		cout << "|" << brojSedista;
	}
	if (datum != NULL)
	{
		cout << "|" << datum;
	}
	cout << "|"<<brojVeceri;
}