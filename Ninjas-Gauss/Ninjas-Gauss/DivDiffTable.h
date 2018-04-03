
/// \brief This is the DiffTable class.
/// It will create a divided diffrence table form a given set of x-values
/// and y-values.
/// the returned value is used in the Interpolate class. 
#ifndef DIVDIFFTABLE_H
#define DIVDIFFTABLE_H



template<class T>
class DiffTable
{
public:

	/// \brief Operator () to emulate the Divided Diffrence Table.
	/// \pre Will take any vector or Arrays of numeric type.
	/// \post Will return by value the entire Divided Diffrence table.
	///
	/// \throw overflow_error if any of the x2-x1 is equal to zero as that will cause division by zero.
	std::vector<Array<T>> operator () ( const std::vector<Array<T> >& xy);




};





#include "DivDiffTable.hpp"
#endif 

