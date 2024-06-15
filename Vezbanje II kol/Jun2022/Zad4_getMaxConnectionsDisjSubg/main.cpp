#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	graf.insertNode(1); graf.insertNode(2); graf.insertNode(3); graf.insertNode(4);
	graf.insertNode(5); graf.insertNode(6); graf.insertNode(7); graf.insertNode(8);
	graf.insertNode(9); graf.insertNode(10);

	//graf.insertEdge(1, 4);
	graf.insertEdge(2, 4);
	graf.insertEdge(3, 4);
	graf.insertEdge(2, 3);

	graf.insertEdge(5, 6);

	graf.insertEdge(8, 7);
	graf.insertEdge(8, 9);
	graf.insertEdge(7, 9);

	graf.toUndirected();

	GraphAsListsInt graf3;

	graf3.insertNode(1); graf3.insertNode(2); graf3.insertNode(3); graf3.insertNode(4);
	graf3.insertNode(5); graf3.insertNode(6); graf3.insertNode(7); graf3.insertNode(8);

	graf3.insertEdge(1, 2);
	graf3.insertEdge(1, 4);
	graf3.insertEdge(2, 3);
	graf3.insertEdge(2, 4);
	graf3.insertEdge(3, 1);
	graf3.insertEdge(4, 5);
	graf3.insertEdge(4, 6);
	graf3.insertEdge(5, 7);
	graf3.insertEdge(6, 2);
	graf3.insertEdge(6, 5);
	graf3.insertEdge(6, 7);
	graf3.insertEdge(7, 8);

	graf3.toUndirected();
	//izbacuje dobro i ako se prosledi povezan graf
	cout << "Najveci broj grana nekog podgrafa ovog grafa je: " << graf.getMaxConnectionsDisjointSubgraph();
}

