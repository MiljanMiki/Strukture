#include"Cache.h"
#include <iostream>

void main()
{
	Cache *list = new Cache(5);
	try 
	{
		list->add(new ElemCache(6));
		list->add(new ElemCache(1));
		list->add(new ElemCache(2));
		list->printAll();

		list->deleteFromTail();
		list->deleteFromTail();
		list->deleteFromTail();

		list->printAll();

	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	

	delete list;

}