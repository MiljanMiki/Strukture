#pragma once

#include <iostream>
using namespace std;

class BSTNodeInt
{
public:
	int key;
	BSTNodeInt* left, * right;

public:
	BSTNodeInt()
		: key(), left(nullptr), right(nullptr) { }
	BSTNodeInt(int el)
		: key(el), left(nullptr), right(nullptr) { }
	BSTNodeInt(int el, BSTNodeInt* lt, BSTNodeInt* rt) 
		: key(el), left(lt), right(rt) { }
	bool isLT(int el) const 
	{
		if (key < el) return true;
		else return false;
	};
	bool isGT(int el) const {
		if (key > el) return true;
		else return false;
	};
	bool isEQ(int el) const {
		if (key == el) return true;
		else return false;
	};
	void setKey(int el) { key = el; }
	int getKey() const { return key; }
	void visit() const 
	{ 
		if (left == nullptr && right == nullptr)
			cout << '('<<key << ") JE LIST!!!"; //da budem siguran da mi racuna tacne vrednosti...
		else
			cout << key << " "; 
	}
};

