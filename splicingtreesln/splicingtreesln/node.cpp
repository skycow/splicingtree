#include <iostream>
#include <string>

using namespace std;

class node {
	char value;
	node* left;
	node* right;
public:
	node(char);
	void insert(char);

};

node::node(char newName) {
	value = newName;
	left = NULL;
	right = NULL;
}

void node::insert(char val) {

	//check if leaf node
	if (this->value != 'h' || this->value != 'v') {
	}
	//check for empty right branch
	else if (this->right == NULL) {

		node* temp;
		temp = new node(val);
		
		this->right = temp;
	}
	//check for empty right branch
	else if (this->left == NULL) {
		node* temp;
		temp = new node(val);

		this->left = temp;
	}
	//continue down if full branches
	else if (this->left != NULL) {
		this->left->insert(val);
	}
	else {
		cout << "Error 1" << endl;
	}
	return;
}


