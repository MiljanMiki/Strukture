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

	/*graf.insertEdge(1, 2);
	graf.insertEdge(1, 5);
	graf.insertEdge(1, 6);
	graf.insertEdge(2,3);
	graf.insertEdge(3,4);
	graf.insertEdge(4,5);
	graf.insertEdge(6,4);*/

	graf.insertEdge(1,2);
	graf.insertEdge(2,3);
	graf.insertEdge(4,5);
	graf.insertEdge(5,6);

	graf.toUndirected();
	
	//ako su na ovo jebano mislili onda je to to
	//tezi deo bi mozda bio da se napravi ova toUndirected() f-ja,nzm da li
	//daju ostale metode klase
	cout << graf.doesConnectedComponentExist(2);

}

