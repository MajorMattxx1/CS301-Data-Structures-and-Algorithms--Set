// SetDataStructure.cpp : Defines the entry point for the console application.
//

#include "SetT.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
	/* You should create your own test driver that takes input files and generates output files.
	 The input/output should demonstrate functionality of the SetT ADT
	 (The input below is NOT sufficient for full testing)
	SetT<int> a;
	SetT<int> b;
	b.Add(7);
	b.Add(9);
	a.Add(1);
	a.Add(1);
	a.Add(2);
	a.Add(3);
	a.Add(4);
	a.Add(5);
	a + 6;
	a + b;
	a - b;
	*/


	ofstream outFile;
	ifstream inFile;

	SetT<int> A;
	SetT<int> B;

	outFile.open("SetOutput.txt");
	inFile.open("SetTestInput.txt");

	if (!inFile) {
		cout << "File not found!" << endl;
		exit(0);
	}

	string command;
	inFile >> command;
	while (command != "quit") {
		if (command == "Add ") {
			char set;
			inFile >> set;
			int num;
			inFile >> num;
			if (set == 'A')
			{
				A + num;
			}
			else
			{
				B + num;
			}
			outFile << "Adding " << num << "to " << set << endl;
		}

		else if (command == "Remove") {
			char set;
			inFile >> set;
			int num;
			inFile >> num;
			if (set == 'A')
			{
				A - num;
			}
			else
			{
				B - num;
			}
			outFile << "Removing " << num << "from " << set << endl;
		}
		
		else if (command == "Intersection") {
			char set;
			inFile >> set;
			int num;
			inFile >> num;
			A*B;
			outFile << "Intersectioning" << endl;
		}
		
		else if (command == "Union") {
			char set;
			inFile >> set;
			int num;
			inFile >> num;
			A+B;
			outFile << "Unioning" << endl;
		}

		else if (command == "Difference") {
			char set;
			inFile >> set;
			int num;
			inFile >> num;
			A - B;
			outFile << "Differencing" << endl;
		}

		else if (command == "Size") {
			char set;
			inFile >> set;
			if (set == 'A')
			{
				outFile << "Size of " << set << ": " << A.Size() << endl;//set variable isn't very necessary here
			}
			else
			{
				outFile << "Size of " << set << ": " << B.Size() << endl;//set variable isn't very necessary here
			}
			
		}

		else if (command == "Print") {
			char set;
			inFile >> set;
			if (set == 'A')
			{
				A.Traverse();
			}
			else
			{
				B.Traverse();
			}
		}

		else if (command == "Quit") {
			return 0;
		}
		inFile >> command;
	}
	return 0;
}
