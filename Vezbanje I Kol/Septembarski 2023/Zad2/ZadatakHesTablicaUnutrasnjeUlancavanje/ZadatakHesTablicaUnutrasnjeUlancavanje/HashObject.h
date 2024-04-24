#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* jmbg;//key
	char* brojKarte;//cetvorocifren broj
	char* brojSedista;//trocifren broj
	char* datum;
	unsigned int brojVeceri;

public:
	HashObject();
	HashObject(char* k, char* bK,char* bS,char* dat,unsigned int bV);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	char* getKey() { return jmbg; }
	bool isEqualKey(char* k) { return strcmp(jmbg,k)==0; }
	void print();
};