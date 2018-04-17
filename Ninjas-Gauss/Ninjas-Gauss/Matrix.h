

/// \brief This is the Matrix class.
///	it is a Matrix made of the Array class that provides mathmatical operations to solve lienaer syatems.
#ifndef MATRIX_H
#define MATRIX_H

template<class T>
class Matrix
{
public:
	/// \brief A default constructor for the Matric class.
	/// \pre none.
	/// \post create a matrix with default parameters
	///
	///
	Matrix();
	/// \brief A constructor for the Matric that takes a width and height.
	/// \pre width and height need to be greate than zero.
	/// \post create a matrix of size W*H.
	///
	///
	Matrix(const int width, const int height);
	/// \brief A constructor for a matrix that will copy the given matirx.
	/// \pre none.
	/// \post create a copy of the passed Matrix.
	///
	///
	Matrix(const Matrix<T>& source);
	/// \brief A destructor for the matrix class.
	/// \pre none
	/// \post will have deleted and deallocated the memory of the matrix objet.
	///
	///

	Matrix(Matrix<T>&& t);
	


	~Matrix();
	/// \brief A operator [] that will return the Array at that location, non const version.
	/// \pre needs to be nonnegative integer.
	/// \post returns a Array object.
	///
	///
	Array<T>& operator [](const int n);
	/// \brief A operator [] that will return the Array at that location, const version.
	/// \pre needs to be nonnegative integer.
	/// \post returns a Array object.
	///
	///
	Array<T>& operator [](const int n)const;
	/// \brief A getter that returns the height of the matrix.
	/// \pre none.
	/// \post returns the height of the matrix.
	///
	///
	int getheight()const;
	/// \brief A getter that returns the width of the matrix.
	/// \pre none.
	/// \post returns the width of the matrix.
	///
	///
	int getwidth()const;
	/// \brief A operator = that is the assignment operator for the matrix.
	/// \pre none.
	/// \post copies the rhs matrix to the lhs.
	///
	///
	Matrix<T>& operator = (const Matrix<T>& rhs);
	/// \brief A move operator for the matrix class.
	/// \pre a Lvalue matrix.
	/// \post will cut and paste the matrix to the Lvalue.
	///
	///
	Matrix<T>& operator = (Matrix<T>&& source);
	/// \brief A operator = that is the scalar assignment operator.
	/// \pre none.
	/// \post all values in the matrix will be the scalar.
	///
	///
	Matrix<T>& operator = (const T rhs);
	/// \brief A set function that will delete and reallocate the memory.
	/// \pre none.
	/// \post a new matrix with the private copied and matrix of sizq n*n.
	///
	///
	void setWidth(const int n);
	/// \brief A operator + for the matrix to add two matrixes of the same size.
	/// \pre two same size matrixes.
	/// \post returns a matrix that is a sum of the two.
	///
	///
	Matrix<T> operator + (const Matrix<T>& rhs);//Matrix Addition
	/// \brief A operator - for the matrix to subtract two matrixes of the same size.
	/// \pre two same size matrixes.
	/// \post returns a matrix that is a diffrence of the two.
	///
	///
	Matrix<T> operator - (const Matrix<T>& rhs);//Matrix Subtraction
	/// \brief A operator * for the matrix to multiply two matrixes of the same size.
	/// \pre two matrixes with same inner dimmensions.
	/// \post returns a matrix that is a product of the two.
	///
	///
	Matrix<T> operator * (const Matrix<T>& rhs);//Matrix Multiplication
	/// \brief A operator * for the matrix to multiply a matrix with a scalar value.
	/// \pre none.
	/// \post returns a matrix with every value being scaled to the scalar.
	///
	///
	Matrix<T> operator * (const T scalar);//Matrix and Scalar Multiplication
	/// \brief A operator * for the matrix to multiply a matrix with a vector(Array).
	/// \pre two same inner dimensions.
	/// \post returns a matrix that is a product of the two.
	///
	///
	Matrix<T> operator * (const Array<T>& vect);//Matrix and Vector Multiplication
	/// \brief A stream operator for cout.
	/// \pre a ostream object and a matrix.
	/// \post will output the contents of the matrix to the screen.
	///
	///
	template<class U>
	friend std::ostream& operator << (std::ostream& out, const Matrix<U>& source);
	/// \brief A stream operator for cin.
	/// \pre a istream object and a matrix.
	/// \post will read input from the keyboard or a file object into a matrix.
	///
	///
	template<class U>
	friend std::istream& operator >> (std::istream& in, const Matrix<U>& source);
	/// \brief A function that just outputs the contents of the matrix.
	/// \pre a matrix.
	/// \post will output the contents of the matrix to the screen.
	///
	///
	void examine();
	/// \brief will transpose the matrix by making evey [i][j] place flipped to their [j][i] place.
	/// \pre a matrix.
	/// \post will return a matrix that is the transpose of the passed matrix.
	///
	///
	Matrix<T> Transpose();
	/// \brief A finction that takes two ints and will swap those columns in the matrix,used when transposed to manipulate matrix for partial pivoting.
	/// \pre a matrix and two non-zero ints.
	/// \post will swap the two columns of the matrix in place.
	///
	///
	void rowswap(const int a, const int b);

private:
	int num_vects;
	int height;
	int width;
	Array<T>* ptr_to_data;
	/// \brief A copy function that handles the deallocation and remaking of a matrix into the passed matrix.
	/// \pre two matrixes of any size.
	/// \post Will return a copy of the passed matrix.
	///
	///
	void copy(const Matrix<T>& a);


};







#include "Matrix.hpp"
#endif // !MATRIX_H

