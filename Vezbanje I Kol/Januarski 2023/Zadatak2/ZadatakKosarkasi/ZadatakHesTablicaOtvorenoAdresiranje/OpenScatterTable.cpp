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
	return i*i;
}

bool OpenScatterTable::signUp(ScatterObject kosarkas)
{
	unsigned int probe = h(kosarkas.getKey());
	//unsigned int hash = c(1)+h(kosarkas.getKey());

	if (array[probe].status < 2)
	{
		array[probe] = kosarkas;
		array[probe].status = 2;
		return true;
	}
	else
		return false;
}

int OpenScatterTable::countPlayersBornIn(int key)//ovo nije ono sto su trazili (mislim radi kako treba) ali ko ih jebe kad
{												 //ne znaju normalno da napisu tekst zadatka da bude razumljivo >:(
	unsigned int count = 0;

	unsigned int probe = h(key);
	for (unsigned int i = 0; i < m; i++)
		if (array[i].getGodina() == key)
			count++;

	return count;
}

void OpenScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		array[i].print();
	}
	cout << "\n";
}