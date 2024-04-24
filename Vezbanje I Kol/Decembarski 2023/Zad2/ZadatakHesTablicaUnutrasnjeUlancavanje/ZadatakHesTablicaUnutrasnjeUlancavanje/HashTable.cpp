#include"HashTable.h"

unsigned int HashTable::h(int key)
{
	return g(f(key));
}

unsigned int HashTable::f(int key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	unsigned int zbir = 0;
	unsigned int cifra;
	while (key != 0)
	{
		cifra = key % 10;
		zbir += cifra*17;
		key /= 10;
	}
	return zbir;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	return key%m;
}

