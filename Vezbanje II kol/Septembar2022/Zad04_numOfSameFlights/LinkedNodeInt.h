#pragma once

#include "LinkedEdgeInt.h"

class LinkedNodeInt
{
public:
	int node;
	LinkedEdgeInt* adj;
	LinkedNodeInt* next;
	LinkedNodeInt* prev;
	int status;

	LinkedNodeInt();
	LinkedNodeInt(int nodeN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN);

	void visit();
};
