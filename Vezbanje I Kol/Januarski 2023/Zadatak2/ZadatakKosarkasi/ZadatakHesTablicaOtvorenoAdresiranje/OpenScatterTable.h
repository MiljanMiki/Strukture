#pragma once
#include "HashTable.h"
#include "ScatterObject.h"
class OpenScatterTable :public HashTable
{
protected:
	ScatterObject* array;
public:
	OpenScatterTable(unsigned int length);
	~OpenScatterTable();

	bool signUp(ScatterObject kosarkas);
	int countPlayersBornIn(int key);

	unsigned int c(unsigned int i);
	void print();
};

