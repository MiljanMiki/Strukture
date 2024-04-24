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

	void printAll();

	void swap(SListNode*, SListNode*);

	void swapSusedne(int d1);

	int SwapPairs(int data1, int data2);
	

};

