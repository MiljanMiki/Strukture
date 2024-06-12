#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo,stablo2;

	stablo.insert(15);
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
	stablo.insert(6);

	stablo2.insert(25);
	stablo2.insert(32);
	stablo2.insert(38);
	stablo2.insert(50);
	stablo2.insert(18);
	stablo2.insert(12);
	stablo2.insert(10);
	stablo2.insert(7);
	stablo2.insert(8);
	
	
	cout << "Cvor sa najvecom razlikom broja cvorova levog i desnog podstabla je:\n" << stablo2.razlikaCvorova();
}
