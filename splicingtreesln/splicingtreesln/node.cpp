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

	node* temp;
	temp = new node(val);

	if (this->right == NULL) {
		if (this->value != val) {
			this->right = temp;
		}
	}
}


