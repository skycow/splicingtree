#pragma once
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <iostream>
#include <string>

using namespace std;

class dim {
	double height;
	double width;
	dim* next;
public:
	dim(double, double);
	void instert(dim*);
	double findMin();
	double findMin(double);
	double area();

};

class node {
	char value;
	node* left;
	node* right;
	double height;
	double width;
	dim* dims;
public:
	node(char);
	node(char, double, double);
	void insert(node*);
	void printTree(int);
	double calculate();

};




#endif