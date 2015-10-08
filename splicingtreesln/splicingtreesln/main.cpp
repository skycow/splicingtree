#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "node.h"

using namespace std;

double cost(string[], double[][30], string);

int main() {

	//enum indexNames {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f, g, i, j, k, l };

	string name[30];
	double input[2][30];
	string line;
	ifstream fin("input.txt");

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
		cout << "Unable to open file." << endl;
	}

	//string npe1 = "12v3v4v5v6v7v8v9vavbvcvdvevfvgvivjvkvlv";
	string npe2 = "12h3h4h5h6h7h8h9hahbhchdhehfhghihjhkhlh";
	//cout << cost(name, input, npe1) << endl;
	cout << cost(name, input, npe2) << endl;
	

	return 0;
}

double cost(string name[], double input[][30], string npe) {
	//create tree
	node* root = NULL;

	//insert nodes
	for (int i = 1; i <= npe.size(); i++) {
		int curr = npe.size() - i; 
		char value = npe[curr];
		node* temp;
		double height, width;
		if (value != 'h' && value != 'v') {
			int count = 0;
			while (value != name[count][0]){
				count++;
			}
			height = sqrt(input[0][count] / input[1][count]);
			width = input[0][count] / height;

			cout << height << " and " << width << endl;
			
			temp = new node(value, height, width);
		}
		else {
			temp = new node(value);
		}

		if (root == NULL) {
			
			root = temp;
		}
		else {
			root->insert(temp);
		}

	}

	//print tree
	if (root != NULL) {
		root->printTree(0);
	}

	double area = root->calculate();

	return area;
}
