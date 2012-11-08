#include "Word.h"
#include <cctype>

void Word::read(std::istream& in) {
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
	/*
	do {
		std::string tmp;
		in >> tmp;
		std::copy_if(tmp.begin(), tmp.end(), back_inserter(m_Word), ::isalpha);
	}while(m_Word.empty());
	*/
}
