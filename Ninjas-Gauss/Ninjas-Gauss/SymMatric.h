#pragma once
#ifndef SYMMATRIX_H
#define SYMMATRIX_H

template<class T>
class SymMatrix :public BaseMatrix<T>
{
private:
	int num_vects;
	int height;
	int width;
	int diaglen;
	Array<T>* ptr_to_data;
	/// \brief A copy function that handles the deallocation and remaking of a matrix into the passed matrix.
	/// \pre two matrixes of any size.
	/// \post Will return a copy of the passed matrix.
	///
	///
	void copy(const SymMatrix<T>& a);
public:

	/// \brief A default constructor for the Matric class.
	/// \pre none.
	/// \post create a SymMatrix with default parameters
	///
	///
	SymMatrix();
	/// \brief A constructor for the Matric that takes a width and height.
	/// \pre width and height need to be greate than zero.
	/// \post create a SymMatrix of size W*H.
	///
	///
	SymMatrix(const int width, const int height);
	/// \brief A constructor for a SymMatrix that will copy the given matirx.
	/// \pre none.
	/// \post create a copy of the passed SymMatrix.
	///
	///
	SymMatrix(const SymMatrix<T>& source);
	/// \brief A destructor for the SymMatrix class.
	/// \pre none
	/// \post will have deleted and deallocated the memory of the SymMatrix objet.
	///
	///

	SymMatrix(SymMatrix<T>&& t);



	~SymMatrix();
	/// \brief A operator [] that will return the Array at that location, non const version.
	/// \pre needs to be nonnegative integer.
	/// \post returns a Array object.
	///
	///
	T& operator ()(const int x, const int y);





	/// \brief A operator [] that will return the Array at that location, const version.
	/// \pre needs to be nonnegative integer.
	/// \post returns a Array object.
	///
	///
	T operator ()(const int x, const int y)const;
	/// \brief A getter that returns the height of the SymMatrix.
	/// \pre none.
	/// \post returns the height of the SymMatrix.
	///
	///
	int getheight()const;
	/// \brief A getter that returns the width of the SymMatrix.
	/// \pre none.
	/// \post returns the width of the SymMatrix.
	///
	///
	int getwidth()const;



	int getdiaglen()const;
	/// \brief A operator = that is the assignment operator for the SymMatrix.
	/// \pre none.
	/// \post copies the rhs SymMatrix to the lhs.
	///
	///
	SymMatrix<T>& operator = (const SymMatrix<T>& rhs);
	/// \brief A move operator for the SymMatrix class.
	/// \pre a Lvalue SymMatrix.
	/// \post will cut and paste the SymMatrix to the Lvalue.
	///
	///
	SymMatrix<T>& operator = (SymMatrix<T>&& source);
	/// \brief A operator = that is the scalar assignment operator.
	/// \pre none.
	/// \post all values in the SymMatrix will be the scalar.
	///
	///
	SymMatrix<T>& operator = (const T rhs);
	/// \brief A set function that will delete and reallocate the memory.
	/// \pre none.
	/// \post a new SymMatrix with the private copied and SymMatrix of sizq n*n.
	///
	///
	void setWidth(const int n);
	SymMatrix<T> operator + (const SymMatrix<T>& rhs);//SymMatrix Addition
	/// \brief A operator - for the SymMatrix to subtract two SymMatrixes of the same size.
	/// \pre two same size SymMatrixes.
	/// \post returns a SymMatrix that is a diffrence of the two.
	///
	///
	SymMatrix<T> operator - (const SymMatrix<T>& rhs);//SymMatrix Subtraction
	/// \brief A operator * for the SymMatrix to multiply two SymMatrixes of the same size.
	/// \pre two SymMatrixes with same inner dimmensions.
	/// \post returns a SymMatrix that is a product of the two.
	///
	///
	SymMatrix<T> operator * (const SymMatrix<T>& rhs);//SymMatrix Multiplication
	/// \brief A operator * for the SymMatrix to multiply a SymMatrix with a scalar value.
	/// \pre none.
	/// \post returns a SymMatrix with every value being scaled to the scalar.
	///
	///
	SymMatrix<T> operator * (const T scalar);//SymMatrix and Scalar Multiplication
	/// \brief A operator * for the SymMatrix to multiply a SymMatrix with a vector(Array).
	/// \pre two same inner dimensions.
	/// \post returns a SymMatrix that is a product of the two.
	///
	///
	Matrix<T> operator * (const Array<T>& vect);//SymMatrix and Vector Multiplication
	/// \brief A stream operator for cout.
	/// \pre a ostream object and a SymMatrix.
	/// \post will output the contents of the SymMatrix to the screen.
	///
	///
	template<class U>
	friend std::ostream& operator << (std::ostream& out, const SymMatrix<U>& source);
	/// \brief A stream operator for cin.
	/// \pre a istream object and a SymMatrix.
	/// \post will read input from the keyboard or a file object into a SymMatrix.
	///
	///
	template<class U>
	friend std::istream& operator >> (std::istream& in, const SymMatrix<U>& source);
	/// \brief A function that just outputs the contents of the SymMatrix.
	/// \pre a SymMatrix.
	/// \post will output the contents of the SymMatrix to the screen.
	///
	///
	void examine();
	/// \brief will transpose the SymMatrix by making evey [i][j] place flipped to their [j][i] place.
	/// \pre a SymMatrix.
	/// \post will return a SymMatrix that is the transpose of the passed SymMatrix.
	///
	///
	SymMatrix<T> Transpose();
	/// \brief A finction that takes two ints and will swap those columns in the SymMatrix,used when transposed to manipulate SymMatrix for partial pivoting.
	/// \pre a SymMatrix and two non-zero ints.
	/// \post will swap the two columns of the SymMatrix in place.
	///
	///
	void rowswap(const int a, const int b);
};

#include "SymMatrix.hpp"
#endif // !SYMMATRIX_H
