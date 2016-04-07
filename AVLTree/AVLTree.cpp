#pragma once
#include "AVLTree.h"

int AVLTree::getSize() {
	return size;
};

std::vector<int> AVLTree::findRange(int lowkey, int highkey) {
	std::vector<int> inRange;
	for (auto it = tree.begin(); it != tree.end(); it++) {
		if (it->key <= highkey && it->key >= lowkey) {
			inRange.push_back(it->key);
		}
	}
	return inRange;
};