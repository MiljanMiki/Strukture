#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

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

	stablo.inorder();
	cout << endl;
	int d;
	cin >> d;
	cout << "Broj cvorova koji u svojim podstablima imaju barem jedan cvor koji je u opsegu ";
	cout << "od " << stablo.getNumOfElem() - d << " do " << stablo.getNumOfElem() << " je:\n" << stablo.countSmaller(d);

	//za d=10 rezultat je:5
	//za d=1 rezultat je: 0
	//za d=5 rezultat je: 3


}
