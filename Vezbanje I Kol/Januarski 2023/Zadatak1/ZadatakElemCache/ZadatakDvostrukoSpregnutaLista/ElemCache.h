#pragma once
#include <iostream>
using namespace std;
class ElemCache
{
public:
	int key;
	ElemCache *next, *prev;

	ElemCache();
	ElemCache(int el);
	ElemCache(int el, ElemCache *p, ElemCache *n);
	~ElemCache();

	int print() { return key; }
	bool isEqual(int el) { return el == key; }

};

