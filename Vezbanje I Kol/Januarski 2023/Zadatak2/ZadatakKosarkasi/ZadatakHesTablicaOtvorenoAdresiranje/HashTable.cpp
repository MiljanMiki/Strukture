#include"HashTable.h"

unsigned int HashTable::h(int key)
{
	return g(f(key));
}

unsigned int HashTable::f(int key)
{
	return key;
}

unsigned int HashTable::g(unsigned int key)
{
	return key%m;
}

