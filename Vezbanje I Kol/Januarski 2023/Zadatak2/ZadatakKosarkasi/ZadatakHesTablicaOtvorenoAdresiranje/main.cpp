#include"OpenScatterTable.h"

void main()
{
	OpenScatterTable kamp(32);

	ScatterObject kosarkas1(16, "Nikola", "Jokic", 1992, 44);
	ScatterObject kosarkas5(1, "Nikola", "Jokic", 1992, 44);
	ScatterObject kosarkas6(14, "Nikola", "Jokic", 1992, 44);
	ScatterObject kosarkas7(13, "Nikola", "Jokic", 1992, 44);
	ScatterObject kosarkas2(12, "Asznee", "Hotman", 1972, 14);
	ScatterObject kosarkas3(7, "Ronaldo", "Kristijan", 1988, 7);
	ScatterObject kosarkas4(11, "Messi", "Dragovic", 1990, 15);

	cout<<kamp.signUp(kosarkas1)<<endl;
	cout<<kamp.signUp(kosarkas2)<<endl;
	cout<<kamp.signUp(kosarkas2)<<endl;
	cout<<kamp.signUp(kosarkas3)<<endl;
	cout<<kamp.signUp(kosarkas4)<<endl;
	cout<<kamp.signUp(kosarkas5)<<endl;
	cout<<kamp.signUp(kosarkas6)<<endl;
	cout<<kamp.signUp(kosarkas7)<<endl;

	kamp.print();

	cout << kamp.countPlayersBornIn(1992);
	



}