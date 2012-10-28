#pragma once
#include "starbucks.h"

class Node {
public:
	Node* left;
	Node* right;
	Node(Entry e) { right = left = NULL; entry = e; }
	Entry entry;
	Node* insert(Entry e, Node* r, bool x_level) {
		if(r == NULL) return new Node(e);
		if(e.x == r->entry.x || e.y == r->entry.y) return r;
		if(x_level) {
			if(e.x < r->entry.x) 
				r->left = insert(e, r->left, !x_level);
			else 
				r->right = insert(e, r->right, !x_level);
		} else {
			if(e.y < r->entry.y) 
				r->left = insert(e, r->left, !x_level);
			else 
				r->right = insert(e, r->right, !x_level);
		}
	}
};

class anglesswStarbucks : public Starbucks {
public:
	anglesswStarbucks(void);
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	virtual ~anglesswStarbucks(void);
};

