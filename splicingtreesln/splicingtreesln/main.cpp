#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "node.cpp"

using namespace std;

int cost(string[], double[][30], string);

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

	string npe1 = "12v3v4v5v6v7v8v9vavbvcvdvevfvgvivjvkvlv";
	int area;
	area = cost(name, input, npe1);

	

	return 0;
}

int cost(string name[], double input[][30], string npe) {

	//node* root = NULL;

	for (int i = 1; i <= npe.size(); i++) {
		//cout << npe[npe.size() - i];
		//if (root == NULL) {
			//node* temp;
			//temp = new node(npe[npe.size() - i]);
			//root = temp;
		//}
		//else {
		//	root->insert(npe[npe.size() - i]);
		//}

	}

	return 0;
}
