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
	bool AVLTree::find(int key, int& value);
	std::vector<int> AVLTree::findRange(int lowkey, int highkey);
	
private:
	Node* root;
	int size;
	std::vector<Node> extra;
	bool AVLTree::insertHelper(Node*& rootNode, Node* newNode);
	int AVLTree::recursiveGetHeight(Node* currNode);
	void AVLTree::inorderLvls(const Node* curr, int lvl);
	std::vector<int> AVLTree::recur(Node* curr, int lowkey, int highkey, std::vector<int> inRange);
	//TODO: single rotate
	//TODO: double rotate

};