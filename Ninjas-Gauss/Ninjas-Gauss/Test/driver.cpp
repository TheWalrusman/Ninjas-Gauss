//Author: Kyle Cusack
//Date: 2-26-18
//Assignment: HW3-Newtons Interpolating Polynomial
//Description: Emulation of the Divided diffrence table and 
//checking error rate from measured function
//
#include <cstdio>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <cmath>
#include "Array.h"
#include "Matrix.h"
#include "GaussSolve.h"

using namespace std;
int main(int argc, char *argv[])
{

	


	int numofpoints;
	try
	{
		if (argc != 2)
			throw invalid_argument("Argument List invalid");
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: This program requires one argument " <<
			"a readable file" << endl;

		return 1;
	}
	
	ifstream inputfile(argv[1]);
	try
	{
		if (!inputfile.is_open())
			throw invalid_argument("File cannot be opened");
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: Input file cannot be opened, " <<
			"Please have a readable txt file as first command line argument" << endl;
		inputfile.close();
		return 1;
	}
	inputfile.clear();
	inputfile.seekg(0);
	inputfile >> numofpoints;

	try
	{
		if (!isnormal(numofpoints) || (numofpoints <= 0))
			throw invalid_argument("First value is Invalid");
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: The first number in the file should be a " <<
			"integer and non negative";
		return 1;
	}
	double truncatetest = 0;
	int check = 0;
	try
	{
		inputfile.clear();
		inputfile.seekg(0);
		while (inputfile >> truncatetest)
		{
			check++;
		}
		if (check != ((numofpoints * numofpoints)+numofpoints+1))
			throw invalid_argument("ERROR:More/less data to read after value specified");
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: more/less data to read in after specified " <<
			"number of points. Truncated file input" << endl;
		return 1;
	}

	Matrix<double> baseA((int)numofpoints,(int)numofpoints);
	Matrix<double> linsys((int)numofpoints + 1, (int)numofpoints);

	inputfile.clear();
	inputfile.seekg(0);
	double inputtmp = 0;
	inputfile >> inputtmp;

	inputfile >> baseA;

	inputfile.clear();
	inputfile.seekg(0);
	inputtmp = 0;
	inputfile >> inputtmp;

	inputfile >> linsys;

	cout << endl << "#A*TRANSPOSE(A)" << endl;

	Matrix<double> TranResult;
	TranResult = baseA * baseA.Transpose();
	TranResult.examine();

	

	
	GaussSolve<double> Gauss;
	Matrix<double> test32;
	
	test32 = Gauss(linsys,true);
	cout << endl << "#X-Vector" << endl;

	cout << test32[numofpoints];

	cout << endl << "#A*X" << endl;
	cout << linsys[numofpoints];

	return 0;
}