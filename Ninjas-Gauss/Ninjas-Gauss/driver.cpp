//Author: Kyle Cusack
//Date: 2-26-18
//Assignment: HW3-Newtons Interpolating Polynomial
//Description: Emulation of the Divided diffrence table and 
//checking error rate from measured function
//
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <cmath>
#include "Array.h"
#include "DivDiffTable.h"
#include "Poly.h"
#include "Interpolate.h"
#include "Chebyshev.h"
#include "Basefunction.h"

using namespace std;
int main(int argc, char *argv[])
{
	
	int numofpoints;
	try
	{
		if(argc != 3)
			throw invalid_argument("Argument List invalid");
	}
	catch(const invalid_argument& err)
	{
		cerr<<endl<<"ERROR: This program requires two argument, which must " <<
			"a integer first and then a readable file" << endl;
		
		return 1;
	}
	try
	{
		char *inttest = argv[1];
		while (*inttest != 0)
		{
			if (isdigit(*inttest))
			{
				inttest++;
			}
			else
			{
				throw invalid_argument("Argument one not of int type");
			}
		}
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: This program requires the first argument " <<
			"to be a int" << endl;

		return 1;
	}
	ifstream inputfile(argv[2]);
	try
	{
		if (!inputfile.is_open())
			throw invalid_argument("File cannot be opened");
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: Input file cannot be opened, "<<
		"Please have a readable txt file as first command line argument"<<endl;
		inputfile.close();
		return 1;
	}
	inputfile.clear();
	inputfile.seekg(0);
	inputfile >> numofpoints;
	DiffTable<double> Dtable;
	vector<Array<double>> results;
	vector<Array<double> > vtest(2);
	
	try
	{
		if (!isnormal(numofpoints) || (numofpoints <= 0))
			throw invalid_argument("First value is Invalid");
	}
	catch( const invalid_argument& err)
	{
		cerr << endl << "ERROR: The first number in the file should be a " <<
			"integer and non negative";
		return 1;
	}
	for (int q = 0; q < 2; q++)
	{
		vtest[q].setSize(numofpoints);
	}
	for (int i = 0; i < numofpoints; i++)
	{
		inputfile >> vtest[0][i];
		inputfile >> vtest[1][i];
	}
	double truncatetest = 0;
	int check = 0;
	try
	{
		inputfile.clear();
		inputfile.seekg(0);
		while (inputfile >> truncatetest)
		{
			check++ ;
		}
		if (check != (numofpoints*2 +1))
		throw invalid_argument("ERROR:More/less data to read after value specified");
	}
	catch (const invalid_argument& err)
	{
		cerr << endl << "ERROR: more/less data to read in after specified " <<
			"number of points. Truncated file input" << endl;
		return 1;
	}
	inputfile.close();
	results = Dtable(vtest);

	
	Interpolate<double> interp;
	interp.SetDiffTable(results);
	vector<double> estimatedvalues = interp(0.1,0.9,.2);

	vector<double> truevalues;
	for (double i = 0.1; i <= 0.9; i += 0.2)
	{
		double val = (1) / (1 + (12 * (pow(i, 2))));
		truevalues.push_back(val);
	}

	vector<double> absvalues;
	for (int i = 0; i < 5; i++)
	{
		absvalues.push_back(abs(truevalues[i] - estimatedvalues[i]));
	}
	vector<double> relvalues;
	for (int i = 0; i < 5; i++)
	{
		relvalues.push_back(absvalues[i] / truevalues[i]);

	}
	int nodestomake = atoi(argv[1]);
	Chebyshevx<double> cheby;
	Basefunction<double> mfunction;
	Array<double> Chvaluesx;
	Array<double> Chvaluesy;
	Chvaluesx = cheby(nodestomake);
	Chvaluesy = mfunction(Chvaluesx);
	cout << endl << "#CHEBYSHEV POINTS:" << endl;
	for (int i = 0; i < Chvaluesx.numofElts(); i++)
		cout << setprecision(13) << Chvaluesx[i]<<"  ,  "<<Chvaluesy[i] << endl;

	vector<Array<double> > chebresults(2);
	vector<Array<double> > chebdivtable;
	chebresults[0] = Chvaluesx;
	chebresults[1] = Chvaluesy;
	DiffTable<double> Chevtable;
	chebdivtable =  Chevtable(chebresults);
	vector<double> coefficentscheb;
	vector<double> interpolantcheb;
	vector<double> truecheb;
	Interpolate<double> chebinterp;
	chebinterp.SetDiffTable(chebdivtable);
	cout << endl << "#CHEBYSHEV_COEFFICENTS:" << endl;
	coefficentscheb= chebinterp(chebdivtable);
	for (int i = 0; i <= nodestomake; i++)
	{
		cout << setprecision(13) << coefficentscheb[i] << endl;
	}
	cout << endl << "#CHEBYSHEV_INTERPOLANTS:" << endl;
	interpolantcheb = chebinterp(0.1, 0.9, 0.2);
	for (int i = 0; i < (int)interpolantcheb.size(); i++)
	{
		cout << setprecision(13) << interpolantcheb[i] << endl;
	}
	cout << endl << "#TRUE_VALUES:" << endl;
	vector<double> truevaluescheb;
	for (double i = 0.1; i <= 0.9; i += 0.2)
	{
		double val = (1) / (1 + (12 * (pow(i, 2))));
		cout << setprecision(13) << val << endl;
		truevaluescheb.push_back(val);
	}
	cout << endl << "#ABSOLUTE_ERROR:" << endl;
	vector<double> absvaluescheb;
	for (int i = 0; i < 5; i++)
	{
		cout << setprecision(13) << abs(truevaluescheb[i] - interpolantcheb[i]) << endl;
		absvaluescheb.push_back(abs(truevaluescheb[i] - interpolantcheb[i]));
	}
	cout << endl << "#RELATIVE_ERROR:" << endl;
	vector<double> relativecheb;
	for (int i = 0; i < 5; i++)
	{
		relativecheb.push_back(absvaluescheb[i] / truevaluescheb[i]);
		cout << setprecision(13) << abs(absvaluescheb[i] / truevaluescheb[i]) * 100 << endl;

	}
	cout << endl << "#RELATIVE_CHANGE:" << endl;
	vector<double> relvaluescheb;
	for (int i = 0; i < 5; i++)
	{
		relvaluescheb.push_back(abs(estimatedvalues[i] - interpolantcheb[i]));
	}
	for (int i = 0; i < 5; i++)
	{
		cout << setprecision(13) << abs(relvaluescheb[i]/ estimatedvalues[i]) * 100 << endl;

	}

    return 0;
}