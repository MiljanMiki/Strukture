#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	int next; //-1: nema sledeceg,  0: kraj lrmp
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(int i, char* ime, char* prez, int godU): ScatterObject(i,ime,prez,godU) { next = -1; }
	ChainedScatterObject(int i, char* ime, char* prez, int godU, int n) : ScatterObject(i,ime,prez,godU) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print() ;
};

