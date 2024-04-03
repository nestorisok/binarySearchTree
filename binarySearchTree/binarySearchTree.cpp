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
	Node myNode = 4;
	myTree.insertNode(&myNode, 2);
	myTree.insertNode(&myNode, 7);
	myTree.insertNode(&myNode, 1);
	myTree.insertNode(&myNode, 3);
	myTree.printTree(&myNode);
	
	cout << "\nLargest: " << myTree.Largest(&myNode) << endl;

	int searchNum = 5;

	if (myTree.findNode(&myNode, searchNum) == NULL) {
		cout << searchNum << " was not found." << endl;
	}
	else {
		cout << searchNum << " was found." << endl;
	}


	return 0;
}



void BST::printTree(Node* root) { // post order travel // Currently works
	if (root != NULL) {

		printTree(root->leftChild);
		printTree(root->rightChild);
		cout << " " << root->data;
		//getRoot();
	}

}

int BST::Largest(Node* root) {
	while (root->rightChild != NULL) {
		root = root->rightChild;

	}


	return root->data;
}

bool BST::findNode(Node* root, int data) {

	if (root == NULL || root->data == data) {
		return root;
	}

	if (root->data < data) {
		return findNode(root->rightChild, data);
	}

	else if (root->data > data) {
		return findNode(root->leftChild, data);
	}
}



BST::BST() {


	return;
}

Node* BST::insertNode(Node* root, int data) { 

	if (root == NULL) {
		Node* root = new Node(data); // this WORKS
		return root;
	}
	

	if (data < root->data) {

		root->leftChild = insertNode(root->leftChild, data);
	}
	else if (data > root->data) {

		root->rightChild = insertNode(root->rightChild, data);
	}


	return root;
}