#include "AVLTree.h"
#include <ostream>
#include <string>

AVLTree::AVLTree() {
	size = 0; //number of nodes in the tree initialized to 0
	root = NULL; //root initialized to null ptr
}

bool AVLTree::insert(int key, int value) {
	//inc tree size by 1 if going to return true, else don't increment it
	Node* newNode = new Node(key, value, NULL, NULL);
	int arbitrary = 0;
	if (!find(key, arbitrary)) {
		if (root == NULL) {
			size++;
			root = newNode;
			return true;
		}
		else {
				insertHelper(root, newNode);
				size++;
				return true;
			
		}
	}
	//Failed to add the node
	return false;
};

bool AVLTree::insertHelper(Node*& rootNode, Node* newNode) {
	if (newNode->key < rootNode->key) {
		if (rootNode->lc == NULL) {
			rootNode->lc = newNode;
			return true;
		}
		else {
			insertHelper(rootNode->lc, newNode);
		}
	}
	else {
		if (rootNode->rc == NULL) {
			rootNode->rc = newNode;
			return true;
		}
		else {
			insertHelper(rootNode->rc, newNode);
		}
	}
};

int AVLTree::getSize() {
	return size;
};

int AVLTree::getHeight() {
	//The max height of the tree will be whichever side of the tree is higher
	//check to see if root is NULL
	if (root == NULL) {
		//if it is, then height = 0
		return 0;
	} else {
		//otherwise, find the max height recursively by passing the root
		int maxHeight = recursiveGetHeight(root);
		return maxHeight;
	}
};

int AVLTree::recursiveGetHeight(Node* currNode) {
	//check to see if root is NULL
	if (currNode == NULL) {
		//if it is, then height = 0
		return 0;
	}
	else {
		//otherwise, recursively find the left max height
		int leftHeight = recursiveGetHeight(currNode->lc);
		//then, recursively find the right max height
		int rightHeight = recursiveGetHeight(currNode->rc);

		//compare the two
		//the max height will be the greater of the two heights +1 for the root node
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
};

void AVLTree::print() {
	//do inorder traversal of tree recursively, printing as we go
	inorderLvls(root, 0);
};

void AVLTree::inorderLvls(const Node* curr, int lvl) {
	if (curr == 0) {
		return;
	}
	inorderLvls(curr->rc, lvl + 1);
	cout << string(lvl, '    ') << "(" << curr->key << ", " << curr->value << ")" << endl;
	inorderLvls(curr->lc, lvl + 1);
}

bool AVLTree::find(int key, int& value) {
	Node* check = root; //start at root, compare passed values to Node check
						//if the root is empty then there are no keys, return false
	if (check == NULL) {
		return false;
	};
	while (check->key != key) {
		if (check != NULL) {
			if (check->key > key) {
				value = check->value;
				check = check->lc;
			}
			else {
				value = check->value;
				check = check->rc;
			}

			if (check == NULL) {
				value = value;
				return false;
			}
		}
	}
	//return false b/c key was not found in the tree
	return true;
};


/*
std::vector<int> AVLTree::findRange(int lowkey, int highkey) {
	std::vector<int> inRange;
	//if root == NULL then there is nothing in the tree and thus nothing in the range
	if (root != NULL) {
		Node* check = root; //start at root, compare passed values to Node check
		//while we have nodes to check
		int checkNum = 0;
		while (checkNum =! size) {
			//if check value is > high key AND < low key then check left tree.
			if (check->key > lowkey && check->key < highkey) {
				check = check->rc;
				inRange.push_back(check->key);
				inRange.push_back(check->value);
			}
			
			//if check value is < high key AND > low key then check left tree.
			if (check->key < highkey && check->key > lowkey) {
				check = check->lc;
				inRange.push_back(check->key);
				inRange.push_back(check->value);
			} //else (root value is <= given key) go to right tree

			checkNum++;
	}
	return inRange;
};
*/

std::vector<int> AVLTree::findRange(int lowkey, int highkey) {
	std::vector<int> inRange;
	return inRange;
}