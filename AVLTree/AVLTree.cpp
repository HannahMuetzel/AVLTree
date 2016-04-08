#pragma once
#include "AVLTree.h"

AVLTree::AVLTree() {
	size = 0; //number of nodes in the tree initialized to 0
	root = NULL; //root initialized to null ptr
};

bool AVLTree::insert(int key, int value) {
	//inc tree size by 1 if going to return true, else don't increment it
	Node* newNode;
	//TODO: if the key is already in the tree, return false aka do a find

	if (root == NULL) {
		newNode = new Node(key, value, NULL, NULL);
		size++;
		return true;
	} 
	else {
		insertHelper(root, newNode);
		size++;
		return true;
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
	int maxHeight = 0;
	//TODO: height method to find the height of the tree, return an int which is the height
	return maxHeight;
};

void AVLTree::print() {
	//do inorder traversal of tree
	inorder(root);
};

void AVLTree::inorder(Node* curr) {
	if (!curr) {
		return;
	}
	inorder(curr->lc);
	std::cout << "(" << curr->key << ", " << curr->value << ")" << std::endl;
	inorder(curr->rc);
}

bool AVLTree::find(int key, int& value) {
	Node* check = root; //start at root, compare passed values to Node check
	while (check->key = !key) {
		//if root value is >  given key, go to left tree
		if (check->key > key) {
			check = check->lc;
			value = check->value;
		}
		else {
			check = check->rc;
			value = check->value;
		} //else (root value is <= given key) go to right tree

		//key not found or tree is empty
		if (check == NULL) {
			return false;
		}
	}
	//will only get here if the key has been found in the tree
	return true;
};


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
