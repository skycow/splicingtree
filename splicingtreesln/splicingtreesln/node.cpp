#include "node.h"

dim::dim(double h, double w) {
	height = h;
	width = w;
	next = NULL;
}

void dim::insert(dim* in) {
	if (this->next == NULL) {
		this->next = in;
	}
	else {
		this->next->insert(in);
	}
}

double dim::findMin() {
	double curr = (this->height * this->width);
	if (this->next != NULL) {
		double next = this->next->findMin();
		if (next < curr){
			return next;
		}
	}
	return curr;
}

node::node(char newName) {
	value = newName;
	left = NULL;
	right = NULL;
	height = NULL;
	width = NULL;
	//dims = NULL;
}

node::node(char newName, double h, double w) {
	value = newName;
	left = NULL;
	right = NULL;
	height = h;
	width = w;
	pair<double, double> newDim(h,w);
	
	dims.push_back(newDim);
	if (h != w){
		newDim.first = w;
		newDim.second = h;
		dims.push_back(newDim);
	}

	//dim* dim1, *dim2;
	//dim1 = new dim(h, w);
	//dims = dim1;
	//if (h != w){
	//	dim2 = new dim(w, h);
	//	dims->insert(dim2);
	//}

}

bool node::insert(node* newNode) {

	//check if leaf node
	if (this->value != 'h' && this->value != 'v') {
		return false;
	}
	//check for empty right branch
	bool success;
	if (this->right == NULL && this->value != newNode->value) {		
		this->right = newNode;
		return true;
	}
	else {
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
		if (this->left->insert(newNode)) {
			return true;
		}
		else {
			//cout << "Error 1" << endl;
		}
	}
	//cout << "Error 1.2" << endl;
	return false;
	////continue down if full branches
	//if (this->left != NULL) {
	//	this->left->insert(newNode);
	//	return;
	//}
	//
	////else {
	//	//cout << "Error 1" << endl;
	////}
	//cout << "Error1" << endl;
	//return;
}

double node::calculate(){
	if (this->left == NULL && this->right == NULL) {
		return this->findMin();
	}
	if (this->right != NULL){
		this->right->calculate();
	}
	if (this->left != NULL){
		this->left->calculate();
	}
	if (this->value == 'h') {
		this->calculateH(this->right->dims, this->left->dims);
	}
	if (this->value == 'v') {
		this->calculateV(this->right->dims, this->left->dims);
	}

	return this->findMin();
		
}

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





/*
double node::calculate() {
	
	if (this->left == NULL && this->right == NULL) {
		return this->dims->findMin();
	}
	if (this->right != NULL){
		this->right->calculate();
	}
	if (this->left != NULL){
		this->left->calculate();
	}
	
	if (this->value == 'h')
	//max add
	this->dims = this->right->dims->calcDimsH(this->left->dims);


	//if (this->value == 'v')
	//add max
	//this->dims = this->right->dims->calcDimsV(this->left->dims);

	//this->dims->discard();
	
	return this->dims->findMin();
}*/

dim* dim::calcDimsH(dim* left){
	if (this->next == NULL){
		return left->calcDimsH(this->height, this->width);	
	}
	return left->calcDimsH(this->height, this->width, this->next->calcDimsH(left));
}

dim* dim::calcDimsH(double height, double width, dim* prev){
	if (this->next == NULL){
		dim* newAdd;
		if (this->width > width){
			newAdd = new dim(this->height + height, this->width);
		}
		else{
			newAdd = new dim(this->height + height, width);
		}
		newAdd->next = prev;
		return newAdd;

	}
	else{

		dim* newAdd;
		if (this->width > width){
			newAdd = new dim(this->height + height, this->width);
		}
		else{
			newAdd = new dim(this->height + height, width);
		}

		newAdd->next = this->next->calcDimsH(height, width, prev);
		return newAdd;
	}
}

dim* dim::calcDimsH(double height, double width){
	if (this->next == NULL){
		dim* newAdd;
		if (this->width > width){
			newAdd = new dim(this->height + height, this->width);
		}
		else{
			newAdd = new dim(this->height + height, width);
		}
		return newAdd;

	}
	else{

		dim* newAdd;
		if (this->width > width){
			newAdd = new dim(this->height + height, this->width);
		}
		else{
			newAdd = new dim(this->height + height, width);
		}

		newAdd->next = this->next->calcDimsH(height, width);
		return newAdd;
	}
}

void dim::discard(){
	dim minDim = this->min(this->height, this->width);

	this->discard(minDim.height, minDim.width);
}

void dim::discard(double h, double w){
	if (this->next == NULL){
		return;
	}
	else{
		this->next->discard(h, w);
	}

	if (this->next->next == NULL){

		if (this->next->height > h && this->next->width > w){
			delete this->next;
			this->next = NULL;
			return;
		}
		else{
			return;
		}
	}

	
	if (this->next->height > h && this->next->width > w){
		dim *temp = this->next->next;
		delete this->next;
		this->next = temp;
		return;
	}
	else{
		return;
	}
}

dim dim::min(){
	if (this->next == NULL){
		dim ret(this->height, this->width);
		return ret;
	}
	else{
		dim ret = this->next->min();


		if (this->height < ret.height && this->width < ret.width){
			dim res(this->height, this->width);
			return res;
		}
		else{
			return ret;
		}
	}
	//return this->min(this->height, this->width);
}

dim dim::min(double mh, double mw){
	if (this->next == NULL){
		if (this->height < mh && this->width < mw){
			dim ret(this->height, this->width);
			return ret;
		}
		else{
			dim ret(mh, mw);
			return ret;
		}
	}
	else{
		dim minDim = this->min(this->height, this->width);
	}
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

