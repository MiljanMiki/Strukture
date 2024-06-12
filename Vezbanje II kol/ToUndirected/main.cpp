#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{
	//video sam na blanketima da se generalno trazi
	//da treba PRVO da se pretvori graf u neorijentisani
	//pa da se zatim na neorijentisanom grafu vrsi
	//f-ja koja se trazi u zadatku

	GraphAsListsInt graf;
	graf.insertNode(1); graf.insertNode(2); graf.insertNode(3);
	graf.insertNode(4); graf.insertNode(5); 

	graf.insertEdge(1, 2);
	graf.insertEdge(1, 4);
	graf.insertEdge(2, 4);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 1);
	graf.insertEdge(4,5);
	graf.insertEdge(5,2);

	graf.print();

	cout << "Nakon sto je graf postao neorijentisan:" << endl;
	graf.toUndirected();
	graf.print();



}

