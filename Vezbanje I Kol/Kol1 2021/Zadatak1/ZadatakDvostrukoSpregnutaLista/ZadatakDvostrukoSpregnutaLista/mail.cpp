#include"DList.h"
#include <iostream>

void main()
{
	DList *list = new DList();
	list->addToHead(8);
	list->addToHead(2);
	list->addToHead(1);
	list->addToHead(9);
	list->addToHead(7);
	list->addToHead(5);
	list->addToHead(3);

	list->printAll();

	try
	{
		list->exchange(3,8);
	}
	catch (const char* e)
	{
		cout << e;
	}
	list->printAll();


	delete list;


}