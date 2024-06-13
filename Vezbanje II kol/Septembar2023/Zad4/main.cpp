#include <iostream>
using namespace std;

#include "GraphAsListsInt.h"

int main(int argc, char* argv[]) 
{

	GraphAsListsInt graf;

	graf.insertNode(1,true); graf.insertNode(2,false); graf.insertNode(3,true); graf.insertNode(4,false);
	graf.insertNode(5,true); graf.insertNode(6,false); graf.insertNode(7,false); graf.insertNode(8,false);

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
	graf.insertEdge(8, 6);

	graf.toUndirected();
	graf.print();

	//ovaj majmun uvek krece iz iste sobe tj u ovom slucaju iz 8.
	//nista ne pise u zad odakle treba krece, tako da je to to...
	cout << "Soba u kojoj ce na kraju zavrsiti je:" << endl;
	LinkedNodeInt* ptr=	graf.findNode(16);
	if (ptr != nullptr)
		ptr->visit();
	else
		cout << "U nijednoj! x(";
}

