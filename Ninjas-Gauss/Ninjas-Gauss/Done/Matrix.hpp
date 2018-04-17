




#ifndef MATRIX_HPP
#define MATRIX_HPP

template<class T>
inline Matrix<T>::Matrix()
{
	num_vects = 0;
	height = 0;
	width = 0;
	ptr_to_data = nullptr;

}

template<class T>
inline Matrix<T>::Matrix(const int inwidth,const int inheight)
{
	num_vects = inwidth;
	width = inwidth;
	height = inheight;
	//delete[] ptr_to_data;
	//ptr_to_data = nullptr;
   	ptr_to_data = new Array<T>[width];
	for (int i = 0; i < inwidth; i++)
	{
		ptr_to_data[i] =  Array<T>(inheight);
	}

}


template<class T>
inline Matrix<T>::Matrix(const Matrix<T>& source)
{
	delete[] ptr_to_data;
	ptr_to_data = NULL;
	//ptr_to_data = nullptr;
	num_vects = source.num_vects;
	height = source.height;
	width = source.width;
	ptr_to_data = new Array<T>[width];
	copy(source);

}

template<class T>
inline int Matrix<T>::getheight() const
{
	return height;
}

template<class T>
inline int Matrix<T>::getwidth() const
{
	return width;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	delete[] ptr_to_data;
	ptr_to_data = NULL;

}

template<class T>
inline Array<T>& Matrix<T>::operator[](const int n)
{
	return ptr_to_data[n];
}

template<class T>
inline Array<T>& Matrix<T>::operator[](const int n) const
{
	return ptr_to_data[n];
}

template<class T>
inline void Matrix<T>::copy(const Matrix<T>& a)
{

	setWidth(a.width);
	height = a.height;
	delete[] ptr_to_data;
	for (int i = 0; i < a.num_vects; i++)
	{
		ptr_to_data[i] = a[i];

	}
}

template<class T>
inline void Matrix<T>::setWidth(const int n)
{
	delete[] ptr_to_data;
	num_vects = n;
	width = n;
	ptr_to_data = new Array<T>[n];


}

template<class T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	copy(rhs);
	return *this;
}


template<class T>
inline Matrix<T>& Matrix<T>::operator=(Matrix<T>&& source)
{
	num_vects = source.num_vects;
	height = source.height;
	width = source.width;
	this->ptr_to_data = source.ptr_to_data;
	source.ptr_to_data = nullptr;
	return *this;
}


template<class T>
inline Matrix<T>& Matrix<T>::operator=(const T rhs)
{
	delete[] ptr_to_data;
	for (int i = 0; i < width; i++)
	{
		ptr_to_data[i] = rhs;
	}
	return *this;
}


template<class T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
	
	if ((this->height != rhs.height) || (this->width != rhs.width))
		std::cout << "ERROR HERE";
	Matrix<double> tmp(width, height);
	for (int i = 0; i < width; i++)
	{
		tmp[i] = this->operator[](i) + rhs[i];
	}
	return tmp;
	
}

template<class T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
{

	if ((this->height != rhs.height) || (this->width != rhs.width))
		std::cout << "ERROR HERE";
	Matrix<double> tmp(width, height);
	for (int i = 0; i < width; i++)
	{
		tmp[i] = this->operator[](i) - rhs[i];
	}
	return tmp;
	
}

template<class T>
inline Matrix<T> Matrix<T>::operator*(const T scalar)
{
	Matrix<double> tmp(width, height);
	for (int i = 0; i < width; i++)
	{
		tmp[i] = this->operator[](i) * scalar;
	}
	return tmp;
	
}


template<class T>
inline Matrix<T> Matrix<T>::operator*(const Array<T>& vect)
{
	
	if(width != vect.numofElts())
		std::cout << "ERROR HERE";
	//Matrix<double> test6(6, 6);
	Matrix<double> tmp(1, height);
	for (int i = 0; i < height; i++)
	{
		for (int q = 0; q < vect.numofElts(); q++)
		{
			tmp[0][i] += this->operator[](q)[i] * vect[q];
		}
		
	}

	return tmp;
}

template<class T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
	if (width != rhs.height)
		std::cout << "ERROR HERE";
	Matrix<double> tmp(height, rhs.width);
	
	Matrix<double> test5(*this);
	Matrix<double> slice;
	for (int i = 0; i < width; i++)
	{
		
		slice = test5 * rhs[i];
		tmp[i] = slice[0];
	}

	return tmp;
}

template<class U>
inline std::ostream & operator<<(std::ostream & out, const Matrix<U>& source)
{
	out << std::endl;
	for (int i = 0; i < source.getheight(); i++)
	{
		for (int q = 0; q < source.getwidth(); q++)
		{
			if(source[q][i] == -0)
				out << 0 << " ";
			else
			{
				out << source[q][i] << "  ";
			}
			
		}
		out << std::endl;
	}
	return out;
}

template<class U>
inline std::istream & operator>>(std::istream & in, const Matrix<U>& source)
{
	
	if (abs(source.height - source.width) == 0)
	{
		for (int i = 0; i < source.getheight(); i++)
		{
			for (int q = 0; q < source.getwidth(); q++)
			{
				in >> source[q][i];
				
			}
		}
	}
	else
	{
		for (int i = 0; i < source.getheight(); i++)
		{
			for (int q = 0; q < source.getwidth()-1; q++)
			{
				in >> source[q][i];
				
			}
		}
		for (int i = 0; i < source.getheight(); i++)
		{
			in >> source[source.getwidth() - 1][i];
		}

	}
	
	return in;

}


template<class T>
inline void Matrix<T>::examine()
{
	std::cout <<std::endl<<std::setprecision(9)<< *this<<std::fixed<<std::endl;
}

template<class T>
inline Matrix<T> Matrix<T>::Transpose()
{
	Matrix<T> tmp(height, width);

	for (int i = 0; i < width; i++)
	{
		for (int q = 0; q < height; q++)
		{
			tmp[q][i] = this->operator[](i)[q];
		}
	}

	return tmp;
}

template<class T>
inline void Matrix<T>::rowswap(const int a, const int b)
{
	Array<T> copya(width);
	for (int i = 0; i < width; i++)
	{
		copya[i] = this->operator[](i)[a];
	}
	for (int i = 0; i < width; i++)
	{
		this->operator[](i)[a] = this->operator[](i)[b];
	}

	for (int i = 0; i < width; i++)
	{
		this->operator[](i)[b] = copya[i];
	}


}
#endif // !MATRIX_HPP
