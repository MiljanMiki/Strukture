#include "Cache.h"

Cache::Cache()
{
	head =tail=nullptr;
	maxCnt = 0;
}

Cache::Cache(int c)
{
	head = tail=nullptr;
	maxCnt = c;
}

Cache::~Cache()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

int Cache::deleteFromHead()
{
	ElemCache* pom = head;
	int i = pom->key;

	//if(head->next!=nullptr)//ako ima vise od jednog elementa u listi
		//head->next->prev = nullptr;
	head = head->next;
	if(head!=nullptr)
		head->prev = nullptr;
	delete pom;
	count--;

	return i;
}

int Cache::deleteFromTail()
{
	ElemCache* pom = tail;
	int i = pom->key;
	if (head == tail)//ostao je samo 1 elemenat u listi
	{
		delete pom;
		count--;
		return i;
	}
	tail = tail->prev;
	tail->next = nullptr;
	delete pom;
	count--;
	return i;
}

void Cache::printAll()
{
	ElemCache* pomPtr=head;
	while (pomPtr!= nullptr && count>0)
	{
		cout << " "<<pomPtr->print();
		pomPtr = pomPtr->next;
	}
	if (count == 0)
		cout << "*****Lista je prazna!*****";
	cout << "\n";
}

void Cache::add(ElemCache* elem)
{
	if (isFull())
		deleteFromTail();
	elem->next = head;
	elem->prev = nullptr;
	head = elem;
	if (tail == nullptr)//ovo samo pri prvom dodavanju u listu
		tail = elem;
	if (head->next != nullptr)
		head->next->prev = head;
	count++;

}

void Cache::prebaciNaPocetak(ElemCache* elem)
{
	if (elem != head)
	{
		if (elem != tail)
		{
			elem->next->prev = elem->prev;
			elem->prev->next = elem->next;
		}
		else
		{
			tail->prev->next = nullptr;
		}

		elem->prev = nullptr;
		elem->next = head;
		head->prev = elem;
		head = elem;
	}

}

ElemCache* Cache::get(int key)
{
	ElemCache* pom = head;

	while (pom != nullptr && pom->key != key)
	{
		pom = pom->next;
	}
	if (pom == nullptr)
		throw "\n***********************Elemenat se ne nalazi u listi sa takvim kljucem!!!********************\n";

	if (pom->key == key)
	{
		prebaciNaPocetak(pom);
		return pom;
	}
	else
		throw "\n***********************Elemenat se ne nalazi u listi sa takvim kljucem!!!********************\n";
		
}


