#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int key;
	int value;
	Node* lc = NULL;		//left child
	Node* rc = NULL;	    //right child
	unsigned int LD = 0;	//Left Depth
	unsigned int RD = 0;	//Right Depth

	//Passed key, value, lc, rs constructor
	Node(int keyX, int valueX, Node* lcX, Node* rcX) {
		this->key = keyX;
		this->value = valueX;
		this->lc = lcX;
		this->rc = rcX;
	};

};