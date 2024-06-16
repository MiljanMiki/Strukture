#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(10,2);
	stablo.insert(15,7);
	stablo.insert(13,21);
	stablo.insert(31,10);
	stablo.insert(14,1);
	stablo.insert(8,17);
	stablo.insert(5,13);
	stablo.insert(1,11);
	stablo.insert(3,14);
	stablo.insert(4,15);

	//stablo.inorder();

	cout << stablo.brojCvorova(0, 1);


}


