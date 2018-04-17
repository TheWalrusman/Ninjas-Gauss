#pragma once
#ifndef GAUSSSOLVE_HPP
#define GAUSSSOLVE_HPP



template<class T>
inline Matrix<T> GaussSolve<T>::operator()(Matrix<T>& base,const bool swapornot)
{
	
	Matrix<T> tmp;
	tmp = base;
	//tmp.examine();
	


	for (int diag = 0; diag < base.getheight(); diag++)
	{

		T largestval = 0;
		int maxvect = -1;
		maxvect++;
		int maxdepth;
		if (swapornot == true)
		{
			for (int row = diag; row < base.getheight(); row++)
			{
				if (std::abs(tmp[diag][row]) > largestval)
				{
					largestval = std::abs(tmp[diag][row]);
					maxvect = row;
				}

			}

			tmp.rowswap(diag, maxvect);
			maxdepth = tmp.getheight();
		}
		else
		{
			maxdepth = tmp.getheight() - 1;
		}
		
		tmp = tmp.Transpose();
		if (tmp[diag][diag] != 1)
		{
			tmp[diag] = tmp[diag] * (1/tmp[diag][diag]);
			//tmp.examine();
		}
		//T minval = tmp[diag][diag];
		for (int red = 0; red < diag; red++)
		{
			if (tmp[red][diag] != 0)
			{

				T valtozero = tmp[red][diag];
				T multvalue = valtozero;
				if (valtozero + multvalue != 0)
				{
					multvalue *= -1;
				}
				tmp[red] = (tmp[diag] * multvalue) + tmp[red];
				//tmp.examine();
			}
		}
		for (int red = diag+1; red < maxdepth; red++)
		{
			if (tmp[red][diag] != 0 )
			{
				
				T valtozero = tmp[red][diag];
				T multvalue = valtozero;
				if (valtozero + multvalue != 0)
				{
					multvalue *= -1;
				}
				tmp[red] = (tmp[diag] * multvalue) + tmp[red];
				//tmp.examine();
			}
		}
		//tmp.examine();
		tmp = tmp.Transpose();
		//tmp.examine();



	}





	return tmp;
}








#endif // !GaussSolve