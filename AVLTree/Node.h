#pragma once

#define PTR unsigned int
#define NULLPTR -1

class Node {
public:
	int key;
	int value;
	PTR par;
	PTR lc;
	PTR rs;

	//Default constructor
	Node() {
		key = 0;
		value = 0;
		par = NULLPTR;
		lc = NULLPTR;
		rs = NULLPTR;
	};

	//Passed key, value, par, lc, rs constructor
	Node(int keyX, int valueX, PTR parX, PTR lcX, PTR rsX) {
		key = keyX;
		value = valueX;
		par = parX;
		lc = lcX;
		rs = rsX;
	};

};