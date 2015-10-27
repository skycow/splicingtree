//Skyler Cowley
//A01209720
//ECE 5460
//HW3

#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

//this is the node class for the splicing tree algorithm
class node {
	char value;
	node* left;
	node* right;
	double height;
	double width;
	vector<pair<double, double> > dims;
	
public:
	node(char);
	node(char, double, double);
	bool insert(node*);
	double findMin();
	double calculate();
	void calculateH(vector<pair<double, double> >, vector<pair<double, double> >);
	void calculateV(vector<pair<double, double> >, vector<pair<double, double> >);

};

#endif
