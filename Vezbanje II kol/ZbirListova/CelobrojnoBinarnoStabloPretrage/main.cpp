#include "BSTreeInt.h"

int main()
{
	BSTreeInt stablo;
	stablo.insert(1);
	stablo.insert(4);
	stablo.insert(8);
	stablo.insert(4);
	stablo.insert(5);
	stablo.insert(2);
	stablo.insert(2);
	stablo.insert(15);
	stablo.insert(3);
	stablo.inorder();

	
	cout <<"\nZbir vrednosti listova je:"<< stablo.zbirListova() << endl;
	cout <<"\nZbir vrednosti listova je (NJIHOVO RESENJE):"<< stablo.SumLeafs(stablo.getRoot()) << endl;
	//KAO STO VIDIMO RESENJA SE SLAZU ZDRAVO DOBARDAN DOVIDJENJA






	return 0;
}
