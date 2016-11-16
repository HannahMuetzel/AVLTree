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
	bool AVLTree::insertBST(int key, int value);
	
private:
	
	Node* root;
	int size;
	
	//Helper methods
	std::vector<Node> extra;
	bool AVLTree::insertHelper(Node*& rootNode, Node* newNode);
	int AVLTree::recursiveGetHeight(Node* currNode);
	void AVLTree::inorderLvls(const Node* curr, int lvl);
	void AVLTree::rightRotate(Node*, Node*);
	void AVLTree::leftRotate(Node*, Node*);
	int AVLTree::findBalance(Node*);
	void updateDepths();
};