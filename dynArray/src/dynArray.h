#ifndef DYNARRAY_H_
#define DYNARRAY_H_

template<typename T>
class dynArray
{
private:
	int size;
	T *cVector;
public:
	dynArray(int s)
		:size{s}
		,cVector{new T[size]}
	{
	}
	void setVector ( int elem, T val)
	{
		cVector[elem] = val;
	}

	void getVector () {
		 for ( int j = 0; j < size; j++ ) {

	<< " type: " << typeid(cVector[ j ]).name() << std::endl;
		}
		std::cout << "-----------------------------" << std::endl;
	}
};

#endif // DYNARRAY_H_
