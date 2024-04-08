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
	void printSearch(Node* root, int data);

};


int main() {

	int searchNum;

	BST myTree;
	Node myNode = 7;
	myTree.insertNode(&myNode, 20);
	myTree.insertNode(&myNode, 8);
	myTree.insertNode(&myNode, 9);
	myTree.insertNode(&myNode, 6);
	myTree.insertNode(&myNode, 1);
	myTree.insertNode(&myNode, 19);
	myTree.insertNode(&myNode, 15);
	myTree.insertNode(&myNode, 2);
	myTree.insertNode(&myNode, 10);
	myTree.printTree(&myNode);
	
	cout << "\nLargest: " << myTree.Largest(&myNode) << endl;


	cout << "\nInsert a number to search: ";
	cin >> searchNum;
	myTree.printSearch(&myNode, searchNum);

	cout << "\nInsert a number to search: ";
	cin >> searchNum;
	myTree.printSearch(&myNode, searchNum);

	return 0;
}

void BST::printSearch(Node* root, int data) {
	if (findNode(root, data) == NULL) { // if findNode returns a null, it was not found
		cout << data << " was not found." << endl;
	}
	else {
		cout << data << " was found." << endl;
	}
}

void BST::printTree(Node* root) { // post order travel // Currently works
	if (root != NULL) {

		printTree(root->leftChild); // recursively calling data from left and right children
		printTree(root->rightChild);
		cout << " " << root->data;
		//getRoot();
	}

}

int BST::Largest(Node* root) {
	while (root->rightChild != NULL) {	// in BSTs, right side is larger than root, so we read through that
		root = root->rightChild;

	}


	return root->data; // returns data of largest after traversing
}

bool BST::findNode(Node* root, int data) {

	if (root == NULL || root->data == data) { // if no nodes
		return root;
	}

	if (root->data < data) { // if the data in root is less than data, we read that first
		return findNode(root->rightChild, data);
	}

	else if (root->data > data) { // if data in root is greater than, "					"
		return findNode(root->leftChild, data);
	}
}



BST::BST() {


	return;
}

Node* BST::insertNode(Node* root, int data) { 

	if (root == NULL) {
		Node* root = new Node(data); // Our first node(root)
		return root;
	}
	

	if (data < root->data) {

		root->leftChild = insertNode(root->leftChild, data); // having leftChild contain given data
	}
	else if (data > root->data) {

		root->rightChild = insertNode(root->rightChild, data); // having rightChild contain given data
	}


	return root;
}