#include "line_iterator.h"

//std::istringstream line_iterator::dummy{};

bool line_iterator::operator==( const line_iterator& b) const
{
	return in == b.in;
}
