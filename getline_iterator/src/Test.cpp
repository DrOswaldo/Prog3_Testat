#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "line_iterator.h"

void distanceTest() {
	std::stringstream str{"test\ntest2\n"};

	line_iterator it{str};
	line_iterator end{};

	ASSERT_EQUAL(std::distance(it, end),2);
}

void copyTest() {
	std::stringstream str{"this is a line\nand this too\n"};

	line_iterator it{str};
	line_iterator end{};

	std::vector<std::string> test{};

	std::copy(it, end, back_inserter(test));

	ASSERT_EQUAL(std::distance(test.begin(), test.end()), 2);
	ASSERT_EQUAL(test.at(0), "this is a line");
	ASSERT_EQUAL(test.at(1), "and this too");
}

void equalTest() {
	std::stringstream str{"this is a line\nand this too\n"};
	std::stringstream str2{"this is a line\nand this too\n"};

	line_iterator it1{str};
	line_iterator it2{str2};
	line_iterator end{};

	ASSERT_EQUAL(std::equal(it1, end, it2), true);
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(distanceTest));
	s.push_back(CUTE(copyTest));
	s.push_back(CUTE(equalTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



