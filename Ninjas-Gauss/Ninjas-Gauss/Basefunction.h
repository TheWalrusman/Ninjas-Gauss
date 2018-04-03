
/// \brief will compute the true y-value for any given x-value.
/// 
/// 
///
///

#ifndef BASEFUNCTION_H
#define BASEFUNCTION_H

template<class T>
class Basefunction
{


public:
	/// \brief will peform the true eqaution on the passed x values.
	/// \pre none.
	/// \post will return a Array of all y values of the given x-values.
	///
	///
	Array<T> operator () ( Array<T>& source);




};
#include "Basefunction.hpp"
#endif // !BASEFUNCTION_H
