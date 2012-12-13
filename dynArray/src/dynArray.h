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

	dynArray(std::initializer_list<T> ilist)
		:myvector{ilist}
	{}

	T operator[](int index)
	{
		if (index < 0){
			return myvector[myvector.size - index];
		}
		else {
			return myvector[index];
		}
	}

	size_type size() const
		{ return myvector.size(); }
	bool empty() const
		{ return myvector.empty(); }

	void setElement ( int pos, T val)
	{
		if (pos < 0)
		{
			myvector[myvector.size -pos] = val;
		}
		else
		{
			myvector[pos] = val;
		}
	}


};

#endif // DYNARRAY_H_
