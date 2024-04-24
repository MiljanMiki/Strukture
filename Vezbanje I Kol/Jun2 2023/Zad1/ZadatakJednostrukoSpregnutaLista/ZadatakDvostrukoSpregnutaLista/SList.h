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

	int deleteFromHead();

	bool moveSectionToHead(int, int);

	void addToHead(int);

	void printAll();

};

