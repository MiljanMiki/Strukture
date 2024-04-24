#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(32);
	ChainedScatterObject o1(19105,"Miljan","Dragovic",2022);
	ChainedScatterObject o5(18106,"Zli","Shilangs",1643);
	ChainedScatterObject o2(19342,"Jovan","Todorov",2021);
	ChainedScatterObject o3(18405,"Todor","Jovanovic",2016);
	ChainedScatterObject o4(8124,"Vladimir","Harkonnen",2004);
	tablica.enlist(o1);
	tablica.enlist(o2);
	tablica.enlist(o3);
	tablica.enlist(o4);
	tablica.enlist(o5);

	/*tablica.insert(o3);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.insert(o3);
	tablica.insert(o3);
	tablica.insert(o4);
	tablica.insert(o4);
	tablica.insert(o4);*/
	tablica.print();
	cout << "Da li je " << o3.getKey() << " upisao kolokvijum?\n" << tablica.hasEnlisted(o5.getKey());
}