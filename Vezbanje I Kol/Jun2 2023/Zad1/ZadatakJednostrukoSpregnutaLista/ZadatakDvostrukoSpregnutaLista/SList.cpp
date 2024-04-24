#include "SList.h"

SList::SList()
{
	head = nullptr;
}

SList::~SList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

int SList::deleteFromHead()
{
	int i = head->info;
	SListNode* pom = head;
	if(head!=nullptr)
		head = head->next;
	delete pom;

	return i;
}

bool SList::moveSectionToHead(int data1, int data2)
{
	if (data2 < data1)//forsira da data1<data2, tj da bude pravilan unos podataka
					  // ako se unese (6,3) umesto (3,6),pravilno ce ga zameniti.Ne pise u zadatku
					  //da treba da se sekiramo oko tog ogranicenja ali ja sam se nasekiro
	{
		int pom = data1;
		data1 = data2;
		data2 = pom;
	}
	SListNode* ptr1 = nullptr, * ptr2 = nullptr;
	SListNode* prev1 = nullptr;
	SListNode* pom = head,*prev=nullptr;

	if (!isEmpty())
	{
		while (pom->next != nullptr)
		{
			if (pom->next->info == data1)
			{
				prev1 = pom;
				ptr1 = pom->next;
			}
			else if (pom->next->info == data2)
				ptr2 = pom->next;

			pom = pom->next;
		}
	}
	else
		return false;
	
	if (ptr1 == nullptr || ptr2 == nullptr) // data1/2 ne postoje u ll
		return false;
	if (prev1 == nullptr) //to znaci da je ptr1==head,sto znaci da nema smisla da se vrsi zamena
		return false;
	
	prev1->next = ptr2->next;
	ptr2->next = head;
	head = ptr1;


	return true;
}

void SList::addToHead(int info)
{
	head = new SListNode(info, head);
}

void SList::printAll()
{
	SListNode* pom = head;
	while (pom != nullptr)
	{
		cout << " "<<pom->print();
		pom = pom->next;
	}
	cout << "\n";

}

