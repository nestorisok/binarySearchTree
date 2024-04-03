#include <iostream>

using namespace std;


class Node {
public:
	Node(int data) {
		this->data = data;
		this->leftChild = NULL;
		this->rightChild = NULL;
	};
	int data;
	Node* leftChild;
	Node* rightChild;
};

class BST {
private:
	Node* root;

public:
	BST();
	Node* getRoot() { return this->root; };
	void printTree(Node* root);
	Node* insertNode(Node* root, int data);
	bool findNode(Node* root, int data);
	int Largest(Node* root);
};



int main() {

	BST myTree;
	Node myNode = 6;
	myTree.insertNode(&myNode, 8);
	myTree.printTree(&myNode);
	


	return 0;
}



void BST::printTree(Node* root) { // post order travel
	if (root != NULL) {

		printTree(root->leftChild);
		printTree(root->rightChild);
		cout << " " << root->data;
		getRoot();
	}

	return;
}

int BST::Largest(Node* root) {
	while (root->rightChild != NULL) {
		root = root->rightChild;

	}


	return root->data;
}


BST::BST() {


	return;
}

Node* BST::insertNode(Node* root, int data) {

	if (root == NULL) {
		Node::Node(data);

		return getRoot();
	}

	else if (data < root->data) {

		root->leftChild = insertNode(root->leftChild, data);
	}
	else if (data > root->data) {

		root->rightChild = insertNode(root->rightChild, data);
	}

	return root;
}