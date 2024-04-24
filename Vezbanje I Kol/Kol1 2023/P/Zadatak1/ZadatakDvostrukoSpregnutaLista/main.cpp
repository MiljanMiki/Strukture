#include"SList.h"
#include <iostream>

void main() // VEOMA SKAPANO RESENJE ALI RADI!
{
	int dg, gg;

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

	cout << "Unesite vrednosti elemenata koji ce da budu granice:\n";
	cout << "Donja granica:\n";
	cin >> dg;
	cout << "\nGornja granica:\n";
	cin >> gg;

	int pom =list->SwapPairs(dg,gg); 

	cout << "\nIzgled liste nakon transformacije je:\n";
	list->printAll();
	cout << "\nBroj zamena:" << pom;

	delete list;

}