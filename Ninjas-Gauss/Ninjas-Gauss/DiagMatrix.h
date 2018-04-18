#pragma once
#ifndef DIAGMATRIX_H
#define DIAGMATRIX_H

template<class T>
class DiagMatrix :public BaseMatrix<T>
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
	void copy(const DiagMatrix<T>& a);
public:

	/// \brief A default constructor for the Matric class.
	/// \pre none.
	/// \post create a DiagMatrix with default parameters
	///
	///
	DiagMatrix();
	/// \brief A constructor for the Matric that takes a width and height.
	/// \pre width and height need to be greate than zero.
	/// \post create a DiagMatrix of size W*H.
	///
	///
	DiagMatrix(const int width, const int height);
	/// \brief A constructor for a DiagMatrix that will copy the given matirx.
	/// \pre none.
	/// \post create a copy of the passed DiagMatrix.
	///
	///
	DiagMatrix(const DiagMatrix<T>& source);
	/// \brief A destructor for the DiagMatrix class.
	/// \pre none
	/// \post will have deleted and deallocated the memory of the DiagMatrix objet.
	///
	///

	DiagMatrix(DiagMatrix<T>&& t);



	~DiagMatrix();
	/// \brief A operator [] that will return the Array at that location, non const version.
	/// \pre needs to be nonnegative integer.
	/// \post returns a Array object.
	///
	///
	T operator ()(const int x, const int y);





	/// \brief A operator [] that will return the Array at that location, const version.
	/// \pre needs to be nonnegative integer.
	/// \post returns a Array object.
	///
	///
	T operator ()(const int x, const int y)const;
	/// \brief A getter that returns the height of the DiagMatrix.
	/// \pre none.
	/// \post returns the height of the DiagMatrix.
	///
	///
	int getheight()const;
	/// \brief A getter that returns the width of the DiagMatrix.
	/// \pre none.
	/// \post returns the width of the DiagMatrix.
	///
	///
	int getwidth()const;



	int getdiaglen()const;
	/// \brief A operator = that is the assignment operator for the DiagMatrix.
	/// \pre none.
	/// \post copies the rhs DiagMatrix to the lhs.
	///
	///
	DiagMatrix<T>& operator = (const DiagMatrix<T>& rhs);
	/// \brief A move operator for the DiagMatrix class.
	/// \pre a Lvalue DiagMatrix.
	/// \post will cut and paste the DiagMatrix to the Lvalue.
	///
	///
	DiagMatrix<T>& operator = (DiagMatrix<T>&& source);
	/// \brief A operator = that is the scalar assignment operator.
	/// \pre none.
	/// \post all values in the DiagMatrix will be the scalar.
	///
	///
	DiagMatrix<T>& operator = (const T rhs);
	/// \brief A set function that will delete and reallocate the memory.
	/// \pre none.
	/// \post a new DiagMatrix with the private copied and DiagMatrix of sizq n*n.
	///
	///
	void setWidth(const int n);
	DiagMatrix<T> operator + (const DiagMatrix<T>& rhs);//DiagMatrix Addition
	/// \brief A operator - for the DiagMatrix to subtract two DiagMatrixes of the same size.
	/// \pre two same size DiagMatrixes.
	/// \post returns a DiagMatrix that is a diffrence of the two.
	///
	///
	DiagMatrix<T> operator - (const DiagMatrix<T>& rhs);//DiagMatrix Subtraction
	/// \brief A operator * for the DiagMatrix to multiply two DiagMatrixes of the same size.
	/// \pre two DiagMatrixes with same inner dimmensions.
	/// \post returns a DiagMatrix that is a product of the two.
	///
	///
	DiagMatrix<T> operator * (const DiagMatrix<T>& rhs);//DiagMatrix Multiplication
	/// \brief A operator * for the DiagMatrix to multiply a DiagMatrix with a scalar value.
	/// \pre none.
	/// \post returns a DiagMatrix with every value being scaled to the scalar.
	///
	///
	DiagMatrix<T> operator * (const T scalar);//DiagMatrix and Scalar Multiplication
	/// \brief A operator * for the DiagMatrix to multiply a DiagMatrix with a vector(Array).
	/// \pre two same inner dimensions.
	/// \post returns a DiagMatrix that is a product of the two.
	///
	///
	Matrix<T> operator * (const Array<T>& vect);//DiagMatrix and Vector Multiplication
	/// \brief A stream operator for cout.
	/// \pre a ostream object and a DiagMatrix.
	/// \post will output the contents of the DiagMatrix to the screen.
	///
	///
	template<class U>
	friend std::ostream& operator << (std::ostream& out, const DiagMatrix<U>& source);
	/// \brief A stream operator for cin.
	/// \pre a istream object and a DiagMatrix.
	/// \post will read input from the keyboard or a file object into a DiagMatrix.
	///
	///
	template<class U>
	friend std::istream& operator >> (std::istream& in, const DiagMatrix<U>& source);
	/// \brief A function that just outputs the contents of the DiagMatrix.
	/// \pre a DiagMatrix.
	/// \post will output the contents of the DiagMatrix to the screen.
	///
	///
	void examine();
	/// \brief will transpose the DiagMatrix by making evey [i][j] place flipped to their [j][i] place.
	/// \pre a DiagMatrix.
	/// \post will return a DiagMatrix that is the transpose of the passed DiagMatrix.
	///
	///
	DiagMatrix<T> Transpose();
	/// \brief A finction that takes two ints and will swap those columns in the DiagMatrix,used when transposed to manipulate DiagMatrix for partial pivoting.
	/// \pre a DiagMatrix and two non-zero ints.
	/// \post will swap the two columns of the DiagMatrix in place.
	///
	///
	void rowswap(const int a, const int b);
};

#include "DiagMatrix.hpp"
#endif // !DIAGMATRIX_H
