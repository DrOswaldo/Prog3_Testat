#ifndef LINE_ITERATOR_H_
#define LINE_ITERATOR_H_

#include <boost/iterator/iterator_facade.hpp>

class line_iterator :
	public boost::iterator_facade<
		line_iterator,
		std::string,
		std::input_iterator_tag,
		std::string>
{
public:
	explicit line_iterator()
		:m_istream(0)
	{}
	explicit line_iterator(std::istream &input);

private:
	friend class boost::iterator_core_access;

    value_type dereference() const;

    bool equal(const line_iterator & rhs) const;

    void increment();


	value_type m_current_value;
	std::istream *m_istream;
};

#endif /* LINE_ITERATOR_H_ */
