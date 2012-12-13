#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "dynArray.h"

#include <stdexcept>

template<typename T>
dynArray<T> makedynArray(std::initializer_list<T> ilist)
{
	return dynArray<T>{ilist};
}

void constructorTest() {
	auto dCharArray = makedynArray<char>({});

	ASSERT_EQUAL(dCharArray.size(), 0);

	dynArray<int> dIntArray{1,2,3,4};
	ASSERT_EQUAL(dIntArray.size(), 4);

	ASSERT_EQUAL(dIntArray[0], 1);
	ASSERT_EQUAL(dIntArray[1], 2);
	ASSERT_EQUAL(dIntArray[2], 3);
	ASSERT_EQUAL(dIntArray[3], 4);

	dynArray<double> dDoubleArray(10,3.14);
	ASSERT_EQUAL(dDoubleArray.size(), 10);


	dynArray<std::string> dStringArray(std::istream_iterator<std::string>{std::cin},std::istream_iterator<std::string>{});

}

void negativeIndexTest() {
	dynArray<int> intArray{1,2,3,4};

	ASSERT_EQUAL(4, intArray[-1]);
	ASSERT_EQUAL(3, intArray[-2]);
	ASSERT_EQUAL(2, intArray[-3]);
	ASSERT_EQUAL(1, intArray[-4]);
}

void invalidIndexTest() {

	std::string str{"test"};
	dynArray<std::string> sArr(5, str);
	ASSERT_THROWS(sArr[6], std::out_of_range );

	ASSERT_THROWS(sArr[-6], std::out_of_range );
}

void iteratorTest() {
	dynArray<double> doubleArray{1.0,2.0,3.0,4.0};

	int i=0;
	for(auto it = doubleArray.begin(); it != doubleArray.end(); ++it) {
		ASSERT_EQUAL(*it, doubleArray[i++]);
	}
}

void clearEmptyTest() {
	auto cArr = makedynArray<char>({'a', 'b'});
	ASSERT_EQUAL(2, cArr.size());
	ASSERT_EQUAL(false, cArr.empty());
	cArr.clear();
	ASSERT_EQUAL(0, cArr.size());
	ASSERT_EQUAL(true, cArr.empty());

}

void pushPopTest() {
	auto arr = makedynArray<float>({});
	arr.push_back(1.0f);
	ASSERT_EQUAL(1, arr.size());
	arr.pop_back();
	ASSERT_EQUAL(0, arr.size());
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(constructorTest));
	s.push_back(CUTE(negativeIndexTest));
	s.push_back(CUTE(invalidIndexTest));
	s.push_back(CUTE(iteratorTest));
	s.push_back(CUTE(clearEmptyTest));
	s.push_back(CUTE(pushPopTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



