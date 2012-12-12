#ifndef DYNARRAY_H_
#define DYNARRAY_H_

template<class T>
class dynArray
{
	private:
		int size;
		T *myarray;
	public:
	// constructor with user pre-defined size
		array (int s) {
		size = s;
		myarray = new T [size];
		}
	// calss array member function to set element of myarray
	// with type T values
	void setArray ( int elem, T val) {
		myarray[elem] = val;
		}

	// for loop to display all elements of an array
	void getArray () {
		 for ( int j = 0; j < size; j++ ) {
	// typeid will retriev a type for each value
			cout << setw( 7 ) << j << setw( 13 ) << myarray[ j ]
	<< " type: " << typeid(myarray[ j ]).name() << endl;
		}
		cout << "-----------------------------" << endl;
		}
};

#endif // DYNARRAY_H_
