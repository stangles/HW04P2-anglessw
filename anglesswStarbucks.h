#pragma once
#include "starbucks.h"

class Node {
public:
	Node* left;
	Node* right;
	Node(Entry e) { right = left = NULL; entry = e; }
	Entry entry;
	Node* insert(Entry e, Node* r, bool x_level)
	{
		if(r == NULL) return new Node(e);
		if(e.x == r->entry.x || e.y == r->entry.y) return r;
		if(x_level) {
			if(e.x < r->entry.x) 
				return r->left = insert(e, r->left, !x_level);
			else 
				return r->right = insert(e, r->right, !x_level);
		} else {
			if(e.y < r->entry.y) 
				return r->left = insert(e, r->left, !x_level);
			else 
				return r->right = insert(e, r->right, !x_level);
		}
	}
	Node* search(Entry e, Node* r, bool x_level)
	{
		if(r == NULL) return NULL;
		if(x_level) {
			if(e.x == r->entry.x)
				return r;
			else if(e.x < r->entry.x) {
				Node* candidate;
				return candidate = search(e, r->left, !x_level);
			} else {
				Node* candidate;
				return candidate = search(e, r->right, !x_level);
			}
		} else {
			if(e.y == r->entry.y)
				return r;
			else if(e.y < r->entry.y) {
				Node* candidate;
				return candidate = search(e, r->left, !x_level);
			} else {
				Node* candidate;
				return candidate = search(e, r->right, !x_level);
			}
		}
	}
			

	virtual ~Node() { delete left; delete right; }
};

class anglesswStarbucks : public Starbucks {
public:
	anglesswStarbucks(void);
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	virtual ~anglesswStarbucks(void);
private:
	Entry* entry_arr_;
	int length;
};

