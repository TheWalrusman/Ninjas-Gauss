#pragma once
#ifndef SYMMATRIX_HPP
#define SYMMATRIX_HPP


template<class T>
inline SymMatrix<T>::SymMatrix()
{
	num_vects = 0;
	diaglen = 0;
	height = 0;
	width = 0;
	ptr_to_data = nullptr;

}

template<class T>
inline SymMatrix<T>::SymMatrix(const int inwidth, const int inheight)
{
	num_vects = inwidth;
	width = inwidth;
	height = inheight;
	diaglen = std::min(inwidth, inheight);
	//delete[] ptr_to_data;
	//ptr_to_data = nullptr;
	ptr_to_data = new Array<T>[inwidth];
	for (int i = 0; i < width; i++)
	{
		//Array<double>tmp(inheight);
		ptr_to_data[i] = Array<double>(height-i);
		//std::cout << ptr_to_data[i] << std::endl;
		//ptr_to_data[i]->operator=()

	}

}

template<class T>
inline SymMatrix<T>::SymMatrix(SymMatrix<T>&& t)
{
	num_vects = t.num_vects;
	diaglen = t.diaglen;
	width = t.width;
	height = t.height;
	ptr_to_data = t.ptr_to_data;
	t.ptr_to_data = nullptr;
}

template<class T>
inline SymMatrix<T>::SymMatrix(const SymMatrix<T>& source)
{
	if (ptr_to_data == nullptr)
		delete[] ptr_to_data;
	else
	{
		num_vects = source.num_vects;
		height = source.height;
		diaglen = source.diaglen;
		width = source.width;
		ptr_to_data = new Array<T>[width];
		copy(source);
	}
	//ptr_to_data = NULL;
	//ptr_to_data = nullptr;


}

template<class T>
inline int SymMatrix<T>::getheight() const
{
	return height;
}

template<class T>
inline int SymMatrix<T>::getwidth() const
{
	return width;
}

template<class T>
inline int SymMatrix<T>::getdiaglen() const
{
	return diaglen;
}

template<class T>
inline SymMatrix<T>::~SymMatrix()
{

	delete[] ptr_to_data;
	ptr_to_data = nullptr;
	//std::cout << "HI " << std::endl;

}




template<class T>
inline T& SymMatrix<T>::operator()(const int x, const int y)
{
	if ((y < x))
		return ptr_to_data[y][std::abs(y - x)] ;
	return ptr_to_data[x][std::abs(y-x)];


}

template<class T>
inline T SymMatrix<T>::operator()(const int x, const int y) const
{
	if ((y < x))
		return ptr_to_data[y][std::abs(y - x)];
	return ptr_to_data[x][std::abs(y - x)];
}

template<class T>
inline void SymMatrix<T>::copy(const SymMatrix<T>& a)
{

	//setWidth(1);
	delete[] ptr_to_data;
	num_vects = a.num_vects;
	width = a.width;
	height = a.height;
	ptr_to_data = new Array<T>[a.width];

	//delete[] ptr_to_data;

	for (int i = 0; i < a.num_vects; i++)
	{
		//ptr_to_data[i].setSize(height);
		ptr_to_data[i] = a.ptr_to_data[i];

	}
}

template<class T>
inline void SymMatrix<T>::setWidth(const int n)
{
	delete[] ptr_to_data;
	num_vects = n;
	width = n;
	ptr_to_data = new Array<T>[n];



}

template<class T>
inline SymMatrix<T>& SymMatrix<T>::operator=(const SymMatrix<T>& rhs)
{
	copy(rhs);
	return *this;
}


template<class T>
inline SymMatrix<T>& SymMatrix<T>::operator=(SymMatrix<T>&& source)
{
	delete[] ptr_to_data;
	num_vects = source.num_vects;
	height = source.height;
	width = source.width;
	diaglen = source.diaglen;
	ptr_to_data = source.ptr_to_data;
	source.ptr_to_data = nullptr;
	return *this;
}


template<class T>
inline SymMatrix<T>& SymMatrix<T>::operator=(const T rhs)
{
	//delete[] ptr_to_data;
	for (int i = 0; i < num_vects; i++)
	{
		ptr_to_data[i] = rhs;
		//std::cout << ptr_to_data[i] << std::endl;
	}
	return *this;
}


template<class T>
inline SymMatrix<T> SymMatrix<T>::operator+(const SymMatrix<T>& rhs)
{

	if ((this->height != rhs.height) || (this->width != rhs.width))
		std::cout << "ERROR HERE";
	SymMatrix<double> tmp(width, height);
	for (int i = 0; i < num_vects; i++)
	{
		tmp.ptr_to_data[i] = ptr_to_data[i] + rhs.ptr_to_data[i];
	}
	return tmp;

}

template<class T>
inline SymMatrix<T> SymMatrix<T>::operator-(const SymMatrix<T>& rhs)
{

	if ((this->height != rhs.height) || (this->width != rhs.width))
		std::cout << "ERROR HERE";
	SymMatrix<double> tmp(width, height);
	for (int i = 0; i < num_vects; i++)
	{
		tmp.ptr_to_data[i] = ptr_to_data[i] - rhs.ptr_to_data[i];
	}
	return tmp;

}

template<class T>
inline SymMatrix<T> SymMatrix<T>::operator*(const T scalar)
{
	SymMatrix<double> tmp(width, height);
	for (int i = 0; i < num_vects; i++)
	{
		tmp.ptr_to_data[i] = ptr_to_data[i] * scalar;
	}
	return tmp;

}


template<class T>
inline Matrix<T> SymMatrix<T>::operator*(const Array<T>& vect)
{

	if (width != vect.numofElts())
		std::cout << "ERROR HERE";
	SymMatrix<double> test6(6, 6);
	Matrix<T> tmp(1, height);
	for (int i = 0; i < height; i++)
	{
		for (int q = 0; q < vect.numofElts(); q++)
		{
			tmp(0,i) = tmp(0,i) + (this->operator()(q,i) * vect[q]);
			//tmp[0][i] = (5);
		}
		//std::cout << tmp[0][i]<<std::endl;
	}

	return tmp;
}

template<class T>
inline SymMatrix<T> SymMatrix<T>::operator*(const SymMatrix<T>& rhs)
{
	if (width != rhs.height)
		std::cout << "ERROR HERE";
	SymMatrix<double> tmp(height, rhs.width);

	SymMatrix<double> test5(9, 9);
	test5 = *this;
	SymMatrix<double> slice(9, 9);
	for (int i = 0; i < width; i++)
	{

		slice = test5 * rhs[i];
		tmp.ptr_to_data[i] = slice.ptr_to_data[0];
		//tmp.ptr_to_data[i] = tmp(i, i) * rhs(i, i);
	}

	return tmp;
}

template<class U>
inline std::ostream & operator<<(std::ostream & out, const SymMatrix<U>& source)
{
	out << std::endl;
	for (int i = 0; i < source.getheight(); i++)
	{
		for (int q = 0; q < source.getwidth(); q++)
		{
			if (source(q, i) == -0)
				out << 0 << " ";
			else
			{
				out << source(q,i) << "  ";
				
			}
			//std::cout << std::endl << "( " << q << " , " << i << " ) == " << source(q, i) << std::endl;
			//std::cout << "";

		}
		out << std::endl;
	}
	return out;
}

template<class U>
inline std::istream & operator>>(std::istream & in, const SymMatrix<U>& source)
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
			for (int q = 0; q < source.getwidth() - 1; q++)
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
inline void SymMatrix<T>::examine()
{
	std::cout << std::endl << std::setprecision(9) << *this << std::fixed << std::endl;
}

template<class T>
inline SymMatrix<T> SymMatrix<T>::Transpose()
{
	SymMatrix<T> tmp(height, width);

	/*for (int i = 0; i < width; i++)
	{
	for (int q = 0; q < height; q++)
	{
	tmp[q][i] = this->operator[](i)[q];
	}
	}*/

	return tmp;
}

template<class T>
inline void SymMatrix<T>::rowswap(const int a, const int b)
{
	Array<T> copya(width);
	/*for (int i = 0; i < width; i++)
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
	}*/
}




#endif // !SYMMATRIX_HPP
