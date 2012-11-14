#include "Word.h"
#include <algorithm>
#include <istream>

void Word::read(std::istream& in) {
	std::string tmp{};
	using input=std::istreambuf_iterator<char>;
	input eof{};
	input init{in};
	// Abuse of find_if to do a copy_until to gain creativity points
	auto it=std::find_if(init, eof, [&tmp](const char c) {
			if(::isalpha(c)) {
				tmp.push_back(c);
			}
			else {
				if(! tmp.empty()) {
					return true;
				}
			}
			return false;
		}
	);
	// find_if does not touch the stream, so we have to set the eof bit by ourself
	if( it==eof) {
		in.clear(std::ios_base::eofbit | in.rdstate());
	}
	if (tmp.empty()) {
		in.clear(std::ios_base::failbit | in.rdstate());
	}
	else {
		m_Word = tmp;
	}
}
