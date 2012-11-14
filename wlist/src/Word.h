#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

class Word {
public:
	std::string getWord() const
		{return m_Word;};
	void read(std::istream& in);
	void print(std::ostream& out) const
		{out << getWord();}
private:
	std::string m_Word;
};

inline std::istream& operator>>(std::istream& in, Word & w){
	w.read(in);
	return in;
}

inline std::ostream& operator<<(std::ostream& out, Word const& w){
	w.print(out);
	return out;
}

#endif // WORD_H_
