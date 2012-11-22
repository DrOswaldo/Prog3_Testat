#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;
using std::minus;
using std::multiplies;
using std::divides;
using std::bind;
using std::modulus;


void plus() {
	double x = 1;
	double y = 2;
	auto plus = std::bind(std::plus<double>{}, _1, _2);

	ASSERT_EQUAL(plus(x,y), x+y);
}

void multiplyDivide() {
	double x = 1;
	double y = 2;
	double result = (2.0*x)-(y/3.0);

	auto m = bind(minus<double>{}, _1, _2);
	auto mply = bind(multiplies<double>{}, _1, _2);
	auto div = bind(divides<double>{}, _1, _2);

	auto func = bind(m, bind(mply, 2, _1), bind(div,_2,3));

	ASSERT_EQUAL(func(x,y), result);
}

void squareModulo() {
	int x = 7;
	int y = 2;

	int result = (x * x) % y;

	auto func = bind(modulus<int>{},  bind(multiplies<int>{}, _1, _1) , _2);

	ASSERT_EQUAL(func(x,y), result);
}
/*
(x * x) % y // unsigned integral values
sqrt(x * x) // as simple test case
-(x/2)+sqrt( (x/2)*(x/2) - y ) // p-q formula for quadratic equation with x=p, y=q

*/

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(plus));
	s.push_back(CUTE(multiplyDivide));
	s.push_back(CUTE(squareModulo));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



