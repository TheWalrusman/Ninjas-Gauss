
#ifndef ARRAY_HPP
#define ARRAY_HPP



template<class T>
inline Array<T>::Array(const int n)
{
	num_elts = n;
	ptr_to_data = new T[n];
}

template<class T>
inline Array<T>::Array()
{
	num_elts = 0;
	ptr_to_data = nullptr;
	
}

template<class T>
inline Array<T>::Array(const Array<T>& source)
{
	num_elts = source.num_elts;
	ptr_to_data = new T[num_elts];
	copy(source);

}

template<class T>
inline Array<T>::Array(Array && t)
{
	num_elts = t.num_elts;
	ptr_to_data = t.ptr_to_data;
	t.ptr_to_data = nullptr;
}

template<class T>
inline void Array<T>::copy(const Array<T>& a)
{
	setSize(a.num_elts);
	for (int i = 0; i < a.num_elts; i++)
	{
		ptr_to_data[i] = a.ptr_to_data[i];
	}


}

template<class T>
inline Array<T>::~Array()
{
	delete[] ptr_to_data;
	ptr_to_data = 0;
}

template<class T>
inline T & Array<T>::operator[](const int i)
{
	/*try
	{
		if ((i < 0) || (i > num_elts))
			throw std::out_of_range("ERROR: Out of Array range");
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << std::endl << "ERROR: The value given is not in the range " <<
			"is not within the range of the array" << std::endl;
		exit(EXIT_FAILURE);
	}*/
	
	return ptr_to_data[i];
}




template<class T>
inline int Array<T>::numofElts()const
{
	return num_elts;
}

template<class T>
inline Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	setSize(rhs.num_elts);
	copy(rhs);
	return *this;
}

template<class T>
inline Array<T>& Array<T>::operator=(Array<T>&& t)
{
	num_elts = t.num_elts;
	ptr_to_data = t.ptr_to_data;
	t.ptr_to_data = nullptr;
	return *this;
}

template<class T>
inline Array<T>& Array<T>::operator=(const T rhs)
{
	for (int i = 0; i < num_elts; i++)
	{
		ptr_to_data[i] = rhs;
	}
	return *this;
	
}

template<class T>
inline void Array<T>::setSize(const int n)
{

	try
	{
		if ((n < 0))
			throw std::out_of_range("ERROR: Out of Array range");
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << std::endl << "ERROR: The value given is not in the range " <<
			"of a formal array (0,1,2,3,4,5,....)" << std::endl;
		exit(EXIT_FAILURE);
	}
	delete[] ptr_to_data;
	num_elts = n;
	ptr_to_data = new T[n];
	

}

template<class U>
inline std::ostream & operator<<(std::ostream & out,  Array<U>& source)
{
	for (int i = 0; i < source.numofElts(); i++)
	{
		const U tmp = (U)source[i];
		out << tmp<<" ";
	}
	out << std::endl;
	return out;
}


template<class U>
inline std::istream & operator>>(std::istream & in, Array<U>& obj)
{
	for (int i = 0; i < obj.numofElts(); i++)
	{
		in >> obj[i];
	}
	return in;
}












#endif
