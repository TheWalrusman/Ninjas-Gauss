#ifndef DIVDIFFTABLE_HPP
#define DIVDIFFTABLE_HPP

using namespace std;
template<class T>
inline vector<Array<T>> DiffTable<T>::operator()(const std::vector<Array<T>>& xy)
{
	std::vector<Array<T> > tmp;
	tmp = xy;
	//tmp[0][0] = 20;
	int maxwidth = 2 + (xy[0].numofElts() - 1);
	tmp.resize(maxwidth);
	//std::cout << "HELLO"<<std::endl;

	for (int i = 2; i < maxwidth; i++)
	{
		//std::cout << i<<std::endl;
		tmp[i].setSize(xy[0].numofElts());
	}
	for (int y = 0; y < xy[0].numofElts(); y++)
	{
		for (int x = 0; x < 2; x++)
		{
			//cout << xy[x][y] << "\t";
		}
		//cout << endl;
	}

	//for (int xdiff = 1; xdiff < xy[0].numofElts(); xdiff++)
	//{
	for (int col = 1; col < maxwidth; col++)
	{

		for (int value = 0; value < xy[0].numofElts() - col; value++)
		{
			double ans = 0;
			double x1 = tmp[0][value];
			double x2 = tmp[0][col + value];
			double y1 = tmp[col][col + value - 1];
			double y2 = tmp[col][col + value];
			try
			{
				if ((x2 - x1) == 0)
					throw overflow_error("Divison by zero not allowed");
			}
			catch (const overflow_error& err)
			{
				cerr << endl << "ERROR: The divided diffrence table has " <<
					"to divide by zero. please check input points."<<endl;
				exit(EXIT_FAILURE);
			}
			ans = (y2 - y1) / (x2 - x1);
			//cout << endl << ans << endl;;
			tmp[col + 1][value + col] = ans;
			//cout << endl;

			


		}

		//cout << endl << "NEW ROW" << endl;
	}
	for (int y = 0; y < xy[0].numofElts(); y++)
	{
		for (int x = 0; x < maxwidth; x++)
		{
			//cout << tmp[x][y] << "\t";
		}
		//cout << endl<<endl;
	}

	//}

	for (int i = 0; i < maxwidth - 1; i++)
	{
		//cout << endl <<setprecision(13)<< tmp[i+1][i ] << endl;
	}



	//std::cout << "This is the end" << std::endl;
	return tmp;
}



#endif