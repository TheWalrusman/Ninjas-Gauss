


#ifndef BASEMATRIX_H
#define BASEMATRIX_H
using namespace std;


template<class T>
class BaseMatrix
{

	
public:
	//virtual BaseMatrix(const int width, const int height) = 0;
	virtual ~BaseMatrix() = 0;
	//virtual Array<T>& operator [](const int n) = 0;
	//virtual Array<T>& operator [](const int n)const = 0;
	virtual int getheight()const = 0;
	virtual int getwidth()const = 0;
	//virtual BaseMatrix& operator = (const T& rhs) = 0;
	//virtual BaseMatrix& operator = (const T rhs) = 0;
	virtual void setWidth(const int n) = 0;


};
template<class t>
inline BaseMatrix<t>::~BaseMatrix()
{

}
//template <class T>
//class Dumb : public BaseMatrix<T>
//{
//public:
//	Dumb();
//	~Dumb();
//	Dumb(const int width, const int height);
//
//private:
//	int num_vects;
//	int height;
//	int width;
//	Array<T>* ptr_to_data;
//};
//
//
//template<class T>
//inline Dumb<T>::Dumb()
//{
//	num_vects = 0;
//	height = 0;
//	width = 0;
//	ptr_to_data = nullptr;
//
//}
//
//template<class T>
//inline Dumb<T>::~Dumb()
//{
//	delete[] ptr_to_data;
//	ptr_to_data = nullptr;
//
//
//}
//
//template<class T>
//inline Dumb<T>::Dumb(const int inwidth, const int inheight)
//{
//	num_vects = inwidth;
//	width = inwidth;
//	height = inheight;
//	//delete[] ptr_to_data;
//	//ptr_to_data = nullptr;
//	ptr_to_data = new Array<T>[inwidth];
//	for (int i = 0; i < inwidth; i++)
//	{
//		//Array<double>tmp(inheight);
//		ptr_to_data[i] = Array<double>(inheight);
//		//ptr_to_data[i]->operator=()
//
//	}
//
//
//
//
//}
















#endif // !BASEMATRIX_H


