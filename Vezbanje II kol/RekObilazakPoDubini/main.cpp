#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	graf.insertNode(1);
	graf.insertNode(2);
	graf.insertNode(3);
	graf.insertNode(4);
	graf.insertNode(5);
	graf.insertNode(6);
	graf.insertNode(7);
	graf.insertNode(8);

	graf.insertEdge(1, 2);
	graf.insertEdge(1, 4);
	graf.insertEdge(2,3);
	graf.insertEdge(4,6);
	graf.insertEdge(4,5);
	graf.insertEdge(5,7);
	graf.insertEdge(7,8);

	//dodajemo komponentu povezanosti grafu
	graf.insertNode(9);
	graf.insertNode(10);
	//graf.insertEdge(8, 9);
	graf.insertEdge(9, 10);

	graf.print();
	int broj=0;
	while (broj != -1)
	{
		cin >> broj;
		cout << "\n\nBroj cvorova koji mogu da se obidju iz cvora " << broj << " je: " << graf.brojCvorova(broj) << endl;
	}
}

