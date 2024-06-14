#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo,stablo2;

	
	stablo.insert(25);
	stablo.insert(30);
	stablo.insert(35);
	stablo.insert(36);
	stablo.insert(34);
	stablo.insert(28);
	stablo.insert(29);
	stablo.insert(27);
	stablo.insert(27);
	stablo.insert(20);
	stablo.insert(21);
	stablo.insert(22);
	stablo.insert(23);
	stablo.insert(10);
	stablo.insert(11);
	stablo.insert(5);
	stablo.insert(6);
	stablo.insert(7);
	stablo.insert(8);

	/*
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
	stablo.insert(5);*/

	stablo2.insert(20);
	stablo2.insert(21);
	stablo2.insert(22);
	stablo2.insert(22);
	stablo2.insert(22);
	stablo2.insert(22);
	stablo2.insert(10);
	stablo2.insert(8);
	stablo2.insert(9);
	/*stablo2.insert(9);
	stablo2.insert(9);
	stablo2.insert(9);*/

	//stablo.postorder();

	BSTNodeInt* p = stablo2.findDeepestLeaf();
	if (p != nullptr)
		cout << "\n\nNajdublji list je:"<<p->getKey();
	else
		cout << "x(";

}
