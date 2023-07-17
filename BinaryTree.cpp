#include <iostream>
#include "Tree.h"

int main() {

	Tree tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(6);

	tree.print();
	
	cout << "delete" << endl;
	tree.erase(10);
	tree.print();

	return 0;
}