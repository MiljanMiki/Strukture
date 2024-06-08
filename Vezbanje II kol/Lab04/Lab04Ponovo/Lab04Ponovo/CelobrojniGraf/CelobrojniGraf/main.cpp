#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	graf.insertNode(1);
	graf.insertNode(2);
	graf.insertNode(3);
	graf.insertNode(4);
	graf.insertNode(5);

	graf.insertEdge(1,2);
	graf.insertEdge(1,3);
	graf.insertEdge(2,5);
	graf.insertEdge(3,2);
	graf.insertEdge(3,5);
	graf.insertEdge(4,2);
	graf.insertEdge(4,5);
	graf.insertEdge(5,1);
	graf.insertEdge(5,4);

	graf.breadthFirstTraversal(1);

	cout << "\nIzgled putanje od cvora 1->5 bez grane 2->5 je:\n";
	graf.pathWithoutEdge(1, 5, 2, 5);

}

