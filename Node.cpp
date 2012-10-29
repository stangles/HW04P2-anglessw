#include "Node.h"
#include <iostream>

Node::Node(Entry e)
{
	right = left = NULL; 
	entry = e;
}

Node* Node::insert(Entry e, Node* r, bool x_level)
{
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
	return r;
}

Node* Node::search(Entry e, Node* r, bool x_level)
{
	if(r == NULL) return NULL;
	if(e.x == r->entry.x || e.y == r->entry.y) return r;
	Node* candidate;
	if(x_level) {
		if(e.x < r->entry.x)
			candidate = search(e,r->left,!x_level);
		else
			candidate = search(e,r->right,!x_level);
	} else {
		if(e.y < r->entry.y)
			candidate = search(e,r->left,!x_level);
		else
			candidate = search(e,r->right,!x_level);
	}
	if(candidate == NULL)
		return r;
	else
		return candidate;
}

void Node::printInOrder(Node* r) {
	if(r == NULL) return;
	printInOrder(r->left);
	cout << r->entry.identifier << endl;
	printInOrder(r->right);
}

Node::~Node(void)
{
	delete left;
	delete right;
}
