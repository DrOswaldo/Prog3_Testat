#ifndef LINE_ITERATOR_H_
#define LINE_ITERATOR_H_

#include <sstream>

class line_iterator {
public:
	line_iterator(std::istream &input=dummy)
		:in(input)
	{
	}
private:
	std::istream &in;
	static std::istringstream dummy;
};

#endif /* LINE_ITERATOR_H_ */
