#pragma once
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

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
	void printTree(int);

};

#endif