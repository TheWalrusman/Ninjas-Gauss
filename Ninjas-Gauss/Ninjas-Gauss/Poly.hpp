


#ifndef POLY_HPP
#define POLY_HPP





template<class T>
inline vector<T> Polynomial<T>::multiplypolys(const vector<T>& lp, const vector<T>& rp)
{

	vector<T> result;
	result.resize(lp.size() + rp.size()+1);
	for (int i = 0; i < (int)lp.size(); i++)
	{
		for (int q = 0; q < (int)rp.size(); q++)
		{
			result[i + q] += lp[i] * rp[q];
		}
	}




	return result;
}



template<class T>
inline vector<T> Polynomial<T>::addpolys(const vector<T>& lp, const vector<T>& rp)
{
	vector<T> result;
	result.resize(max(lp.size(), rp.size()));
	for (int i = 0; i < (int)lp.size(); i++)
		result[i] += lp[i];
	for (int i = 0; i < (int)rp.size(); i++)
		result[i] += rp[i];



	return result;
}





#endif // !POLY_HPP

