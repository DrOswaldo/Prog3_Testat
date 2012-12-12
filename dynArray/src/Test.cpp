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

	ASSERT_EQUAL(dCharArray.size(), 0);

	dynArray<int> dIntArray{1,2,3,4};
	ASSERT_EQUAL(dIntArray[0], 1);
	ASSERT_EQUAL(dIntArray[1], 2);
	ASSERT_EQUAL(dIntArray[2], 3);
	ASSERT_EQUAL(dIntArray[3], 4);

	dynArray<double> dDoubleArray(10,3.14);

	//dynArray<std::string> dStringArray(std::istream_iterator<std::string>{std::cin},std::istream_iterator<std::string>{});

}

void negativeIndexTest() {
	dynArray<int> intArray{1,2,3,4};

	ASSERT_EQUAL(4, intArray[-1]);
	ASSERT_EQUAL(3, intArray[-2]);
	ASSERT_EQUAL(2, intArray[-3]);
	ASSERT_EQUAL(1, intArray[-4]);
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(constructorTest));
	s.push_back(CUTE(negativeIndexTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



