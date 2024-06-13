#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt graf;

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

	graf2.insertEdge(1,2);
	graf2.insertEdge(2,3);
	graf2.insertEdge(4,5);
	graf2.insertEdge(5,6);*/

	graf.insertNode(1); graf.insertNode(2); graf.insertNode(3); graf.insertNode(4);
	graf.insertNode(5); graf.insertNode(6); graf.insertNode(7); graf.insertNode(8);
	graf.insertNode(9); graf.insertNode(10);

	graf.insertEdge(1, 4);
	graf.insertEdge(2, 4);
	graf.insertEdge(3, 4);
	graf.insertEdge(2, 3);

	graf.insertEdge(5, 6);

	graf.insertEdge(8, 7);
	graf.insertEdge(8, 9);
	graf.insertEdge(7, 9);

	graf.toUndirected();
	
	//ako su na ovo jebano mislili onda je to to
	//tezi deo bi mozda bio da se napravi ova toUndirected() f-ja,nzm da li
	//daju ostale metode klase

	int i;
	cin >> i;
	cout <<"Da li postoji podgraf koji je duzi od "<<i<<"? Odgovor je(1-da, 0-ne):\n"<< graf.doesConnectedComponentExist(i);

}

