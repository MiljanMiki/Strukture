#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	int next; //-1: nema sledeceg,  0: kraj lrmp
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(char* k, char* bK, char* bS, char* dat, unsigned int bV): ScatterObject(k,bK,bS,dat,bV) { next = -1; }
	ChainedScatterObject(char* k, char* bK, char* bS, char* dat, unsigned int bV, int n) : ScatterObject(k,bK,bS,dat,bV) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

