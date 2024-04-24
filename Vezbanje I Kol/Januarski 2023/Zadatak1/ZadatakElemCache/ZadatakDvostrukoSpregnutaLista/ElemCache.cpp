#include "ElemCache.h"


ElemCache::ElemCache()
{
	prev = NULL; next = NULL;
	key = 0;
}

ElemCache::ElemCache(int el)
{ 
	key = el; 
	prev = NULL; 
	next = NULL; 
}

ElemCache::ElemCache(int el, ElemCache *p, ElemCache *n)
{
	key = el;
	next = n; 
	prev = p;
}

ElemCache::~ElemCache()
{
	//delete prev;
	//delete next;

}
