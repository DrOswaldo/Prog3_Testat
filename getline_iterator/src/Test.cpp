#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include <string>
#include <iterator>
#include <sstream>

#include "line_iterator.h"

void iteratorTest() {
	std::stringstream str{"test\ntest2"};
	std::istream_iterator<std::string> in{str};
	std::istream_iterator<std::string> eof{};

	line_iterator it{str};
	line_iterator end{};

	std::vector<std::string> output(2);

	std::distance(it, end);

}

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(iteratorTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



