#include"HashTable.h"
#include <cmath>

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key) //jmbg (13 broja)
{

	unsigned int b1 = (unsigned int)key[0] * 1000 + (unsigned int)key[1] * 100 + (unsigned int)key[2] * 10 + (unsigned int)key[3]*10 + (unsigned int)key[4] * 1;
	unsigned int b2 = (unsigned int)key[5] * 1000 + (unsigned int)key[6] * 100 + (unsigned int)key[7] * 10 + (unsigned int)key[8]*1;
	unsigned int b3 = (unsigned int)key[9] * 1000 + (unsigned int)key[10] * 100 + (unsigned int)key[11] * 10 + (unsigned int)key[12] * 1;

	return b1+b2+b3;
}

unsigned int HashTable::g(unsigned int key)
{
	return key%m;
}

