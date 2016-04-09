#include "AVLTree.h"

int main() {

	int testSize = 0;
	AVLTree testTree;
	
	testTree.insert(1, 10);
	
	for (int i = 1; i < 11; i++) {
		bool testSuccess = testTree.insert(i, i * 10);
		if (testSuccess) {
			cout << "Inserted key " << i << " with value " << i * 10 << endl;
			testSize++;
		}
	}

	bool dupInsert = testTree.insert(1, 10);
	cout << "Inserted key 1 with value 10? " << dupInsert << endl;

	int actSize = testTree.getSize();
	cout << "The size according to the AVLTree is " << actSize << " and the incremented size is " << testSize << endl;

	testTree.print();

	system("pause");
	return 0;
}