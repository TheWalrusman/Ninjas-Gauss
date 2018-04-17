
/// \brief This is the Array class.
///	it is a basic array class that hold elements and is used in most of the other classes.
#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Array
{
private:
	int num_elts;
	T* ptr_to_data;
	void copy(const Array<T>& a);   

public:
	/// \brief A constructor for the Array class that sets the size with n.
	/// \pre needs to be nonnegative.
	/// \post create a Array class of size n
	///
	///
	Array(const int n);
	/// \brief A default constructor for the Array class.
	/// \pre None.
	/// \post will create a Array of size 0.
	///
	///
	Array();
	/// \brief Copy constructor for Array class.
	/// \pre two Arrays of same type.
	/// \post Two Arrays now contain the same infomation.
	///
	///
	Array(const Array<T>& source);
	/// \brief Move constructor for Array class.
	/// \pre None.
	/// \post Will deallocate the Source Array and transfer it to the Destination Array.
	///
	///
	Array(Array&& t);
	/// \brief Array class destructor.
	/// \pre A Array class object.
	/// \post Will deallocate memory taken by ptr_to_data array.
	///
	///
	~Array();
	/// \brief Array class operator [] non const version.
	/// \pre A Array class object and nonnegative int i, needs to be with in the array's dimensions.
	/// \post will return the value stored at position i.
	///
	/// \throws std::out_of_range if the value specified is less than 0 or greater than the Arrays num_elts.
	T& operator[](const int i);

	/// \brief Array class operator [] const version.
	/// \pre A Array class object and nonnegative int i, needs to be with in the array's dimensions.
	/// \post will return the value stored at position i.
	///
	/// \throws std::out_of_range if the value specified is less than 0 or greater than the Arrays num_elts.
	T& operator[](const int i)const;


	

	
	/// \brief The numofElts function.
	/// \pre None.
	/// \post Will return the int that represents the size of the Array.
	///
	///
	int numofElts()const;
	/// \brief Operator = for copy assignment.
	/// \pre needs two Arrays of same type.
	/// \post Will copy all data from rhs to the lhs.
	///
	///
	Array<T>& operator = (const Array<T>& rhs);
	/// \brief Operator = Move operator.
	/// \pre None.
	/// \post Will have copied the non pointer data while cutting the pointer from rhs to lhs.
	///
	///
	Array<T>& operator = (Array<T>&& t);
	/// \brief Operator = for scalar assignment.
	/// \pre  t needs to be of same type T.
	/// \post will assign all array space with value t.
	///
	///
	Array<T>& operator = (const T rhs);
	/// \brief setSize Function.
	/// \pre n needs to be nonnegative and not over the max size of a int.
	/// \post will have deallocated the ptr_to_data and re-initilized the Array to size n.
	///
	/// \throws std::out_of_range if the value specified is less than 0.
	void setSize(const int n);



	/// \brief prints all elements of array seperated by space.
	/// \pre a stream object and a Array object.
	/// \post will have return the stream object.
	///
	///
	template<class U>
	friend std::ostream& operator << (std::ostream& out,  const Array<U>& source);

	/// \brief will read in as many elements needed to fill up given Array object.
	/// \pre needs a in stream object and a Array object.
	/// \post will return a stream object.
	///
	///
	///
	template<class U>
	friend std::istream& operator >> (std::istream& in, const Array<U>& obj);


	/// \brief will multiply the array by the scalar.
	/// \pre needs a filled array.
	/// \post will return a Array.
	///
	///
	///
	Array<T> operator *(const double scalar);


	/// \brief will add two arrays.
	/// \pre needs two arrays of same size..
	/// \post will return a Array.
	///
	///
	///
	Array<T> operator +(const Array<T>& rhs);

	/// \brief will subtract a array from another Array.
	/// \pre needs two arrays of the same size.
	/// \post will return a Array.
	///
	///
	///
	Array<T> operator -(const Array<T>& rhs);


};

#include "Array.hpp"
#endif

