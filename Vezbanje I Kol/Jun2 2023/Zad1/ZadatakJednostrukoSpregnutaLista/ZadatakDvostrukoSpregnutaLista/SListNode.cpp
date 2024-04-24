#include "SListNode.h"


SListNode::SListNode()
{
	info = 0;
	next = NULL;
}

SListNode::SListNode(int el)
{ 
	info = el; 
	next = NULL; 
}

SListNode::SListNode(int el,SListNode *n)
{
	info = el;
	next = n; 
}

SListNode::~SListNode()
{
}
