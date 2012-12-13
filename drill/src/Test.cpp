#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;
using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
using std::negate;
using std::bind;
using std::modulus;

void testPlus() {
	double x = 1;
	double y = 2;
	auto func = bind(plus<double>{}, _1, _2);

	ASSERT_EQUAL(func(x,y), x+y);
}

void multiplyDivide() {
	double x = 1;
	double y = 2;
	double result = (2.0*x)-(y/3.0);

	auto m    = minus<double>{};
	auto mply = multiplies<double>{};
	auto div  = divides<double>{};

	auto func = bind(m, bind(mply, 2, _1), bind(div,_2,3));

	ASSERT_EQUAL(func(x,y), result);
}

template<class T>
std::function< T(T) > getSquare() {
	return bind(multiplies<T>{},_1,_1);
}

void squareModulo() {
	int x = 7;
	int y = 2;
	int result = (x * x) % y;

	auto square = getSquare<unsigned>();

	auto func = bind(modulus<unsigned>{},  bind(square, _1), _2);

	ASSERT_EQUAL(func(x,y), result);
}

void sqrtSquare() {
	double x = 7;
	double result = sqrt(x * x);

	auto square = getSquare<double>();

	auto func = bind( sqrt, bind(square,_1) );

	ASSERT_EQUAL(func(x), result);
}

void pqFormula() {
	double x = 7;
	double y = 7;
	double result = -(x/2)+sqrt( (x/2)*(x/2) - y );

	auto div = divides<double>{};
	auto p   = plus<double>{};
	auto n   = negate<double>{};
	auto m   = minus<double>{};

	auto half = bind(div, _1, 2);
	auto square = getSquare<double>();

	auto tmp = bind(m, bind(square, bind(half,_1) ), _2 );

	auto func = bind(p,
		bind(n, bind(half, _1) ),
		bind(sqrt,
			bind(tmp,_1,_2)
		)
	);

	ASSERT_EQUAL(func(x,y), result);
}


void runSuite(){
	cute::suite s;

	s.push_back(CUTE(testPlus));
	s.push_back(CUTE(multiplyDivide));
	s.push_back(CUTE(squareModulo));
	s.push_back(CUTE(sqrtSquare));
	s.push_back(CUTE(pqFormula));

	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



