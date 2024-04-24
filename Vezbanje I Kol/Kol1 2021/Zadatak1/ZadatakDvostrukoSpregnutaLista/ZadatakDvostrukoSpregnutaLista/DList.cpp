#include "DList.h"



DList::DList()
{
	head = NULL;
}


DList::~DList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

DListNode* DList::findNodePtr(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode *ret = head;
	while (ret != NULL && ret->info != el)
	{
		ret = ret->next;
	}
	return ret;
}

int DList::getHeadEl()
{
	if (isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int DList::getNextEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

int DList::getPreviousEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->prev == NULL)
		throw new exception("Element doesn't have previous node");
	return tmp->prev->info;
}

bool DList::isInList(int el)
{
	if (isEmpty())
		return false;
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		return false;
	else
		return true;
}

void DList::deleteEl(int el)
{
	if (!isEmpty())
		if (head->isEqual(el))
		{
			DListNode *tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		else
		{
			DListNode *tmp;
			for (tmp = head->next; tmp != NULL && !(tmp->isEqual(el)); tmp = tmp->next);

			/*tmp = head->next;
			while (tmp != NULL && !(tmp->isEqual(el)))
				tmp = tmp->next;*/


			if (tmp != NULL)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
		}
}

void DList::addToHead(int el)
{
	head = new DListNode(el, NULL, head);
	if(head->next!=NULL)
		head->next->prev = head;
}

void DList::addToTail(int el)
{
	if (!isEmpty())
	{
		DListNode* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new DListNode(el, tmp, NULL);
	}
	else
		addToHead(el);
}

int DList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	DListNode *tmp = head;
	head = head->next;
	if(head!=NULL)
		head->prev = NULL;
	delete tmp;
	return el;
}

int DList::deleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		return deleteFromHead();
	}
	else
	{
		DListNode *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		el = tmp->info;
		tmp->prev->next = NULL;
		delete tmp;
	}
	return el;
}

void DList::printAll()
{
	DListNode *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void DList::exchange(int a, int b)
{
	DListNode* ptr1=nullptr, *ptr2=nullptr;
	DListNode* pom = head;
	if (head == nullptr)
		throw "\n********Lista je prazna!!*********\n";

	while (pom != nullptr && (ptr1 == nullptr || ptr2 == nullptr))
	{
		if (pom->info == a)
			ptr1 = pom;
		else if (pom->info == b)
			ptr2 = pom;
		pom = pom->next;
	}
	if (ptr1 == nullptr || ptr2 == nullptr)
		throw "\n*******Elementi se ne nalaze u listi!*********\n";

	DListNode* prev1 = ptr1->prev;
	DListNode* next1 = ptr1->next;

	if (ptr1->prev == nullptr) //ptr1 je head
		head = ptr2;
	else
		ptr1->prev->next = ptr2;

	ptr1->next->prev = ptr2;
	ptr2->prev->next = ptr1;
	if (ptr2->next != nullptr)//ptr2 je tail
		ptr2->next->prev = ptr1;

	ptr1->next = ptr2->next;
	ptr1->prev = ptr2->prev;
	ptr2->next = next1;
	ptr2->prev = prev1;

	//i ovo isto radi lmao (u najboljem slucaju)
	/*ptr1->next = ptr2->next;
	ptr1->prev = ptr2->prev;
	prev1->next = ptr2;
	next1->prev = ptr2;

	ptr2->next->prev = ptr1;
	ptr2->prev->next = ptr1;
	ptr2->next = next1;
	ptr2->prev = prev1;*/


	//ptr1->next = ptr2->next; //sigurno dobro
	//ptr1->prev = ptr2->prev;
	//ptr2->next->prev = ptr1;
	//ptr2->prev->next = ptr1;
	//
	//ptr2->next = next1;
	//ptr2->prev = prev1;
	//next1->prev = ptr2;
	//prev1->next = ptr2;
	//if (prev1 == nullptr)
	//{
	//	ptr1->next->prev = ptr2;
	//	ptr2->next->prev = ptr1;
	//}


}