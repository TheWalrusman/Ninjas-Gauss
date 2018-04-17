#pragma once

#ifndef GAUSSSOLVE_H
#define GAUSSSOLVE_H
/// \brief This is Gaussian solver using partial pivits.
///	it takes a martrix of any size and will try to solve it using partial pivoting.
template<class T>
class GaussSolve
{
public:
	/// \brief A functor for the GaussSolve that will apply the partial piviting to a linear system of equations.
	/// \pre A matrix that is able to be solved.
	/// \post will return a full reduced matrix.
	///
	///
	Matrix<T> operator() (Matrix<T>& base,const bool swapornot);



};












#include "GaussSolve.hpp"
#endif // !GaussSolve

