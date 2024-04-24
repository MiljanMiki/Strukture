#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(32);//bilo je 64
	try
	{
		ChainedScatterObject o("www.google.com");
		ChainedScatterObject o1("www.elfak.ni.ac.rs");
		ChainedScatterObject o2("www.redtube.com");
		ChainedScatterObject o3("www.asdfmovie3.com");
		tablica.insert(o);
		tablica.insert(o1);
		tablica.insert(o1);
		tablica.insert(o2);
		tablica.insert(o3);
		tablica.insert(o3);
		tablica.insert(o2);
		tablica.insert(o1);
		tablica.insert(o1);
		tablica.insert(o1);

		tablica.print();

		if (tablica.deleteObject("asdf123"))
			cout << "\nObjektat obrisan\n";
		//tablica.deleteObject("www.elfak.ni.ac.rs");
		//tablica.deleteObject("www.elfak.ni.ac.rs");
	}
	catch (const char* e)
	{
		cout << e;
	}
	
}