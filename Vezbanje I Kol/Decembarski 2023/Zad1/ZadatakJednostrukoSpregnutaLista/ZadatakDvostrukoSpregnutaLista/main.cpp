#include"SList.h"
#include <iostream>

void main() 
{
	SList* list = new SList();
	try {
		
		list->addToHead(0);
		list->addToHead(9);
		list->addToHead(8);
		list->addToHead(7);
		list->addToHead(6);
		list->addToHead(5);
		list->addToHead(4);
		list->addToHead(3);
		list->addToHead(2);
		list->addToHead(1);

		list->printAll();

		cout<<list->reverseOrder(3,7)<<endl;

		list->printAll();
	}
	catch (const char* e)
	{
		cout << e;
	}

	delete list;
}