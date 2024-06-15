#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(20);
	stablo.insert(14);
	stablo.insert(22);
	stablo.insert(21);
	stablo.insert(25);
	stablo.insert(10);
	stablo.insert(17);
	stablo.insert(15);
	stablo.insert(19);
	stablo.insert(12);
	stablo.insert(9);
	stablo.insert(9);
	stablo.insert(5);

	cout<<"Da li je stablo perfektno:"<<stablo.isPerfect();

}
