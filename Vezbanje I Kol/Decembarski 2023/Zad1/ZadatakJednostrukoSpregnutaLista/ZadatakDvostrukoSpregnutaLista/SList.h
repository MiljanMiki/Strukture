#pragma once
#include"SListNode.h"
class SList
{
protected:
	SListNode *head;
public:
	SList();
	~SList();

	inline bool isEmpty() { return head == NULL; }

	void addToHead(int el);

	int deleteFromHead();

	bool reverseOrder(int first, int last);

	void printAll();

};

