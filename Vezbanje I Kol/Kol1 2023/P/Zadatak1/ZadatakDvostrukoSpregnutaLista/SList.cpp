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

void SList::swap(SListNode* p1, SListNode* p2)//preduslov da je p1 pre p2
{
	SListNode* pomPtr=head,*prev1,*prev2,*p1Next;
	while (pomPtr->next != p1)
		pomPtr = pomPtr->next;
	if (pomPtr->next == p1)
		prev1 = pomPtr;

	pomPtr = head;
	while (pomPtr->next != p2)
		pomPtr = pomPtr->next;
	if (pomPtr->next == p2)
		prev2 = pomPtr;
	
	p1Next = p1->next;

	p1->next = p2->next;
	prev2->next=p1;
	p2->next = p1Next;
	prev1->next = p2;


}

void SList::swapSusedne(int d1)//preduslov da je p1 pre p2
{
	SListNode* pomPtr = head;
	SListNode* p1=nullptr, * p2=nullptr;
	SListNode* p1Prev=nullptr, * p2Next=nullptr;

	if (head->info == d1)//ako treba prvi element da se zameni sa drugim
	{
		p1 = head;
		p2 = head->next;
		
		p1->next = p2->next;
		p2->next = p1;
		head = p2;

		return;
	}

	while (p1 == nullptr && pomPtr->next !=nullptr)
	{
		if (pomPtr->next->info == d1)
		{
			p1Prev = pomPtr;
			p1 = pomPtr->next;
			p2 = p1->next;
			//p2Next = p2->next;
		}
		pomPtr = pomPtr->next;
	}

	if (p1->next == nullptr) //p1 nema susednog elementa,pa ne moze da se vrsi zamena
		return;
	
	if (p2->next == nullptr)//p2 nema sledbenika,odnosno p2 je kraj liste
	{
		p1->next = nullptr;
		p2->next = p1;
		p1Prev->next = p2;
		return;
	}
	
	//p2 = p1->next;
	p2Next = p2->next;

	p1->next = p2Next;
	p2->next = p1;
	p1Prev->next = p2;

		
}

int SList::SwapPairs(int data1, int data2)
{
	//TODO:treba da dodam (nadjem) i prev1 i prev2,kao i ptr1Next.
	if (isEmpty()) //prazna lista
			return -1;
	//if (data1 > data2) //ne pise u zadatku ali sam i taj slucaj obradio
	//{
	//	int pom = data1;
	//	data1 = data2;
	//	data2 = pom;
	//}
	

	int brojPonavljanja=0;
	SListNode* ptr1=nullptr, * ptr2=nullptr, * pomPtr=head;
	bool pravilanRedosled = true;

	while ((ptr1 == nullptr || ptr2 == nullptr)&&pomPtr->next!=nullptr)
	{
		
		if (pomPtr->isEqual(data1))
		{
			ptr1 = pomPtr;
			if (ptr2 != nullptr)
				pravilanRedosled = false;
		}
		if (pomPtr->next->isEqual(data2))
			ptr2 = pomPtr;

		pomPtr = pomPtr->next;
	}
	if (ptr1 == nullptr) //ne postoji element sa data1
		return 0;

	//ne razumem da li misle da se menjaju cvorori od pocetka do kraja liste, ili od
	//data1 do kraja liste.Ja cu da uradim za drugi slucaj
	if (ptr2 == nullptr) //Ako ne postoji sledbenik poslednjeg cvora podliste (sa info delom data2)
		
	{
		SListNode* pomPtr = head;
		while (pomPtr->next->next != nullptr) //da bi se stiglo do predposlednjeg elementa 
			pomPtr = pomPtr->next;			  //(pomPtr->next!=nullptr) da bi se stiglo do poslednjeg elementa 

		//ptr1 = head;
		ptr2 = pomPtr;
	}

	if (!pravilanRedosled) //ako je data2 ispred data1 samo da se zamene
	{
		SListNode* pomPtr = ptr1;
		ptr1 = ptr2->next;
		ptr2 = pomPtr;
	}

	//odavde bi trebalo da su provereni svi granicni slucajevi,i da su
	//data 1 i data 2 u pravilnom redosledu.

	//pomPtr = ptr1;
	

	while (ptr1 != nullptr && ptr1->info!=data2 && ptr1->info!=ptr2->info) //while ((ptr1->info!=data2 && ptr1->info!=ptr2->info) && ptr1 != nullptr)
	{
		swapSusedne(ptr1->info);
		ptr1 = ptr1->next;
		brojPonavljanja++;
	}
	


	return brojPonavljanja;
}