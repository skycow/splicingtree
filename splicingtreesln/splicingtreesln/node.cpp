#include "node.h"

//node constructer that takes a char
node::node(char newName) {
	value = newName;
	left = NULL;
	right = NULL;
	height = NULL;
	width = NULL;
	//dims = NULL;
}

//node constructor that takes a char and 2 doubles
node::node(char newName, double h, double w) {
	value = newName;
	left = NULL;
	right = NULL;
	height = h;
	width = w;
	pair<double, double> newDim(h,w);
	dims.push_back(newDim);
	//adds the second orientation unless it is a square
	if (h != w){
		newDim.first = w;
		newDim.second = h;
		dims.push_back(newDim);
	}
}

//this function inerts nodes into a splicing tree
bool node::insert(node* newNode) {

	//check if leaf node
	if (this->value != 'H' && this->value != 'V') {
		return false;
	}
	//check for empty right branch
	if (this->right == NULL && this->value != newNode->value) {		
		this->right = newNode;
		return true;
	}
	else {
		//progress down the right branch
		if (this->right->insert(newNode)) {
			return true;
		}
	}

	//check for empty right branch
	if (this->left == NULL) {
		this->left = newNode;
		return true;
	}
	else {
		//progress further down the left branch
		if (this->left->insert(newNode)) {
			return true;
		}
	}
	return false;
}

//this function calculates the possible dimensions and orientations for the
//h and v nodes in the tree and returns the minimum area from the top node
double node::calculate(){
	//check for leaf node and end of branch
	if (this->left == NULL && this->right == NULL) {
		return this->findMin();
	}
	//move down the right branch
	if (this->right != NULL){
		this->right->calculate();
	}
	//move down the left branch
	if (this->left != NULL){
		this->left->calculate();
	}
	//if the node is an h, calculate the dimensions and orientations
	if (this->value == 'H') {
		this->calculateH(this->right->dims, this->left->dims);
	}
	//if the node is an v, calculate the dimensions and orientations
	if (this->value == 'V') {
		this->calculateV(this->right->dims, this->left->dims);
	}
	//returns the area
	return this->findMin();		
}

//this function calculates the minimum area from a list of dimensions and orientations
double node::findMin() {
	double area = 0, curr;
	for (int i = 0; i < dims.size(); i++) {
		curr = dims[i].first * dims[i].second;
		if (area == 0) {
			area = curr;
		}
		else if (curr < area) {
			area = curr;
		}
	}

	return area;
}

//this function calculates the possible dimensions and orientations of an h node
//it takes the two lists of dimensions and orientations from the h nodes children
void node::calculateH(vector<pair<double, double>> right, vector<pair<double, double>> left) {
	for (int i = 0; i < right.size(); i++) {
		for (int j = 0; j < left.size(); j++) {
			double max;
			if (right[i].second > left[j].second) {
				max = right[i].second;
			}
			else {
				max = left[j].second;
			}

			pair<double, double> newDim(right[i].first + left[j].first, max);
			this->dims.push_back(newDim);
		}
	}
}

//this function calculates the possible dimensions and orientations of an v node
//it takes the two lists of dimensions and orientations from the v nodes children
void node::calculateV(vector<pair<double, double>> right, vector<pair<double, double>> left) {
	for (int i = 0; i < right.size(); i++) {
		for (int j = 0; j < left.size(); j++) {
			double max;
			if (right[i].first > left[j].first) {
				max = right[i].first;
			}
			else {
				max = left[j].first;
			}

			pair<double, double> newDim(max, right[i].second + left[j].second);
			this->dims.push_back(newDim);
		}
	}
}



