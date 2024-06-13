#pragma once

#include "LinkedEdgeInt.h"

class LinkedNodeInt
{
public:
	int node;
	LinkedEdgeInt* adj;
	LinkedNodeInt* next;
	int status;
	bool mracnaSoba=false;//true - mracna soba | false - svetla soba

	LinkedNodeInt();
	LinkedNodeInt(int nodeN);
	LinkedNodeInt(int nodeN,bool mracna);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN,bool mracna);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN);

	void visit();
};
