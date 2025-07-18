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
		throw new exception("Tablica je puna!");
	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
		{
			probe = array[probe].next;
		}
		if (array[probe].next == 0)
			throw new exception("Izdvojeni prostor za sinonime je pun!");
		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;
	}
	array[probe] = obj;
	array[probe].status = 2; // zauzet
	array[probe].next = -1;
	count++;
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

ChainedScatterObject* ChainedScatterTable::vratiSveKarte(char* key, ChainedScatterObject* niz,int* dimenzija)
{
	int n = *dimenzija;
	int probe = h(key);
	if (array[probe].status < 2)
		throw "\n*************Uneli ste nepostojecu kartu!!!*************\n";

	while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
	{
		if(array[probe].isEqualKey(key))
			n++;

		probe = array[probe].next;
	}
	if (n == 0 && array[probe].next == 0)
		throw "\n*************Nema ove karte!!************\n";

	niz = new ChainedScatterObject[n];

	int k = 0;
	probe = h(key);
	while (array[probe].status == 2 && probe != -1 && k<n)
	{
		niz[k++] = array[probe];
		probe = array[probe].next;
		
	}
	*dimenzija = n;

	return niz;



}

