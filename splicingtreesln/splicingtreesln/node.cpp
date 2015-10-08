#include "node.h"

dim::dim(double h, double w) {
	height = h;
	width = w;
	next = NULL;
}

void dim::instert(dim* in) {
	if (this->next == NULL) {
		this->next = in;
	}
	else {
		this->next->instert(in);
	}
}

double dim::findMin() {
	double curr = (this->height * this->width);
	if (this->next == NULL) {
		return curr;
	}
	else {
		return findMin(curr);
	}
}

double dim::findMin(double prev) {
	double curr = (this->height * this->width);
	if (this->next == NULL) {
		if (curr < prev) {
			return curr;
		}
		else {
			return prev;
		}
	}
	else {
		double next = findMin(curr);

	}
}

node::node(char newName) {
	value = newName;
	left = NULL;
	right = NULL;
	height = NULL;
	width = NULL;
	dims = NULL;
}

node::node(char newName, double h, double w) {
	value = newName;
	left = NULL;
	right = NULL;
	height = h;
	width = w;
	dims = NULL;
}

void node::insert(node* newNode) {

	//check if leaf node
	if (this->value != 'h' && this->value != 'v') {
		return;
	}
	//check for empty right branch
	
	if (this->right == NULL) {		
		this->right = newNode;
		return;
	}
	//check for empty right branch
	if (this->left == NULL) {
		this->left = newNode;
		return;
	}
	//continue down if full branches
	if (this->left != NULL) {
		this->left->insert(newNode);
		return;
	}

	//else {
		//cout << "Error 1" << endl;
	//}
	cout << "Error1" << endl;
	return;
}

double node::calculate() {
	
	if (this->left == NULL && this->right == NULL) {
		return this->dims->findMin();
	}
	
	
	
	double area;
	return area;
}

















void node::printTree(int count) {
	if (this->left == NULL && this->right == NULL) {
		for (int i = 0; i < count; i++) {
			std::cout << "   ";
		}
		cout << value << std::endl;
		return;
	}

	if (this->left != NULL) {
		this->left->printTree(count + 1);

	}

	for (int i = 0; i < count; i++) {
		std::cout << "   ";
	}
	std::cout << value << std::endl;

	if (this->right != NULL) {
		this->right->printTree(count + 1);

	}

	return;
}

