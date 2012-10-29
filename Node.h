#pragma once
#include "Starbucks.h"
class Node
{
public:
	Node* left;
	Node* right;
	Node(Entry e);
	Entry entry;
	Node* insert(Entry e, Node* r, bool x_level);
	Node* search(Entry e, Node* r, bool x_level);
	double distance(Entry e1, Entry e2);
	void printInOrder(Node* r);
	virtual ~Node(void);
private:
	double best_dist_;
};

