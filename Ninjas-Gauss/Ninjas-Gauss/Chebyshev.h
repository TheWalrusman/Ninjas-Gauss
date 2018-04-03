

/// \brief is a functor that generates a set of Chebyshev nodes for a given degree of poly.
/// 
/// 
///
///

#ifndef CHEBYSHEV_H
#define CHEBYSHEV_H



template<class T>
class Chebyshevx
{
private:
	const double PI = 3.141592653589793;


public:
	/// \brief Will take in the amount of nodes to generate and generate them.
	/// \pre none.
	/// \post will have computed N+1 nodes and returned them in a vector format.
	///
	///
	Array<T> operator () (const int nodes);

};












#include "Chebyshev.hpp"
#endif // !CHEBYSHEV_H

