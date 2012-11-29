#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "dynArray.h"

template<class T>
dynArray<T> makedynArray(std::initializer_list<T> ilist)
{
	return dynArray<T>{ilist};
}

void constructorTest() {
	auto dCharArray = makedynArray<char>({});


	dynArray<int> dIntArray{1,2,3,4};
	dynArray<double> dDoubleArray(10,3.14);
	dynArray<std::string> dStringArray(std::istream_iterator<std::string>{std::cin},std::istream_iterator<std::string>{});

	ASSERTM("start writing tests", false);	
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(constructorTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



