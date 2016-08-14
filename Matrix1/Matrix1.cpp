

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
#include "Array2.h"

using namespace std;
using namespace Move;


void test1();
void test2();
void test3();
Array Func(Array array);

int main()
{
	test3();
    return 0;
}

void test1() {

	double a[] = { 1, 2, 3, 4,
					10, 20, 30, 40,
					100, 200, 300, 400 };
	double b[] = { 0, 1, 0,
		-1, 0, -1, 0,
		10, 0, 10, 0,
		0, -10, 0, -10};


	Matrix ma(a, 4, 3);
	Matrix mb(b, 3, 4);



}

Array Func(Array array) {
    return array;
}

void test2() {
    Array array(32);
    array = Func(array);
}

void test3() {
	double da[] = { 1, 2, 3, 4, 5 };
	double db[] = { 0, 1, 0, 1, 0 };
	double dc[] = { -10, 10, 0, 10, 1000 };

	Array a(da, 5);
	Array b(db, 5);
	Array c(dc, 5);

	Array p = a + c;
	Array q = a * b;
	Array r = a * b + c;
	Array s = c + 3.3;
	Array t = -1000.1 + c;

	p.print();
	q.print();
	r.print();
	s.print();
	t.print();
}