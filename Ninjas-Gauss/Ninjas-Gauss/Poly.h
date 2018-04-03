
/// \brief allows for the addition and multiplication between vectors.
/// this functor assumes that the given vectors are in the format
/// c=x+x^2+x^3+....
///
///

#ifndef POLY_H
#define POLY_H

#include <vector>
template<class T>
class Polynomial
{	

public:
	
	/// \brief will take two vectors and multiply them as if they were ordered polynomials
	/// \pre two vectors in format c+x+x^2+x^3+....
	/// \post will return a new vector that is the product of the two given
	///
	///
	vector<T> multiplypolys(const vector<T>& lp, const vector<T>& rp);
	/// \brief will take two vectors and add them as if they were ordered polynomials
	/// \pre two vectors in format c+x+x^2+x^3+....
	/// \post will return a new vector that is the sum of the two given
	///
	///
	vector<T> addpolys(const vector<T>& lp, const vector<T>& rp);










};
#include "Poly.hpp"
#endif // !POLY_H

