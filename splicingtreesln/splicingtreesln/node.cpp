#include "node.h"

node::node(char newName) {
	value = newName;
	left = NULL;
	right = NULL;
}

void node::insert(char val) {

	//check if leaf node
	if (this->value != 'h' && this->value != 'v') {
		return;
	}
	//check for empty right branch
	
	if (this->right == NULL) {
		node* temp;
		temp = new node(val);
		
		this->right = temp;
		return;
	}
	//check for empty right branch
	if (this->left == NULL) {
		node* temp;
		temp = new node(val);

		this->left = temp;
		return;
	}
	//continue down if full branches
	if (this->left != NULL) {
		this->left->insert(val);
		return;
	}

	//else {
		//cout << "Error 1" << endl;
	//}
	cout << "Error1" << endl;
	return;
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

