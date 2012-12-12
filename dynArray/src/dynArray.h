#ifndef DYNARRAY_H_
#define DYNARRAY_H_

template<typename T>
class dynArray
{
	using size_type=typename std::vector<T>::size_type;
	std::vector<T> myvector;
public:
	dynArray()
		:myvector{}
	{}

	dynArray(size_type size, T value)
		:myvector(size, value)
	{}

	dynArray(std::initializer_list<T> ilist)
		:myvector{ilist}
	{}

	T operator[](int index)
	{
		return myvector[index];
	}

	size_type size() const
		{ return myvector.size(); }
	bool empty() const
		{ return myvector.empty(); }

	// calss array member function to set element of myarray
	// with type T values
	void setArray ( int elem, T val)
	{
		myvector[elem] = val;
	}


	// for loop to display all elements of an array
	void getArray () {
		 for ( int j = 0; j < myvector.size; j++ ) {
	// typeid will retriev a type for each value
	        std::cout //<< std::setw( 7 ) << j << std::setw( 13 ) << myarray[ j ]
	<< " type: " << typeid(myvector[ j ]).name() << std::endl;
		}
		std::cout << "-----------------------------" << std::endl;
	}
};

#endif // DYNARRAY_H_
