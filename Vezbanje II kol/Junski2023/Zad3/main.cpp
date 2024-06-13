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

	cout<<stablo.maxHeightDiff()->getKey();

}
