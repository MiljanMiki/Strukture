#include "BSTreeInt.h"

#include <exception>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

void BSTreeInt::deleteTree(BSTNodeInt* ptr)
{
	if (ptr != nullptr) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		delete ptr;
	}
}

BSTNodeInt* BSTreeInt::search(int el) const
{
	BSTNodeInt* ptr = root;
	while (ptr != nullptr)
		if (ptr->isEQ(el))
			return ptr;
		else if (ptr->isGT(el))
			ptr = ptr->left;
		else
			ptr = ptr->right;
	return nullptr;
}

void BSTreeInt::insert(int el)
{
	BSTNodeInt* ptr = root, * par = nullptr;
	while (ptr != nullptr) {  // trazenje mesta za umetanje novog cvora
		par = ptr;
		if (ptr->isLT(el))
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}
	if (root == nullptr)    // stablo je prazno
		root = new BSTNodeInt(el);
	else if (par->isLT(el))
		par->right = new BSTNodeInt(el);
	else
		par->left = new BSTNodeInt(el);
	numOfElements++;
}

void BSTreeInt::deleteByCopying(int el)
{
	BSTNodeInt* node, * ptr = root, * par = nullptr;
	while (ptr != nullptr && !ptr->isEQ(el)) { 	// nalazenje cvora sa zeljenim el.
		par = ptr;
		if (ptr->isLT(el)) ptr = ptr->right;
		else ptr = ptr->left;
	}
	node = ptr;
	if (ptr != nullptr && ptr->isEQ(el)) {
		if (node->right == nullptr)             // cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == nullptr)         // cvor nema levog potomka (2)
			node = node->right;
		else {									// cvor ima oba potomka (3)
			BSTNodeInt* tmp = node->left;
			BSTNodeInt* parent = node;
			while (tmp->right != nullptr) {		// nalazenje krajnjeg desnog cvora
				parent = tmp;             		// u levom podstablu
				tmp = tmp->right;
			}
			node->setKey(tmp->getKey());		// prepisivanje reference na kljuc 
			if (parent == node)           		// tmp je direktni levi potomak node-a
				parent->left = tmp->left;		// ostaje isti raspored u levom podstablu
			else
				parent->right = tmp->left; 		// levi potomak tmp-a 
			delete tmp;							// se pomera na mesto tmp-a
			numOfElements--;
			return;
		}
		if (ptr == root)						// u slucaju (1) i (2) samo je pomerena
			root = node;						// referenca node pa je potrebno
		else if (par->left == ptr)				// izmeniti i link prethodnog cvora
			par->left = node;					// u slucaju (3) ovo nema dejstva
		else
			par->right = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != nullptr)
		throw new exception("Element is not in the tree!");
	else
		throw new exception("The tree is empty!");
}

void BSTreeInt::deleteByMerging(int el)
{
	BSTNodeInt* node, * ptr = root, * par = nullptr;
	while (ptr != nullptr && !ptr->isEQ(el)) {	// nalazenje cvora sa zeljenim el.
		par = ptr;
		if (ptr->isLT(el)) ptr = ptr->right;
		else ptr = ptr->left;
	}
	node = ptr;
	if (ptr != nullptr && ptr->isEQ(el)) {
		if (node->right == nullptr)				// cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == nullptr)			// cvor nema levog potomka (2)
			node = node->right;
		else {									// cvor ima oba potomka (3)
			BSTNodeInt* tmp = node->left;
			while (tmp->right != nullptr)		// nalazenje krajnjeg desnog cvora
				tmp = tmp->right;				// u levom podstablu
			tmp->right = node->right;			// prebacivanje desnog linka node-a u tmp
			node = node->left;					// na tekucem mestu bice prvi levi potomak
		}
		if (ptr == root)
			root = node;
		else if (par->left == ptr)
			par->left = node;
		else
			par->right = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != nullptr)
		throw new exception("Element is not in the tree!");
	else
		throw new exception("The tree is empty!");
}

void BSTreeInt::preorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		ptr->visit();
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BSTreeInt::inorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		ptr->visit();
		inorder(ptr->right);
	}
}

void BSTreeInt::postorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		ptr->visit();
	}
}

void BSTreeInt::iterativePreorder() const
{
	BSTNodeInt* ptr = root;
	StackAsArrayBSTNodeInt stack(numOfElements);
	if (ptr != nullptr) {
		stack.push(ptr);
		while (!stack.isEmpty()) {
			ptr = stack.pop();
			ptr->visit();
			if (ptr->right != nullptr)	// levi potomak se stavlja u magacin
				stack.push(ptr->right); // posle desnog, da bi se prvi obradio
			if (ptr->left != nullptr)
				stack.push(ptr->left);
		}
	}
}

void BSTreeInt::breadthFirstSearch() const
{
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != nullptr) 
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty()) {
			ptr = queue.dequeue();
			ptr->visit();
			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}
}

BSTNodeInt* BSTreeInt::findMaxAverage()
{
	int maxAverage = 0;
	BSTNodeInt* maxNode=nullptr;
	if (root == nullptr)
		return nullptr;
	findMaxAverage(root, &maxAverage, &maxNode);
	return maxNode;

}


//jedna veca digresija posto sam glup ko kurac:kad hocu da prosledim pokazivac i zelim da f-ja njega
//modifikuje, nije dovoljno da samo prosledim taj pokazivac (jer se tada samo lokalna kopija,ko za sve ostalo),
//nego vec moram njegovu adresu da prosledim, a da u deklaraciji f-je to bude 
// DUPLI pokazivac.Zatim ako hocu da azurizam vrednost,moram u f-ji da ga deferenciram
//prosli kod mi je bio ovakav:
/*
	*maxNode=nullptr
	findMaxAverage(root, &maxAverage, maxNode);
	return maxNode;

	void BSTreeInt::findMaxAverage(BSTNodeInt* start, int* average, BSTNodeInt* maxNode)

	STO NIJE DOBRO!!!Ovde se samo pravi lokalna kopija pokazivaca, pa kad se vraca maxNode ipak se vraca nullptr

	u osnovi uvek kada se passuje neka vrednost f-ji koju zelim da se menja, ona uvek treba da bude prosledjena
	kao adresa, a da u deklaraciji f-je stoji pokazivac, CAK i ako se passuje pokazivac. Stupid nigger...

	***U OSNOVI:kako se pasuju obicne vrednosti tako treba i pokazivaci eg:
	int p;
	nekaFunkcija(&p) (u deklaraciji je nekaFunkcija(int*))

	int* p;
	nekaFunkcija(&p); (u deklaraciji je nekaFnkcija(int**))

	presive sam treskao sto od besa zbog ovog previda

*/

void BSTreeInt::findMaxAverage(BSTNodeInt* start, int* average, BSTNodeInt** maxNode)
{
	if (start != nullptr)
	{
		int brojCvorovaLevo = 0,zbirLevo=0;
		int brojCvorovaDesno = 0,zbirDesno=0;

		if (start->left != nullptr)
			obidjiPodsablo(start->left, &brojCvorovaLevo, &zbirLevo);
		if(start->right != nullptr)
			obidjiPodsablo(start->right, &brojCvorovaDesno, &zbirDesno);
		//int srednjaVrednost=-1;
		if (brojCvorovaDesno+brojCvorovaLevo!=0)//start->right != nullptr || start->left != nullptr
		{
			//srednjaVrednost = (zbirDesno + zbirLevo) / (brojCvorovaDesno + brojCvorovaLevo);

			if ((zbirDesno + zbirLevo) / (brojCvorovaDesno + brojCvorovaLevo) > *average)
			{
				*average = (zbirDesno + zbirLevo) / (brojCvorovaDesno + brojCvorovaLevo);
				*maxNode = start;
			}
		}
		if(start->right!=nullptr)
			findMaxAverage(start->right, average, maxNode);
		if (start->left != nullptr)
			findMaxAverage(start->left, average, maxNode);

		/*if (srednjaVrednost > *average)
		{
			*average = srednjaVrednost;
			return start;
		}
		else
			return maxNode;*/
	}
	//return maxNode;
}

void BSTreeInt::obidjiPodsablo(BSTNodeInt* start, int* brojCvorova, int* zbir)
{
	*brojCvorova += 1;
	*zbir += start->getKey();

	if (start->right != nullptr)
		obidjiPodsablo(start->right, brojCvorova, zbir);
	if (start->left != nullptr)
		obidjiPodsablo(start->left, brojCvorova, zbir);

}
