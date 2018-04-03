


#ifndef CHEBYSHEV_HPP
#define CHEBYSHEV_HPP

template<class T>
inline Array<T> Chebyshevx<T>::operator()(const int nodes)
{
	Array<T> xnodes;
	xnodes.setSize(nodes+1);

	for (int i = 0; i <= nodes; i++)
	{
		double p1 = (2 * nodes) + 1 - (2 * i);
		double p2 = (PI) / ((2 * nodes) + 2);
		xnodes[i] = cos(p1 * p2);
		

	}


	return xnodes;
}













#endif