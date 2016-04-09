#pragma once
#include <vector>
#include <iostream>
#include "Node.h"

class AVLTree {
public:

	AVLTree();

	bool AVLTree::insert(int key, int value);
	int AVLTree::getHeight();
	int AVLTree::getSize();
	void AVLTree::print();
	//TODO:
	bool AVLTree::find(int key, int& value);
	std::vector<int> AVLTree::findRange(int lowkey, int highkey);
	bool AVLTree::insertHelper(Node*& rootNode, Node* newNode);
	int AVLTree::recursiveGetHeight(Node* currNode);
	void AVLTree::inorderLvls(const Node* curr, int lvl);
	//TODO: single rotate
	//TODO: double rotate

private:
	Node* root;
	int size;
};