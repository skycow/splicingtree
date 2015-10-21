//Skyler Cowley
//A01209720
//ECE 5460
//HW3

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include "node.h"

using namespace std;

//prototypes
double cost(string[], double[][30], string);

//this is the main function for calculating floor plan topologies
//from the splicing method
int main() {

	//variable declerations
	string name[30];
	double input[2][30];
	string line;
	ifstream fin("input.txt");

	//reading in the contents of the file
	if (fin.is_open()) {
		int count = 0;
		while (getline(fin, line)) {
			istringstream individual(line);
			individual >> name[count];
			individual >> input[0][count];
			individual >> input[1][count];
			count = (count + 1);
		}
	}
	else {
		//file open error
		cout << "Unable to open file." << endl;
	}

	//input NPEs
	string npe1 = "12V3V4V5V6V7V8V9VaVbVcVdVeVfVgViVjVkVlV";
	string npe2 = "12H3H4H5H6H7H8H9HaHbHcHdHeHfHgHiHjHkHlH";
	string npe3 = "213546H7VHVa8V9HcVHgHibdHkVHfeHVlHVjHVH";

	//test
	//for (int i = 0; i < 10; i++){
		//test

		//output and cost call
		cout << "The area for NPE " << npe1 << " is ";
		cout << cost(name, input, npe1) << endl;
		cout << "The area for NPE " << npe2 << " is ";
		cout << cost(name, input, npe2) << endl;
		cout << "The area for NPE " << npe3 << " is ";
		cout << cost(name, input, npe3) << endl;

	//keep open to see results
	cout << "Press enter to exit: ";
        getchar();
        //cin.get();

	//exit program
	return 0;
}

double cost(string name[], double input[][30], string npe) {
	//create tree
	node* root = NULL;

	//insert nodes beginning from the right side of the NPE
	for (int i = 1; i <= npe.size(); i++) {
		//current position
		int curr = npe.size() - i; 
		//current character value
		char value = npe[curr];
		node* temp;
		double height, width;
		//if the value is a leaf value find the index
		if (value != 'H' && value != 'V') {
			int count = 0;
			while (value != name[count][0]){
				count++;
			}
			//calculate height and width for the leaf nodes
			height = sqrt(input[0][count] / input[1][count]);
			width = input[0][count] / height;
			//create leaf node
			temp = new node(value, height, width);
		}
		else {
			//create h or v node
			temp = new node(value);
		}
		//start the tree if it doesn't exist
		if (root == NULL) {
			
			root = temp;
		}
		else {
			//insert new nodes
			root->insert(temp);
		}

	}

	//calculates the area from the tree
	double area = root->calculate();
	//returns the area value to main
	return area;
}
