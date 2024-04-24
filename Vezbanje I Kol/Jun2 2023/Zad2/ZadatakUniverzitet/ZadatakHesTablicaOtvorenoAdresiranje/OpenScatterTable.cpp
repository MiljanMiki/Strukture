#include "OpenScatterTable.h"
using namespace std;


OpenScatterTable::OpenScatterTable(unsigned int length)
{
	count = 0;
	m = length;
	array = new ScatterObject[m];
}


OpenScatterTable::~OpenScatterTable()
{
	delete[] array;
}

unsigned int OpenScatterTable::c(unsigned int i)
{
	//TODO implementirati sekundarnu funkciju
	return i*i;
}

//unsigned int OpenScatterTable::findUnoccupied(ScatterObject obj)
//{
//	unsigned int hash = h(obj.getKey());
//	unsigned int probe = hash;
//	if (array[probe].status < 2)  // el cringe c funkcija
//		return probe; // slobodan
//	int i = 1;
//	do {
//		probe = (hash + c(i))%m; //kvadratno trazenje?
//		if (array[probe].status < 2)  
//			return probe;
//		i++;
//	} while (probe != hash && i<m);
//	throw new exception("Tablica je puna");
//}

//void OpenScatterTable::withdraw(char * key)
//{
//	if (count == 0) throw new exception("Tablica je prazna");
//	long offset = findMatch(key);
//	if (offset < 0) throw new exception("Nije nadjen!");
//	array[offset].status = 1; // obrisan
//	array[offset] = ScatterObject();
//	count--;
//
//}
//
//unsigned int OpenScatterTable::findMatch(char* key)
//{
//	unsigned int hash = h(key);
//	for (unsigned int i = 0; i < m; i++)
//	{
//		unsigned int probe = hash + c(i);
//		if (array[probe].status == 0) return -1;
//		if (array[probe].isEqualKey(key)) return probe;
//	}
//	return ~0U;
//}

void OpenScatterTable::find(char* key,float* povratnaVrednost) //vraca prosecnu ocenu,godinu upisa i brojIndeksa
{
	unsigned int probe = h(key);
	unsigned int i = 1;
	if (array[probe].status < 2)
		throw "\n**************Trazeni element ne postoji!*****************\n";
	while (!(array[probe].isEqualKey(key)) && i < m)
	{
		probe = (probe + c(i)) % m;
		i++;
	}
	if (i >= m)
		throw "\n***********Trazeni objekat se ne nalazi u tablici!!!***************\n";
	if(!array[probe].isEqualKey(key))
		throw "\n***********Trazeni objekat se ne nalazi u tablici!!!***************\n";

	povratnaVrednost[0] = array[probe].getIndeks();
	povratnaVrednost[1] = array[probe].getGodUpisa();
	povratnaVrednost[2] = array[probe].getProsekOcena();
	
}

void OpenScatterTable::insert(ScatterObject obj)
{
	if (count == m)
		throw "\n**********Tablica je puna!************\n";

	unsigned int probe = h(obj.getKey());
	int i = 1;
	while (array[probe].status == 2 && i<m)
	{
		probe = (probe + c(i)) % m;
		i++;
	}
	if (i >= m)
		throw "\n*********Tablica je puna!***************\n";
	if(array[probe].status==2)
		throw "\n * ********Tablica je puna!***************\n";
	array[probe] = obj;
	array[probe].status = 2;
	count++;

	//if (count == m)
	//	throw new exception("Tablica je puna!");
	//unsigned int offset = findUnoccupied(obj);
	//array[offset] = obj;
	//array[offset].status = 2; // zauzet
	//count++;
}

void OpenScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		array[i].print();
	}
}