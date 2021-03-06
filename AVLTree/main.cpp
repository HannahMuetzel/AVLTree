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
	if (testTree.insert(4, 30)) {
		testSize++;
		//cout << "Inserted key " << 3 << " with value " << 30 << endl;
	}
	if (testTree.insert(5, 30)) {
		testSize++;
		//cout << "Inserted key " << 3 << " with value " << 30 << endl;
	}
	if (testTree.insert(6, 30)) {
		testSize++;
		//cout << "Inserted key " << 3 << " with value " << 30 << endl;
	}
	if (testTree.insert(7, 30)) {
		testSize++;
		//cout << "Inserted key " << 3 << " with value " << 30 << endl;
	}

	int height = testTree.getHeight();
	cout << "The height is " << height << endl;
	
	bool dupInsert = testTree.insert(1, 10);
	if (dupInsert) {
		testSize++;
	}
	cout << "Inserted key 1 with value 10? " << dupInsert << endl;
	
	int testVal = 0;
	bool found = testTree.find(3, testVal);
	cout << "Key 3 was found? " << found << " testVal = " << testVal << endl;
	found = testTree.find(47, testVal);
	cout << "Key 47 was found? " << found << " testVal = " << testVal << endl;
	
	int actSize = testTree.getSize();
	cout << "The size according to the AVLTree is " << actSize << " and the main.cpp size is " << testSize << endl;

	testTree.print();

	cout << "Gonna test the range now, yo." << endl;
	std::vector<int> range = testTree.findRange(2, 6);
	for (auto it = range.begin(); it < range.end(); it++) {
		cout << *it << " ";
	}

	cout << "Test AVL rotations!" << endl;
	AVLTree AVL;
	AVLTree BST;

	AVL.insertAVL(1, 10);
	BST.insert(1, 10);
	AVL.insertAVL(2, 20);
	BST.insert(2, 20);
	AVL.insertAVL(5, 50);
	BST.insert(5, 50);

	
	cout << "The BST looks like:" << endl;
	BST.print();

	cout << "The AVL looks like:" << endl;
	AVL.print();

	system("pause");
	return 0;
}