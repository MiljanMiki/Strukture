#include"OpenScatterTable.h"

void main()
{
	OpenScatterTable tablica(120); //velicina tablice bi trebala da bude 12000 but fuck that
	ScatterObject o("2504003730048",19105,"Miljan","Dragovic",2022,8.50);
	ScatterObject o1("2203003735215",19111,"Jovana","Djordjevic",2022,8.33);
	ScatterObject o2("0110003815123",19107,"Katarina","Ducic",2022,8.50);
	ScatterObject o3("2505004731146",19102,"Nemanja","Dinic",2022,9.15);
	ScatterObject o4("1606994737171",1677,"Isidora","Dragovic",2013,9.0);
	ScatterObject o5("1681995132190",14321,"Asznee","Cajkovski",2021,7.0);
	ScatterObject o6("0602004730002",16666,"Vladimir","Jovanovic",2022,9.25);

	try
	{
		tablica.insert(o);
		tablica.insert(o);
		tablica.insert(o);
		tablica.insert(o1);
		tablica.insert(o1);
		tablica.insert(o1);
		tablica.insert(o2);
		tablica.insert(o2);
		tablica.insert(o2);
		tablica.insert(o3);
		tablica.insert(o3);
		tablica.insert(o3);
		tablica.insert(o3);
		tablica.insert(o3);
		tablica.insert(o4);
		tablica.insert(o4);
		tablica.insert(o4);
		tablica.insert(o4);
		tablica.insert(o4);
		tablica.insert(o4);
		tablica.insert(o5);
		tablica.insert(o5);
		tablica.insert(o5);
		tablica.insert(o5);
		tablica.insert(o6);
		tablica.insert(o6);
		tablica.insert(o6);
		tablica.print();
		cout << "\n\n";

		float pomocniNiz[3];
		tablica.find("2504003730048", pomocniNiz);
		for (int i = 0; i < 3; i++)
			cout<<" "<<pomocniNiz[i];
		cout << "\n\n";
		tablica.find("2203003735215", pomocniNiz);
		for (int i = 0; i < 3; i++)
			cout << " " << pomocniNiz[i];
	}
	catch (const char* e)
	{
		std::cout << e;
	}
}