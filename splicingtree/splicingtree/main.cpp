#include<iostream>
#include<fstream>

using namespace std;

int main() {

	double input[3][25];

	ifstream fin("input.txt");

	if (fin.good()) {
		cout << "We're good" << endl;
		int test;
		fin >> test;
		cout << test << endl;
	}
	else {
		cout << "We're not good" << endl;
	}

	

	return 0;
}