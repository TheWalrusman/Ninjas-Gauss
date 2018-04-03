


#ifndef BASEFUNCTION_HPP
#define BASEFUNCTION_HPP


template<class T>
inline Array<T> Basefunction<T>::operator()( Array<T>& source)
{
	Array<T> yvalues(source.numofElts());
	

	for (int i = 0; i < yvalues.numofElts(); i++)
	{
		
		
		yvalues[i] = 1 / (1 + (12 * std::pow(source[i],2)));
		//T tmp = yvalues[i];
		//tmp = yvalues[i];
		//std::cout << std::endl << tmp << std::endl;
	}



	return yvalues;
}







#endif // !BASEFUNCTION_HPP

