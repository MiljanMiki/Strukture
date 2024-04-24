#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key;//jmbg

	int indeks;
	char* ime;
	char* prezime;
	int godUpisa;
	float prosekOcena;

public:
	HashObject();
	HashObject(char* k,int,char*,char*,int,float);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	char* getKey() { return key; };
	int getIndeks() { return indeks; };
	int getGodUpisa() { return godUpisa; };
	float getProsekOcena() { return prosekOcena; };
	bool isEqualKey(char* k) { return strcmp(key, k) == 0; };
	void print();
};