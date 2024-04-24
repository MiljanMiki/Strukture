#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(32);
	ChainedScatterObject o1("2504003730048","1001","073","25/04/2024",2);
	ChainedScatterObject o2("0110003841234", "7012", "074", "25/04/2024", 2);
	ChainedScatterObject o3("0702004731240", "0071", "100", "21/07/2023", 5);
	ChainedScatterObject o4("1203992741200", "0001", "999", "02/12/2020", 1);
	ChainedScatterObject o5("1212000341777", "0123", "005", "01/07/2016", 2);

	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o3);
	tablica.insert(o3);
	tablica.insert(o3);
	tablica.insert(o4);
	tablica.insert(o4);
	tablica.insert(o5);
	tablica.insert(o5);
	tablica.print();

	ChainedScatterObject randomNiz[1];
	int* p;
	int n=1;
	p = &n;
	try {
		auto pomNiz = tablica.vratiSveKarte("2504003730049", randomNiz, p);

		for (int i = 0; i < *p; i++)
			pomNiz[i].print();
	}
	catch (const char* e)
	{
		cout << e;
	}

}