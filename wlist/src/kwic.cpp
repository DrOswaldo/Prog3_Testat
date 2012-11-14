#include "Word.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
 #include <stdexcept> // out_of_range exception

int main() {
	std::vector< std::vector<std::string> > lines{};
	size_t maxCount { 0 };

	while(!std::cin.eof() && std::cin.good()) {
		std::string line{};
		std::getline(std::cin, line);

		std::vector<Word> words{};
		std::vector<std::string> row{};
		std::stringstream iss{};
		iss << line;

		while(!iss.eof() && iss.good())
		{
			Word w{};
			iss >> w;
			words.push_back(w);
		}
		if ( words.size() > maxCount)
		{ maxCount = words.size(); }

		for (unsigned cWord = 0; cWord < words.size(); cWord++)
		{
			std::string tmpLine{};
			rotate(words.begin(), words.begin()+1, words.end());
			for (unsigned i = 0; i < words.size(); i++)
			{
				tmpLine = tmpLine + words[i].getWord() + " ";
			}
			row.push_back(tmpLine);
		}
		std::sort(row.begin(),row.end());
		lines.push_back(row);
	}
	for (unsigned i = 0; i < maxCount; i++)
	{
		for(unsigned u = 0; u < lines.size(); u++)
		{
			try
			{
				std::cout << lines[u].at(i) << std::endl;
			} catch (std::out_of_range& oor)
			{

			}
		}
	}

}

