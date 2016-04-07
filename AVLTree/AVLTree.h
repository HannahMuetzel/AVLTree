#pragma once
#include "Node.h"

#include <vector>
#include <iostream>
#include "Node.h"

class AVLTree {
public:

	AVLTree();
	~AVLTree();

	//TODO: bool AVLTree::insert(int key, int value);
	//TODO: int AVLTree::getHeight();
	int AVLTree::getSize();
	//TODO: void AVLTree::print();
	//TODO: bool AVLTree::find(int key, int& value);
	std::vector<int> AVLTree::findRange(int lowkey, int highkey);

	//TODO: recursive insert
	//TODO: double rotate
	//TODO: double rotate

private:
	std::vector<Node> tree;
	PTR root;
	int size;
};