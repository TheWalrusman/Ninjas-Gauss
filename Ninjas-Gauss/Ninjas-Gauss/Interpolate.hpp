#ifndef INTERPOLATE_HPP
#define INTERPOLATE_HPP

using namespace std;
template<class T>
inline void Interpolate<T>::SetDiffTable(const std::vector<Array<T>>& difftable)
{
	divtable = difftable;
}


template<class T>
inline std::vector<T> Interpolate<T>::operator()(const double start, const double end, const double step)
{
	int totalpoints = divtable[0].numofElts();
	std::vector<T> values;
	vector<T> totalpoly;
	//vector<vector<T>> testpoly(15);
	totalpoly.resize(1);
	for (double i = start; i <= end; i += step)
	{
		double currentpoint = 0;
		//cout << endl;
		for (int q = 0; q < totalpoints; q++)
		{
			double startval = 1;
			for (int c = 0; c < q; c++)
			{
				startval *= (i - (divtable[0][c]));
				//cout <<setprecision(5)<< "( " << 'x' << " - " << divtable[0][c] << " ) * ";
				//testpoly[q].push_back(1);
				//testpoly[q].push_back(divtable[0][c]);
			}

			currentpoint += startval * (divtable[q + 1][q]);
			//testpoly[q].push_back(divtable[q + 1][q]);
			//cout <<setprecision(5)<< "( " << divtable[q + 1][q] << " )"<<endl;
		}
		//std::cout <<std::setprecision(13) << currentpoint << std::endl;
		values.push_back(currentpoint);

	}



	return values;
}

template<class T>
inline std::vector<T> Interpolate<T>::operator()(const std::vector<Array<T>>& table)
{
	(void)table;
	int totalpoints = divtable[0].numofElts();
	std::vector<T> values;
	vector<T> totalpoly;
	//vector<vector<T>> testpoly(15);
	totalpoly.resize(1);
	Polynomial<T> polyp;
	vector<T> results = { 1 };
	vector<double> interone = { 1 };
	vector<T> endresults;
	double currentpoint = 0;
	//cout << endl;
	for (int q = 0; q < totalpoints; q++)
	{
		double startval = 1;
		interone = { 1 };

		for (int c = 0; c < q; c++)
		{
			if (c == 0)
				interone = { (divtable[0][c] * (-1)),1 };
			else
			{
				//cout << setprecision(5) << "( " << 'x' << " - " << divtable[0][c] << " ) * ";
				//testpoly[q].push_back(1);
				//testpoly[q].push_back(divtable[0][c] * (-1));
				vector<T> intermediate = { (divtable[0][c] * (-1)),1 };
				interone = polyp.multiplypolys(interone, intermediate);
			}
			
		}

		currentpoint += startval * (divtable[q + 1][q]);
		//testpoly[q].push_back(divtable[q + 1][q]);
		//cout << setprecision(5) << "( " << divtable[q + 1][q] << " )" << endl;
		vector<T> interend = { (divtable[q + 1][q]) };
		results = polyp.multiplypolys(interone, interend);
		endresults = polyp.addpolys(endresults,results);
	}
	//std::cout << std::setprecision(13) << currentpoint << std::endl;
	values.push_back(currentpoint);


	return endresults;
}








#
#endif
