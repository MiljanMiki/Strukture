#pragma once
#include"ElemCache.h"
class Cache
{
protected:
	ElemCache *head,*tail;
	int maxCnt;
	int count = 0;
public:
	Cache();
	Cache(int);
	~Cache();

	bool isEmpty() { return head == nullptr || count==0; }
	bool isFull() { return count >= maxCnt; };
	int deleteFromHead();
	void printAll();

	int deleteFromTail();

	void prebaciNaPocetak(ElemCache*);

	void add(ElemCache* elem);

	ElemCache* get(int key);

};

