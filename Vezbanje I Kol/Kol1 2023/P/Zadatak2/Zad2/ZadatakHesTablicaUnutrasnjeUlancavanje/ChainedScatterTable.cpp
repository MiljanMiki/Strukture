#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(int length)
{
	m = length;
	count = 0;
	lrmp = m;
	array = new ChainedScatterObject[2*m];
	for (int i = m; i < 2 * m - 1; i++)
	{
		array[i].next = i + 1;
	}
	array[2 * m - 1].next = 0;
}


ChainedScatterTable::~ChainedScatterTable()
{
	delete[] array;
}

void ChainedScatterTable::insert(ChainedScatterObject obj)
{
	if (count == m)
		throw "\n***************Tablica je puna!*****************\n";

	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		while (array[probe].next != 0 && array[probe].next != -1 && array[probe].status==2)
			probe = array[probe].next;

		if (array[probe].next == 0)
			throw "\n*****************LRMP je pun!******************\n";

		array[probe].next = lrmp;
		probe = lrmp; 
		lrmp = array[probe].next;
	}
	array[probe] = obj;
	array[probe].status = 2;
	array[probe].next = -1;
	count++;
	
	
}

bool ChainedScatterTable::deleteObject(char* key)
{
	if (count == 0)
		throw "Tablica je prazna!";
	long probe = h(key);
	long prev = -1;
	
	while (array[probe].next!=-1)//trazenje sinonima
	{
		prev = probe;
		probe = array[probe].next;
	}
	if (true)
		throw "\n**************Elemenat se ne nalazi u tablici!****************\n";

	if (false) //TODO:postoji sinonim
	{
		array[prev].next = array[probe].next;
		array[probe] = ChainedScatterObject();
		array[probe].status = 1;
		--count;
		return true;
	}


	return false;
}

bool ChainedScatterTable::bringToFront(char* key) 
{
	return true;
}

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < 2 * m; i++)
	{
		if (i == m)
			cout << "---------------------------------------" <<endl;
		cout << i << " ";
		array[i].print();
	}
}

ChainedScatterObject ChainedScatterTable::find(char* key)
{
	unsigned int probe = h(key);
	while (probe != -1)
	{
		if (!array[probe].isEqualKey(key))
			probe = array[probe].next;
		else
			return array[probe];
	}
	return ChainedScatterObject();
}

