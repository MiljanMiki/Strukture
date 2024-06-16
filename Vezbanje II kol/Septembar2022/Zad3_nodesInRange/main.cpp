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

	/*stablo.insert(25);
	stablo.insert(30);
	stablo.insert(35);
	stablo.insert(36);
	stablo.insert(34);
	stablo.insert(29);
	stablo.insert(29);
	stablo.insert(28);
	stablo.insert(28);
	stablo.insert(20);
	stablo.insert(21);
	stablo.insert(22);
	stablo.insert(23);
	stablo.insert(10);
	stablo.insert(11);
	stablo.insert(5);
	stablo.insert(6);
	stablo.insert(7);
	stablo.insert(8);*/


	cout << "Broj cvorova u zadatom opsegu je: " << stablo.countNodesInRange(stablo.getRoot(),9,15);
}
