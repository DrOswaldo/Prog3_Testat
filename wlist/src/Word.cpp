#include "Word.h"
#include <cctype>
#include <iostream>

void Word::read(std::istream& in) {

	/*
	while(in.good()) {
		char c = in.get();
		if(::isalpha(c)) {
			m_Word.push_back(c);
		}
		else {
			if(!m_Word.empty()){
				return;
			}
		}
	}
	*/


	// @TODO: use temporary string and only apply to m_Word when succsessfull

	using input=std::istreambuf_iterator<char>;
	input eof{};
	input init{in};
	auto it=std::find_if(init, eof, [this](const char c) {
			if(::isalpha(c)) {
				this->m_Word.push_back(c);
			}
			else {
				if(! this->m_Word.empty()) {
					return true;
				}
			}
			return false;
		}
	);
	if( it==eof) {
		in.clear(std::ios_base::eofbit | in.rdstate());
	}
	if (m_Word.empty()) in.clear(std::ios_base::failbit|in.rdstate());
	/*
	do {
		std::string tmp;
		in >> tmp;
		std::copy_if(tmp.begin(), tmp.end(), back_inserter(m_Word), ::isalpha);
	}while(m_Word.empty());
	*/
}
