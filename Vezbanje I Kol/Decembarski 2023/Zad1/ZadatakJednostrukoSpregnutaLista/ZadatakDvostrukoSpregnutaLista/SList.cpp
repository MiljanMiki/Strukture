#include "SList.h"

SList::SList()
{
	head = NULL;
}

SList::~SList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

void SList::addToHead(int el)
{
	head = new SListNode(el,head);
}

int SList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	SListNode* tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

bool SList::reverseOrder(int first, int last)
{
	SListNode* p1 = nullptr, * p2 = nullptr;
	SListNode* prev1 = nullptr, * next2 = nullptr;
	SListNode* pom = head;
	if (head->info == first)
		p1 = head;

	while (pom->next != nullptr && (p1==nullptr ||p2==nullptr))
	{
		if (pom->next->info == first)
		{
			prev1 = pom;
			p1 = pom->next;
			if (p2 != nullptr)
				return false;
		}
		else if (pom->next->info == last)
		{
			p2 = pom->next;
			next2 = pom->next->next;
		}
		pom = pom->next;
	}
	if (p1 == nullptr || p2 == nullptr) //first ili last ne postoje
		return false;
	//if (next2 == nullptr) za ovo me ustvari nije briga,to samo znaci da je ptr2 bio tail

	pom = p1;
	unsigned int brojElemenata = 0;
	while (pom != next2)
	{
		brojElemenata++;
		pom = pom->next;
	}
	
	pom = p1;
	SListNode** niz = new SListNode * [brojElemenata];
	for (int i = 0; i < brojElemenata; i++)
	{
		niz[i] = pom;
		pom = pom->next;
	}
	for (int i = brojElemenata - 1; i >0; i--)
	{
		niz[i]->next = niz[i - 1];
	}
	niz[0]->next = next2;
	if (prev1 == nullptr)//p1 je ustvari head
		head = niz[brojElemenata - 1];
	else
		prev1->next = niz[brojElemenata-1];

	return true;
}

void SList::printAll()
{
	SListNode *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

