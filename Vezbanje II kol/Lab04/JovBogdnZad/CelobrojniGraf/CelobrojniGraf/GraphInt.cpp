#include "GraphInt.h"

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
	while (ptr != nullptr && (pSrc == nullptr || pDest == nullptr)) {
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
				pEdgePrev->link = pEdge->link;
			//delete pEdge
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::deleteNode(const int& data)
{
	LinkedNodeInt* prev = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data) {
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == nullptr)
		return false;

	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr) {
		LinkedEdgeInt* pEdgeTmp = pEdge->link;
		delete pEdge;
		pEdge = pEdgeTmp;
	}
	ptr->adj = nullptr;

	deleteEdgeToNode(ptr);

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
	while (!queue.isEmpty()) {
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
	if (ptr->status != 1) {
		ptr->visit();
		ptr->status = 1;
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

	LinkedNodeInt* ptr = start;
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

// TODO: Realizovati metod koji odredjuje i prikazuje jedan (bilo koji)
//  put u grafu izmedju zadatog pocetnog i krajnjeg cvora koji prolazi
//  kroz treci zadati cvor i ne mora biti prost.
void GraphAsListsInt::pathThroughNode(int dataFirst, int dataLast, int dataThrough)
{
	LinkedNodeInt* first = findNode(dataFirst);
	LinkedNodeInt* finish = findNode(dataLast);
	LinkedNodeInt* thru = findNode(dataThrough);
	if (start == nullptr || finish == nullptr || thru == nullptr)
		return;

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		ptr->prev = nullptr;
		ptr = ptr->next;
	}
	
	setStatusForAllNodes(1);

	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(first);
	first->status = 2;

	bool dataOnPath = false;

	while (!stack.isEmpty())
	{
		LinkedNodeInt* pom = stack.pop();
		LinkedEdgeInt* pEdge = pom->adj;

		while (pEdge != nullptr)
		{
			
			if (pEdge->dest->status == 1)
			{
				pEdge->dest->status = 2;
				stack.push(pEdge->dest);
				pEdge->dest->prev = pom;
			}
			if (pEdge->dest == thru)
			{
				dataOnPath = true;
				break;
			}
			if (pEdge->dest == finish)
			{
				if (dataOnPath)
				{
					cout << "Put je:" << endl;
					finish->visit();
					LinkedNodeInt* pomocniPtr = pom;
					while (pomocniPtr != nullptr)
					{
						pomocniPtr->visit();
						pomocniPtr = pomocniPtr->prev;
					}
					return;
				}
			}
			pEdge = pEdge->link;
		}
	}



	/*
	setStatusForAllNodes(1);
	LinkedNodeInt* ptr = start;

	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(ptr);
	bool postojiOdStartDoThru = false;

	LinkedNodeInt** niz = new LinkedNodeInt * [nodeNum]();
	int p = 1;
	niz[0] = start;

	//ovo ce da bude samo prost put jbg nmg drugi da trazim
	while (!postojiOdStartDoThru && !stack.isEmpty())
	{
		LinkedNodeInt* pom = stack.pop(); pom->status = 2;
		LinkedEdgeInt* pEdge = pom->adj;

		niz[p++] = pom;

		while (pEdge != nullptr)
		{
			if (pEdge->dest == thru)
			{
				postojiOdStartDoThru = true;
				niz[p++] = pEdge->dest;
				break;
			}
			if (pEdge->dest->status == 1)
				stack.push(pEdge->dest);
			//if (!postojiOdStartDoThru)
				//p--;
			pEdge = pEdge->link;
		}
	}

	if (postojiOdStartDoThru)
	{
		while (!stack.isEmpty())
			stack.pop();

		setStatusForAllNodes(1);
		stack.push(thru);
		niz[p++] = thru;
		bool postojiOdThruDoFinish = false;

		while (!stack.isEmpty() && !postojiOdThruDoFinish)
		{
			LinkedNodeInt* pom = stack.pop(); pom->status = 2;
			niz[p++] = pom;

			LinkedEdgeInt* pEdge = pom->adj;
			while (pEdge != nullptr)
			{
				if (pEdge->dest == finish)
				{
					postojiOdThruDoFinish = true;
					niz[p++] = pEdge->dest;
					break;
				}
				if (pEdge->dest->status == 1)
					stack.push(pEdge->dest);

				//if (!postojiOdThruDoFinish)
					//p--;
				pEdge = pEdge->link;
			}
		}
		if (postojiOdStartDoThru)
		{
			int* vecVidjeno = new int[p]; int k = 0;
			cout << "put postoji i on je:" << endl;
			//start->visit();
			for (int i = 0; i < p; i++)
			{
				bool vecOdstampano = false;
				for (int l = 0; l < k; l++)
					if (niz[i]->node == vecVidjeno[l])
						vecOdstampano = true;
				if(!vecOdstampano)
					niz[i]->visit();

				vecVidjeno[k++] = niz[i]->node;
			}
		}
		else
			return;
		

	}
	else
		return;
	*/

	/*
	LinkedNodeInt* start = findNode(dataFirst);
	LinkedNodeInt* finish = findNode(dataLast);
	LinkedNodeInt* through = findNode(dataThrough);
	if (start == nullptr || finish == nullptr || through == nullptr )
		return;

	setStatusForAllNodes(1);//da li mi je stvarno potreban status??

	//jedna od mogucnosti da imam 2 putanje,
	// ****************************************
	//jedna za od first to through, a druga od through do finish
	//i onda posle samo spojim 2 putanje/stampam jednu pa drugu putanju
	//*****************************************
	LinkedNodeInt** putanja = new LinkedNodeInt * [nodeNum]();
	putanja[0] = start;
	start->status = 2;
	int p = 1;
	bool putanjaPostoji = false;

	LinkedEdgeInt* pEdge = start->adj;
	while (pEdge != nullptr && !putanjaPostoji)
	{
		if (pEdge->dest->status == 1)
		{
			if (imaPut(start, through, putanja, &p))
			{
				//putanja[p++] = through;
				if (imaPut(through, finish, putanja, &p))
				{
					//putanja[p++] = through;
					putanjaPostoji = true;
				}
				//else
					//p--;
			}
		}
		pEdge->dest->status = 2;
		pEdge = pEdge->link;
	}
	//nalazimi mi dobar put,samo mi ga pogresno stampa
	//ili mi stampa duplo neke cvorove,ili mi duplo odstampa pocetak.
	if (p > 1 && putanjaPostoji)
	{
		start->visit();
		for (int i = 1; i<p; i++)
			if (putanja[i] != nullptr)
				putanja[i]->visit();
		//finish->visit();
	}
	*/

}

//NIGGA ISTESTIRAJ SVE OVO ZBOG OVIH DODATIH STATUSA I SVE TO...
bool GraphAsListsInt::imaPut(LinkedNodeInt* start, LinkedNodeInt* finish, LinkedNodeInt** putanja, int* pokazivac)
{
	if (start == finish)
		return true;
	if (start == nullptr)
		return false;

	LinkedEdgeInt* pEdge = start->adj;
	while (pEdge != nullptr)
	{
		if (pEdge->dest == finish)
		{
			//putanja[*pokazivac] = pEdge->dest;//ZASTO MI IZBACUJE ISTO NEBITNO 
			//putanja[*pokazivac] = finish;       //KOJE OD OVE 2 LINIJE ISKORISTIM
			if(start->status==1)
			{
				putanja[*pokazivac] = start;
				*pokazivac += 1;
				start->status = 2;
			}
			if(finish->status==1)
			{
				putanja[*pokazivac] = finish;
				*pokazivac += 1;
				finish->status = 2;
			}
			return true;
		}
		if (pEdge->dest->status == 1)
		{
			if (imaPut(pEdge->dest, finish, putanja, pokazivac))
			{
				//putanja[*pokazivac] = pEdge->dest;
				if(start->status==1)
				{
					putanja[*pokazivac] = start;
					*pokazivac += 1;
					start->status = 2;
				}
				return true;
			}
		}

		pEdge = pEdge->link;
	}
	return false;

}
