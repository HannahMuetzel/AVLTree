#include "AVLTree.h"

int main() {

	int testSize = 0;
	AVLTree testTree;


	if (testTree.insert(2, 20)) {
		testSize++;
		//cout << "Inserted key " << 2 << " with value " << 20 << endl;
	}
	if (testTree.insert(1, 10)) {
		testSize++;
		//cout << "Inserted key " << 1 << " with value " << 10 << endl;
	}
	if (testTree.insert(3, 30)) {
		testSize++;
		//cout << "Inserted key " << 3 << " with value " << 30 << endl;
	}
	
	bool dupInsert = testTree.insert(1, 10);
	if (dupInsert) {
		testSize++;
	}
	cout << "Inserted key 1 with value 10? " << dupInsert << endl;

	int actSize = testTree.getSize();
	cout << "The size according to the AVLTree is " << actSize << " and the main.cpp size is " << testSize << endl;

	testTree.print();

	system("pause");
	return 0;
}