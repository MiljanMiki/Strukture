#include"SList.h"
#include <iostream>

void main() 
{
	SList *list = new SList();
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

	cout<<list->moveSectionToHead(6,3)<<endl;
	list->printAll();

	delete list;
}