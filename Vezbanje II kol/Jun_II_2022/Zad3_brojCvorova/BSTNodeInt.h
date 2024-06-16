#pragma once

#include <iostream>
using namespace std;

class BSTNodeInt
{
public:
	int key;
	BSTNodeInt* left, * right;
	double value;

public:
	BSTNodeInt()
		: key(), left(nullptr), right(nullptr) ,value(0){ }
	BSTNodeInt(int el)
		: key(el), left(nullptr), right(nullptr),value(0) { }

	BSTNodeInt(int el,double val):key(el),left(nullptr),right(nullptr),value(val)
	{}

	BSTNodeInt(int el, BSTNodeInt* lt, BSTNodeInt* rt) 
		: key(el), left(lt), right(rt),value(0) { }
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

	inline double getValue() { return value; };

	void setKey(int el) { key = el; }
	int getKey() const { return key; }
	void visit() const { cout << key << " "; }
};

