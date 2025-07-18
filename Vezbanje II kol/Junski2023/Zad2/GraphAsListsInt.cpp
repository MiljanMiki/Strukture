#include "GraphAsListsInt.h"

#include <iostream>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

GraphAsListsInt::GraphAsListsInt() : start(nullptr), nodeNum()
{
}

GraphAsListsInt::~GraphAsListsInt()
{
}

LinkedNodeInt* GraphAsListsInt::findNode(const int& data) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data)
		ptr = ptr->next;
	return ptr;
}

LinkedEdgeInt* GraphAsListsInt::findEdge(const int& dataSrc, const int& dataDest) const
{
	LinkedNodeInt* ptr = findNode(dataSrc);
	if (ptr == nullptr)
		return nullptr;
	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest)
		pEdge = pEdge->link;
	return pEdge;
}

void GraphAsListsInt::insertNode(const int& data)
{
	start = new LinkedNodeInt(data, nullptr, start);
	nodeNum++;
}

bool GraphAsListsInt::insertEdge(const int& dataSrc, const int& dataDest, const double& weight /*= 0*/)
{
	LinkedNodeInt* pSrc = nullptr;
	LinkedNodeInt* pDest = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && (pSrc == nullptr || pDest == nullptr)) //ili samo da se zameni sa findNode(dataSrc),(dataDest)
	{
		if (ptr->node == dataSrc) {
			pSrc = ptr;
		}
		else if (ptr->node == dataDest) {
			pDest = ptr;
		}
		ptr = ptr->next;
	}
	if (pSrc == nullptr || pDest == nullptr)
		return false;
	pSrc->adj = new LinkedEdgeInt(pDest, pSrc->adj);
	return true;
}

bool GraphAsListsInt::deleteEdge(const int& dataSrc, const int& dataDest)
{
	LinkedNodeInt* pSrc = findNode(dataSrc);
	if (pSrc == nullptr)
		return false;

	LinkedEdgeInt* pEdgePrev = nullptr;
	LinkedEdgeInt* pEdge = pSrc->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest) {
		pEdgePrev = pEdge;
		pEdge = pEdge->link;
	}
	if (pEdge == nullptr)
		return false;

	if (pEdgePrev == nullptr)
		pSrc->adj = pEdge->link;
	else
		pEdgePrev->link = pEdge->link;

	delete pEdge;

	return true;
}

void GraphAsListsInt::deleteEdgeToNode(const LinkedNodeInt* pDest)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdgePrev = nullptr;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr && pEdge->dest != pDest) {
			pEdgePrev = pEdge;
			pEdge = pEdge->link;
		}
		if (pEdge != nullptr)
		{
			if (pEdgePrev == nullptr)
				ptr->adj = pEdge->link;
			else
				pEdgePrev->link = pEdge->link; //gde je delete pEdge? stupid nigger... (ustvari vrv i ovo radi,jer onda pEdge vise nije povezan u listi pa svakako necemo da ga dobijemo
											  //,ali sto bi drzao memorijski prostor bezveze zauzetim?
				//delete pEdge
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::deleteNode(const int& data)
{
	LinkedNodeInt* prev = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data) //findNode... (PA NE MOZE FINDNODE MAJMUNE JER TI TREBA PREV!)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == nullptr)
		return false;

	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr)//brisu se sve grane cvora koji se brise
	{
		LinkedEdgeInt* pEdgeTmp = pEdge->link;
		delete pEdge;
		pEdge = pEdgeTmp;
	}
	ptr->adj = nullptr;//bitno!!!!

	deleteEdgeToNode(ptr);//brise sve grane koje ukazuju na cvor ptr

	if (prev == nullptr)
		start = start->next;
	else
		prev->next = ptr->next;

	delete ptr;
	nodeNum--;

	return true;
}

void GraphAsListsInt::print() const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		cout << ptr->node << " -> ";
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			cout << pEdge->dest->node << " | ";
			pEdge = pEdge->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}

void GraphAsListsInt::setStatusForAllNodes(int status) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = status;
		ptr = ptr->next;
	}
}

long GraphAsListsInt::breadthFirstTraversal(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(ptr);
	ptr->status = 2;
	while (!queue.isEmpty()) 
	{
		ptr = queue.dequeue();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				queue.enqueue(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalIterative(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(ptr);
	ptr->status = 2;
	while (!stack.isEmpty()) {
		ptr = stack.pop();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				stack.push(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(LinkedNodeInt* ptr) const
{
	int retVal = 0;
	if (ptr->status != 1)
	{
		ptr->visit();
		ptr->status = 1; // 1? zar ne bi trebalo 3? - nope posto je ovo rekurzivno, ili je 0- neobidjen ili 1- obidjen
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			retVal += depthFirstTraversalRecursive(pEdge->dest);
			pEdge = pEdge->link;
		}
		retVal++;
	}
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(const int& data) const
{
	LinkedNodeInt* pNode = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 0;
		if (ptr->node == data) {
			pNode = ptr;
		}
		ptr = ptr->next;
	}

	if (pNode == nullptr)
		return 0;

	return depthFirstTraversalRecursive(pNode);
}

long GraphAsListsInt::topologicalOrderTravrsal() const
{
	int retVal = 0;

	setStatusForAllNodes(0);

	LinkedNodeInt* ptr = start; //status je ovde broj cvorova koji ukazuje na zadati cvor (ovaj kod je vrv za orijentisan graf?)
	while (ptr != nullptr) {
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status += 1;
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	ptr = start;
	while (ptr != nullptr) {
		if (ptr->status == 0)
			queue.enqueue(ptr);
		ptr = ptr->next;
	}

	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status--;
			if (pEdge->dest->status == 0)
				queue.enqueue(pEdge->dest);
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}


void GraphAsListsInt::toUndirected()
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr)
		{
			if (findEdge(pEdge->dest->node, ptr->node) == nullptr)
				insertEdge(pEdge->dest->node, ptr->node);
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}
}

void GraphAsListsInt::connectMaxAndMin()
{
	LinkedNodeInt* ptr = start;

	StackAsArrayLinkedNodeInt stack(nodeNum);
	setStatusForAllNodes(1);//mislim da je dovoljno samo 1-2, ne treba mi 3

	int brojCvorovaNajvecegGrafa = -1;
	LinkedNodeInt* cvorNajvecegGrafa = nullptr;
	LinkedNodeInt* cvorNajmanjegGrafa = nullptr;
	int brojCvorovaNajmanjegGrafa = 9999999999999;

	while (ptr != nullptr)
	{
		if (ptr->status == 1)
		{
			stack.push(ptr);
			ptr->status = 2;
			int count = 1;

			while (!stack.isEmpty())
			{
				LinkedNodeInt* pom = stack.pop();
				LinkedEdgeInt* pEdge = pom->adj;
				while (pEdge != nullptr)
				{
					if (pEdge->dest->status == 1)
					{
						stack.push(pEdge->dest);
						pEdge->dest->status = 2;
						count++;
					}
					pEdge = pEdge->link;
				}

			}
			//ne nalazi mi korektno min/max podgraf
			//npr ako prvi koji se preradjuje je cvor 10,on ce
			//biti sracunat kao najveci,pa ce zatim biti smenjen
			//mozda da se doda u ovaj neki if ispod da ako cvorNajvecegGrafa!=nullptr,
			//da se odradi ispitivanje da li je mozda najmanji?
			if (count > brojCvorovaNajvecegGrafa)
			{
				brojCvorovaNajvecegGrafa = count;
				cvorNajvecegGrafa = ptr;
			}
			if (count < brojCvorovaNajmanjegGrafa) //bukvalno je samo trebalo da se stavi if umesto else if :D...
			{									   //mada imam neki osecaj da bi se ovo sjebalo u neki edge case
				brojCvorovaNajmanjegGrafa = count;
				cvorNajmanjegGrafa = ptr;
			}

		}

		ptr = ptr->next;
	}
	//samo uslova provere najveceg/najmanejg podgrafa moze se desiti da su jednaki cvorovi (znak da je graf povezan)
	if (cvorNajmanjegGrafa != nullptr && cvorNajvecegGrafa != nullptr && cvorNajmanjegGrafa!=cvorNajvecegGrafa)
	{
		insertEdge(cvorNajmanjegGrafa->node, cvorNajvecegGrafa->node);
		insertEdge(cvorNajvecegGrafa->node, cvorNajmanjegGrafa->node);
	}
	else
		throw "OOpsie!";

}
