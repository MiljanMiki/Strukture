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

	graf.print();

	cout<<"\n\n Broj istih aerodroma izmedju putanja je:"<<graf.numOfSameFlights(1, 8, 6);

}

