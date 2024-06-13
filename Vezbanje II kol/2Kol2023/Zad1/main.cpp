#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo,stablo2;

	/*stablo.insert(15);
	stablo.insert(13);
	stablo.insert(25);
	stablo.insert(20);
	stablo.insert(61);
	stablo.insert(7);
	stablo.insert(14);
	stablo.insert(5);
	stablo.insert(11);
	stablo.insert(2);
	stablo.insert(3);
	stablo.insert(6);*/

	stablo.insert(4);
	stablo.insert(4);
	stablo.insert(8);
	stablo.insert(15);
	stablo.insert(5);
	stablo.insert(2);
	stablo.insert(3);
	stablo.insert(1);
	stablo.insert(2);

	//stablo.inorder();

	stablo2.insert(20);
	stablo2.insert(14);
	stablo2.insert(22);
	stablo2.insert(21);
	stablo2.insert(25);
	stablo2.insert(10);
	stablo2.insert(17);
	stablo2.insert(15);
	stablo2.insert(19);
	stablo2.insert(12);
	stablo2.insert(9);
	stablo2.insert(9);
	stablo2.insert(5);

	//stablo2.inorder();

	cout<<"Cvor sa najvecom razlikom parnih i neparnih brojeva njegovi podstabla je:\n"<<stablo2.razlikaPodstabla();

}
