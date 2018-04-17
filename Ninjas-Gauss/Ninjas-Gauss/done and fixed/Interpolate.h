
/// \brief This is the Interpolate class.
/// it allows for the interpolating at a x value from the divided diffrence table.
/// it also for the formation of the full power polynomial from the divided diffrence table.

#ifndef INTERPOLATE_H
#define INTERPOLATE_H

template<class T>
class Interpolate
{
private:
	std::vector<Array<T>> divtable;
public:
	/// \brief Will set the member variable to difftable.
	/// \pre  A same type object as the Interpolate class.
	/// \post Will have set divtable with new value.
	///
	///
	void SetDiffTable(const std::vector<Array<T> >& difftable);
	/// \brief operator () to emulate the interpolation of a Divided Diffrence Table.
	/// \pre  Requires that the SetDiffTable() be called before and have set divtable.
	/// \post Will return a vector containing all values at 0.1,0.2,0.3,...,1. 
	///
	///
	std::vector<T> operator () (const double start, const double end, const double step);
	
	/// \brief operator() that will create the full power form polynomial from the divtable.
	/// \pre needs to have the div table set in order to work.
	/// \post will have computed the polynomial and returned it in vecotr format.
	///
	///
	std::vector<T> operator()(const std::vector<Array<T>>& table);
};




#include "Interpolate.hpp"
#endif
