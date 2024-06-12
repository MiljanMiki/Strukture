#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	graf.insertNode(1); graf.insertNode(2); graf.insertNode(3); graf.insertNode(4);
	graf.insertNode(5); graf.insertNode(6); graf.insertNode(7); graf.insertNode(8);
	graf.insertNode(9); graf.insertNode(10);

	graf.insertEdge(1,4);
	graf.insertEdge(2,4);
	graf.insertEdge(3,4);
	graf.insertEdge(2,3);

	graf.insertEdge(5,6);

	graf.insertEdge(8,7);
	graf.insertEdge(8,9);
	graf.insertEdge(7,9);


	graf.toUndirected();
	int p;
	cin >> p;
	cout << "Broj disjunktnih podgrafova koji imaju barem jedan cvor veci od "<<p <<" je:\n"<< graf.subgraphCnt(p);
}

