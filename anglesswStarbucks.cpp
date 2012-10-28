#include "anglesswStarbucks.h"
#include <ctime>
#include <cstdlib>

static const double difference = 0.00001;

anglesswStarbucks::anglesswStarbucks(void)
{
}

void anglesswStarbucks::build(Entry* c, int n)
{
	srand((unsigned) time(0));
	length = n;
	entry_arr_ = new Entry[length];
	Node* root = new Node(entry_arr_[rand()%length]);
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if((j+1==i) && (abs(c[j].x-c[i].x) > difference) &&
				(abs(c[j].y-c[i].y) > difference)) {
				root->insert(c[i], root, true);
			}
		}
	}
	delete root;
}

Entry* anglesswStarbucks::getNearest(double x, double y)
{
	return new Entry();
}

anglesswStarbucks::~anglesswStarbucks(void)
{
}
