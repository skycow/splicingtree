//Skyler Cowley
//A01209720
//ECE 5460
//HW4

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
	
	//HW4
	//Parameters
		int nmoves = 10;
	//double ratio = 0.85;
	//int t0 = -1;
	double lambdatf = 0.005;
	int iseed = 3;
	//int n = 6;
	//double P = 0.99;
	double epsilon = 0.001;
	int N = npe3.size()*nmoves;

	srand(3);





	int Random;// = rand(); //= random number
	
	string E0 = npe3; //initial solution
	string E = E0;
	string best = E0;
	int t0 = -1;
	int uphill = 0;
	int MT = 0;
	int T = t0;

	int Reject;
	double dCost;
	string newE;
	
	//repeat1
	do{
		MT = 0;
		uphill = 0;
		Reject = 0;
		//repeat2
		do{

			bool moved = false;
			while (!moved) {
				newE = E; //?
				Random = rand();
				cout << "Random number: " << Random << endl;
				switch (Random%3) {
					//m1: swap adjecent operands 
				case(0) : {

					//get a random place in the string
					//for (int i = 0; i < E.size(); i++) {
					int mRand = Random%E.size();
					//find an operand
					while (E[mRand] == 'H' || E[mRand] == 'V') {
						//move left
						mRand -= 1;
					}
					if (mRand == 0) {
						int mRand2 = mRand + 1;
						while (npe3[mRand2] == 'H' || npe3[mRand2] == 'V') {
							//move left
							mRand2 += 1;
						}
						char temp = newE[mRand];
						newE[mRand] = newE[mRand2];
						newE[mRand2] = temp;
					}
					else {
						int mRand2 = mRand - 1;
						while (npe3[mRand2] == 'H' || npe3[mRand2] == 'V') {
							//move left
							mRand2 -= 1;
						}
						char temp = newE[mRand];
						newE[mRand] = newE[mRand2];
						newE[mRand2] = temp;
					}
					//cout << newE << endl;
				//}
					moved = true;
					break;
				}
						  //M2
				case(1) : {
					//cout << "s:" << E << endl;
					//for (int i = 0; i < E.size(); i++) {
					newE = E;

					int mRand = Random%E.size();
					//find an operand
					while (E[mRand] != 'H' && E[mRand] != 'V') {
						//move right
						mRand += 1;
					}
					//move to the right of the chain
					while ((E[mRand] == 'H' || E[mRand] == 'V') && mRand != E.size() - 1) {
						mRand += 1;
					}
					if (mRand != E.size() - 1) {
						mRand -= 1;
					}
					while (E[mRand] == 'H' || E[mRand] == 'V') {
						//change current
						if (E[mRand] == 'H') {
							newE[mRand] = 'V';
						}
						else {
							newE[mRand] = 'H';
						}
						mRand -= 1;
					}
					//cout << "e:" << newE<<endl;
				//}
					moved = true;
					break;
				}
						  //M3
				case(2) : {
					newE = E;
					int mRand = Random%E.size();
					bool check = false;

					//check left
					if (mRand != 0) {
						//if h or v
						if (E[mRand] == 'H' || E[mRand] == 'V') {
							//if left is not h or v
							if (E[mRand - 1] != 'H' && E[mRand - 1] != 'V') {
								char temp = newE[mRand];
								newE[mRand] = newE[mRand - 1];
								newE[mRand - 1] = temp;
								cout << "break 1" << endl;
								check = true;
							}
						}
						//if not h or v
						else {
							//if left is h or v
							if (E[mRand - 1] == 'H' || E[mRand - 1] == 'V') {
								char temp = newE[mRand];
								newE[mRand] = newE[mRand - 1];
								newE[mRand - 1] = temp;
								cout << "break 2" << endl;
								check = true;
							}
						}
					}
					else if (mRand != E.size() - 1) {
						//if h or v
						if (E[mRand] == 'H' || E[mRand] == 'V') {
							//if left is not h or v
							if (E[mRand + 1] != 'H' && E[mRand + 1] != 'V') {
								char temp = newE[mRand];
								newE[mRand] = newE[mRand + 1];
								newE[mRand + 1] = temp;
								cout << "break 3" << endl;
								check = true;
							}
						}
						//if not h or v
						else {
							//if left is h or v
							if (E[mRand + 1] == 'H' || E[mRand + 1] == 'V') {
								char temp = newE[mRand];
								newE[mRand] = newE[mRand + 1];
								newE[mRand + 1] = temp;
								cout << "break 4" << endl;
								check = true;
							}
						}
					}
					else {
						break;
						cout << "false" << endl;
					}
					//if chekc is true then a move has occurred
					bool valid = false;
					//check for balloting 
					if (check) {
						int operators = 0;//hv
						int operands = 0;//#
						int check1cnt = 0;
						while (operands >= operators && check1cnt < newE.size()) {
							if (newE[check1cnt] == 'H' || newE[check1cnt] == 'V') {
								operators += 1;
							}else{
								operands += 1;
							}
							check1cnt += 1;
						}
						cout << "operands: " << operands << " and operators: " << operators << endl;
						if(operands < operators) {
							check = false;
							cout << "check is false" << endl;
						}
					}
					//check for normailization (double letter)
					if (check) {
						int check2cnt = 0;
						while ((newE[check2cnt] != newE[check2cnt+1] ) && check2cnt < newE.size()-1) {
							check2cnt += 1;
						}

						if (check2cnt == newE.size() - 1) {
							if ((newE[check2cnt-1] == newE[check2cnt])) {
								check = false;
							}
						}
						else if ((newE[check2cnt] == newE[check2cnt + 1])) {
							check = false;
						}
					}

					if (!moved) {
						if (check) {
							moved = true;
						}
					}
					//a move did not occur 
					
					break;
				}
				}
			}
			
			
			MT += 1;
			dCost = cost(name, input, newE) - cost(name, input, E);
			if(dCost < 0 || Random < exp(-dCost/T)){
				if(dCost > 0){
					uphill += 1;
					cout << "Uphill: " << uphill << endl;
					E = newE;
				}
				if(cost(name, input, E) < cost(name, input, best)){
					best = E;
				}
			}else{
				Reject += 1;
				cout << "Reject: " << Reject<<endl;
			}
			cout << uphill << " <= " << N << endl;
			cout << MT << "<= " << 2 * N << endl;
		}while (uphill <= N && MT <= 2 * N);
		T = lambdatf*T;
	}while (Reject / MT <= 0.95 && T > epsilon);


	//end HW4
	
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
