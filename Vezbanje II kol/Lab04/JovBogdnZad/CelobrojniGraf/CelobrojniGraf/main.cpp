#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

	/*
	1------------------>5
	| \					^				
	|   \				|
	|    \				|
	|     \				|
	2      6			|
	 \      \			|
	  \      \			|
	   \      \			|
	    \      \		|
		 3----->4-------|
	*/

	//tipa za ovaj primer sve radi normalno
	/*graf.insertNode(1); graf.insertNode(5); graf.insertNode(2);
	graf.insertNode(3);	graf.insertNode(4); graf.insertNode(6);

	graf.insertEdge(1, 5);
	graf.insertEdge(1, 2);
	graf.insertEdge(1, 6);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 4);
	graf.insertEdge(4, 5);
	graf.insertEdge(6, 4);*/

	
	//za ovo mi vec ne radi (ponovo ne stampa kako valja...)
	graf.insertNode(1); graf.insertNode(2); graf.insertNode(3); graf.insertNode(4);
	graf.insertNode(5); graf.insertNode(6); graf.insertNode(7); graf.insertNode(8);

	//ali sve u svemu veoma pametno resenje i elegantno
	graf.insertEdge(1, 2);
	graf.insertEdge(1, 4); //puca kada se izbrise ova grana
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
	

	//graf.print();
	graf.pathThroughNode(6,4,1);
}

