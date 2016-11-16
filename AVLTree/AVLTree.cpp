#include "AVLTree.h"
#include <ostream>
#include <string>

/*
AVLTree() constructor
initializes size to 0 and root to NULL pointer
Runtime: theta(1)
*/
AVLTree::AVLTree() {
	size = 0; //number of nodes in the tree initialized to 0
	root = NULL; //root initialized to null ptr
}

/*
bool insert(int, int)
Inserts to create an AVL tree.
Rotations implemented.
Inserts a new node to the tree, linking it to the previous node based on key value
by sending it to the recursive insertHelper function.
Node->key values are added to a vector in order to use later in findRange function.
(Calls findBalance funciton, which calls recursiveGetHeight, therefore...)
Runtime: theta(n^2)
*/
bool AVLTree::insert(int key, int value) {
	//inc tree size by 1 if going to return true, else don't increment it
	Node* newNode = new Node(key, value, NULL, NULL);
	int arbitrary = 0;
	if (!find(key, arbitrary)) {
		if (root == NULL) {
			size++;
			root = newNode;
			extra.push_back(*root);
			updateDepths();
			return true;
		}
		else {
				insertHelper(root, newNode);
				size++;
				//TODO: implement rotations
				/*
				-trav tree
				-if any node has balance >= |2|
					- find deepest node with |2|
						-if +2:
							-if bal of lc = +1:
								-RR
							-if bal of lc = -1:
								-LR
								-RR
						-if -2:
							-if bal of rc = -1:
								-LR
							-if bal of rc = +1:
								-RR
								-LR
				-updateDepths();
				*/
				return true;
				//TODO: write a function to find the deepest node with |2|
				// ^ pseudo-code in spiral notebook, Raymer ok'd it! :)
		}
	}
	//Failed to add the node
	return false;
};

/*
bool insertBST(int, int)
Inserts to create a binary search tree, not an AVL tree.
No rotations implemented.
Inserts a new node to the tree, linking it to the previous node based on key value
by sending it to the recursive insertHelper function.
Node->key values are added to a vector in order to use later in findRange function.
Runtime: theta(1)
*/
bool AVLTree::insertBST(int key, int value) {
	//inc tree size by 1 if going to return true, else don't increment it
	Node* newNode = new Node(key, value, NULL, NULL);
	int arbitrary = 0;
	int balance = 0;
	if (!find(key, arbitrary)) {
		if (root == NULL) {
			size++;
			root = newNode;
			extra.push_back(*root);
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

/*
bool insertHelper(Node ptr ref, Node ptr)
Recursively inserts a node based on key into tree.
Also adds key values into a vector in order to use in findRange function later.
Runtime: theta(logn)
*/
bool AVLTree::insertHelper(Node*& rootNode, Node* newNode) {
	if (newNode->key < rootNode->key) {
		if (rootNode->lc == NULL) {
			rootNode->lc = newNode;
			extra.push_back(*newNode);
			return true;
		}
		else {
			insertHelper(rootNode->lc, newNode);
		}
	}
	else {
		if (rootNode->rc == NULL) {
			rootNode->rc = newNode;
			extra.push_back(*newNode);
			return true;
		}
		else {
			insertHelper(rootNode->rc, newNode);
		}
	}
};

/*
int getSize()
Returns the size of the tree, aka number of nodes.
Runtime: theta(1)
*/
int AVLTree::getSize() {
	return size;
};

/*
int getHeight()
calls recursiveGetHeight to recursively get the height if root is not null.
The entire height of the tree will be the maximum of leftHeight or rightHeight, which is returned.
Runtime: theta(1)
*/
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

/*
int recursiveGetHeight(Node ptr)
Runs through the tree recursively and keeps track of the max height.
The entire height of the tree will be the maximum of leftHeight or rightHeight, which is returned.
Runtime: theta(n)
*/
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

/*
void print()
recursively calls inorderLvls(Node ptr, int) to print the tree with proper spacing.
Runtime: theta(1)
*/
void AVLTree::print() {
	//do inorder traversal of tree recursively, printing as we go
	inorderLvls(root, 0);
};

/*
void inorderLvls(Node ptr, int)
Recursive function that prints the nodes in an inorder traversal, adding proper spacings along the way.
Runtime: theta(n)
*/
void AVLTree::inorderLvls(const Node* curr, int lvl) {
	if (curr == 0) {
		return;
	}
	inorderLvls(curr->rc, lvl + 1);
	cout << string(lvl, '\t') << "(" << curr->key << ", " << curr->value << ")" << endl;
	inorderLvls(curr->lc, lvl + 1);
}

/*
void leftRotate(Node ptr)
A lovely readjustment of pointers in order to do a left rotation of nodes.
If given BST with 1-2-3 (inserted in that order), this is not a valid AVL tree, and a left rotation is needed.
~ 2 becomes new root
~ 1's right child becomes 2's left child
~ 2's left child becomes 1
 **THERE IS NO CHANGE TO 2's !RIGHT! CHILD--It remains 3!**
Runtime: theta(1)
*/
void AVLTree::leftRotate(Node* origRoot, Node* newRoot)
{
	origRoot->rc = newRoot->lc;
	newRoot->lc = origRoot;
}

/*
int findBalance(Node ptr)
Returns the balance of the node, as calculated by the equation:
	balance = height of left subtree - height of right subtree
Calls the recursive function to find the balance of a specific node twice.
(Thus, findBalance traverses the tree twice.)
Runtime: theta(n^2)
*/
int AVLTree::findBalance(Node* node)
{
	int balance = node->LD - node->RD;
	return balance;
}

/*
Update the left and right depths of each node in the AVL tree.
This helps calculate the balance and makes rotations possible.
Runtime: theta(n)
*/
void AVLTree::updateDepths()
{
	for (auto it = extra.begin(); it < extra.end(); it++) {
		it->LD = recursiveGetHeight(it->lc);
		it->RD = recursiveGetHeight(it->rc);
	}
}

/*
void leftRotate(Node ptr)
A suspiciously similiar readjustment of pointers in order to do a right rotation of nodes.
If given BST with 3-2-1 (inserted in that order), this is not a valid AVL tree, and a right rotation is needed.
~ 2 becomes new root
~ 3's left child becomes 2's right child
~ 2's right child becomes 3
 **THERE IS NO CHANGE TO 2's !LEFT! CHILD--It remains 1!**
Runtime: theta(1)
*/
void AVLTree::rightRotate(Node* origRoot, Node* newRoot)
{
	origRoot->lc = newRoot->rc;
	newRoot->rc = origRoot;
}

/*
bool find(int, int ref)
Starts at root, checks the values, and returns if the key is in the tree or not.
Value is then set.
Runtime: theta(logn)
*/
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
	return false;
};

/*
vector<int> findRange(int, int)
Runs through the stored vector of keys and checks to see if they're in the range.
If they are in the range, then they are placed into the inRange vector and returned.
Runtime: theta(n)
*/
std::vector<int> AVLTree::findRange(int lowkey, int highkey) {
	std::vector<int> inRange;
	for (auto it = extra.begin(); it < extra.end(); it++) {
		if (it->key >= lowkey && it->key <= highkey) {
			inRange.push_back(it->key);
			inRange.push_back(it->value);
		}
	}
	return inRange;
};