#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:

	int key;//indeks
	char* ime;
	char* prezime;
	int godUpisa;
public:
	HashObject();
	HashObject(int, char*, char*, int);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	int getKey() { return key; };
	char* getIme() { return ime; };
	char* getPrezIme() { return prezime; };
	int getGodUpisa() { return godUpisa; };
	bool isEqualKey(int k) { return  key== k; };
	 void print();
};