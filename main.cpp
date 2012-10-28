#include <iostream>
#include <fstream>
#include <string>
#include "Starbucks.h"
#include "anglesswStarbucks.h"

//using namespace std;

int main(void) {
	ifstream in_file("Starbucks_2006.csv");

	string identifier; 
	int index = 0;

	Entry* entry_arr = new Entry[7700];

	while(in_file.eof() != true) {
		getline(in_file,entry_arr[index].identifier,',');

		in_file >> entry_arr[index].x;

		in_file.get();

		in_file >> entry_arr[index].y;
		
		in_file.get();

		index++;
	}

	anglesswStarbucks* starbucks = new anglesswStarbucks();

	starbucks->build(entry_arr, index);
	Entry* ent = starbucks->getNearest(0.295011306,0.4454744);

	cout << ent->identifier << ' ' << ent->x << ' ' << ent->y << endl;

	delete ent;
	delete starbucks;
	delete [] entry_arr;

	return 0;
}



