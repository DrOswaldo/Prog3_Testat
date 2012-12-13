#include "getline_iterator.h"

line_iterator::line_iterator(std::istream &input)
	:m_istream(&input)
{
	getline(*m_istream, m_current_value);
}

line_iterator::value_type line_iterator::dereference() const
{
	return m_current_value;
}

bool line_iterator::equal(const line_iterator & rhs) const
{
	return m_istream == rhs.m_istream;
}

void line_iterator::increment()
{
	if(0 != m_istream){
		getline(*m_istream, m_current_value);
		if(! m_istream->good()){
			m_istream = 0;
		}
	}
}
