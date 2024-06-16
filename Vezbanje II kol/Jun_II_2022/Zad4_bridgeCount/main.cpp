#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	graf.insertNode(1); graf.insertNode(2); graf.insertNode(3); graf.insertNode(4);
	graf.insertNode(5); graf.insertNode(6); graf.insertNode(7); graf.insertNode(8);

	graf.insertEdge(1, 2);
	graf.insertEdge(1, 4);
	graf.insertEdge(2, 3);
	graf.insertEdge(2, 4);
	graf.insertEdge(3, 1);
	graf.insertEdge(4, 5);
	graf.insertEdge(4, 6);
	graf.insertEdge(5, 7);
	graf.insertEdge(6, 2);
	graf.insertEdge(6, 5);
	graf.insertEdge(6, 7);
	graf.insertEdge(7, 8);

	graf.toUndirected();

	//graf.print();

	GraphAsListsInt graf2;

	/*graf2.insertNode(1);
	graf2.insertNode(2);
	graf2.insertNode(3);
	graf2.insertNode(4);
	graf2.insertNode(5);
	graf2.insertNode(6);

	graf2.insertEdge(1, 2);
	graf2.insertEdge(1, 5);
	graf2.insertEdge(1, 6);
	graf2.insertEdge(2,3);
	graf2.insertEdge(3,4);
	graf2.insertEdge(4,5);
	graf2.insertEdge(6,4);

	graf2.toUndirected();*/

	cout << "Minimalan broj mostova koji mora da se obidje je:" << graf.bridgeCount(3,8);



}

