#pragma once
#include <iostream>
using namespace std;
class SListNode
{
public:
	int info;
	SListNode* next;

	SListNode();
	SListNode(int el);
	SListNode(int el,SListNode *n);
	~SListNode();

	int print() { return info; }
	bool isEqual(int el) { return el == info; }

};

