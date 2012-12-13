#ifndef DYNARRAY_H_
#define DYNARRAY_H_

template<typename T>
class dynArray
{
	using size_type=typename std::vector<T>::size_type;
	using iterator_type=typename std::vector<T>::iterator;
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
		if (index < 0){
			return myvector.at(myvector.size() + index);

		}
		else {
			return myvector.at(index);
		}
	}
	T at(int index)
	{
		if (index < 0){
			return myvector.at(myvector.size() + index);

		}
		else {
			return myvector.at(index);
		}
	}

	iterator_type begin()
	{
		return myvector.begin();
	}
	iterator_type end()
	{
		return myvector.end();
	}

	T front()
	{
		return myvector.front();
	}
	T back()
	{
		return myvector.back();
	}

	size_type size() const
		{ return myvector.size(); }
	bool empty() const
		{ return myvector.empty(); }

	void setElement ( int pos, T val)
	{
		if (pos < 0)
		{
			myvector.at(myvector.size() +pos) = val;
		}
		else
		{
			myvector.at(pos) = val;
		}
	}


};

#endif // DYNARRAY_H_
