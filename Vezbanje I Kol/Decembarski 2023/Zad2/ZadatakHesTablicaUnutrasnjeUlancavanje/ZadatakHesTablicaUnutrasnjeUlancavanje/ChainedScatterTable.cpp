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

//void ChainedScatterTable::insert(ChainedScatterObject obj)
//{
//	if (count == m)
//		throw new exception("Tablica je puna!");
//	unsigned int probe = h(obj.getKey());
//	if (array[probe].status == 2)
//	{
//		while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
//		{
//			probe = array[probe].next;
//		}
//		if (array[probe].next == 0)
//			throw new exception("Izdvojeni prostor za sinonime je pun!");
//		array[probe].next = lrmp;
//		probe = lrmp;
//		lrmp = array[probe].next;
//	}
//	array[probe] = obj;
//	array[probe].status = 2; // zauzet
//	array[probe].next = -1;
//	count++;
//}

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < 2 * m; i++)
	{
		if (i == m)
			cout << "---------------------------------------" <<endl;
		cout << i << " ";
		array[i].print();
		cout << endl;
	}
}

//ChainedScatterObject ChainedScatterTable::find(int key)
//{
//	unsigned int probe = h(key);
//	while (probe != -1)
//	{
//		if (!array[probe].isEqualKey(key))
//			probe = array[probe].next;
//		else
//			return array[probe];
//	}
//	return ChainedScatterObject();
//}

bool ChainedScatterTable::enlist(ChainedScatterObject obj)
{
	unsigned int probe = h(obj.getKey());
	if (array[probe].status== 2)
	{
		while(probe!=0 && probe!=lrmp)
			probe = array[probe].next;
		if (probe == 0)
			return false;

		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;
	}

	array[probe] = obj;
	array[probe].next = lrmp;
	array[probe].status = 2;
	return true;
}
bool ChainedScatterTable::hasEnlisted(int key)
{
	int probe = h(key);
	//while (array[probe].getKey() != key && probe!=-1 && probe!=0)//puca ovde ako je array[probe] nepostojece
		//probe = array[probe].next;


	while (probe != -1 && probe != 0)
	{
		if (array[probe].getKey() != key)
			probe = array[probe].next;
		else
			return true;
	}
	return false;

	/*if (probe == -1 || probe == 0)
		return false;

	if (array[probe].getKey() == key)
	return true;*/
}

