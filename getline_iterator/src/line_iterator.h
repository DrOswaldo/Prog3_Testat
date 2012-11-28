#ifndef LINE_ITERATOR_H_
#define LINE_ITERATOR_H_

#include <boost/operators.hpp>

#include <istream>
#include <boost/iterator/iterator_facade.hpp>

class line_iterator :
	public boost::iterator_facade<
		line_iterator,
		std::string,
		std::input_iterator_tag,
		std::string>

{
	friend class boost::iterator_core_access;

    value_type dereference() const
    {
        return m_current_value;
    }

    bool equal(const line_iterator & rhs) const
    {
        return m_istream == rhs.m_istream;
    }

    void increment()
    {
        if(0 != m_istream){
            getline(*m_istream, m_current_value);
            if(! m_istream->good()){
                m_istream = 0;
            }
        }
    }

public:
	explicit line_iterator()
		:m_istream(0)
	{}
	explicit line_iterator(std::istream &input)
		:m_istream(&input)
	{}
private:
	value_type m_current_value;
	std::istream *m_istream;
};

#endif /* LINE_ITERATOR_H_ */
