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

	void clear() noexcept
	{
		myvector.clear();
	}

	iterator_type begin()
	{
		return myvector.begin();
	}
	iterator_type rbegin()
	{
			return myvector.rbegin();
	}
	iterator_type crbegin()
	{
			return myvector.crbegin();
	}
	iterator_type cbegin()
	{
			return myvector.crbegin();
	}
	iterator_type end()
	{
		return myvector.end();
	}
	iterator_type rend()
	{
		return myvector.rend();
	}
	iterator_type cend()
	{
		return myvector.cend();
	}
	iterator_type crend()
	{
		return myvector.crend();
	}
	iterator_type erase(iterator_type position)
	{
		return myvector.erase(position);
	}
	iterator_type erase(iterator_type first, iterator_type last)
	{
		return myvector.erase(first, last);
	}
	T front()
	{
		return myvector.front();
	}
	T back()
	{
		return myvector.back();
	}
	size_type capacity() const noexcept
	{
		return myvector.capacity();
	}
	void resize (size_type n)
	{
		myvector.resize(n);
	}
	void resize (size_type n, T val)
	{
		myvector.resize(n,val);
	}
	void push_back(T item){
		myvector.push_back(item);
	}
	void pop_back(){
		myvector.pop_back();
	}
	size_type size() const
		{ return myvector.size(); }
	bool empty() const noexcept
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
