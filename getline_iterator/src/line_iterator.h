#ifndef LINE_ITERATOR_H_
#define LINE_ITERATOR_H_

#include <boost/operators.hpp>
#include <sstream>

class line_iterator : boost::input_iterator_helper<line_iterator, std::string>

{
public:
	explicit line_iterator()
		:in(0)
	{}
	explicit line_iterator(std::istream &input)
		:in(&input)
	{}

	value_type operator*() const
	{
		return value;
	}

	line_iterator& operator++()
	{
		if(in) {
			getline(*in, value);
			if( !in->good() ) {
				in = 0;
			}
		}
		return *this;
	}

	bool operator==( const line_iterator& b) const;

private:
	value_type value;
	std::istream *in;
	//static std::istringstream dummy;
};

#endif /* LINE_ITERATOR_H_ */
