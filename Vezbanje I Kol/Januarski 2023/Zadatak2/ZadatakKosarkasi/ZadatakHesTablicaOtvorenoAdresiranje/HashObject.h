#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	int playerNumber;//key
	char* ime;
	char* prezime;
	int yearBorn;
	int jerseyNumber;

public:
	HashObject();
	HashObject(int,char*,char*,int,int);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	//void deleteRecord();
	int getKey() { return playerNumber; };
	int getGodina() { return yearBorn; };
	bool isEqualKey(int k) { return playerNumber == k; };
	void print();
};