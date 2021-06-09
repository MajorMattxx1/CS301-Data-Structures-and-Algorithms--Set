// SetDataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SetT.h"

using namespace std;

int main()
{
	// You should create your own test driver that takes input files and generates output files.
	// The input/output should demonstrate functionality of the SetT ADT
	// (The input below is NOT sufficient for full testing)
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

	return 0;
}
