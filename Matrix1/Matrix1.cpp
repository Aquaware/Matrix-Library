

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;
using namespace Move;


void test1();
void test2();
void test3();
Vector Func(Vector vector);

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

Vector Func(Vector array) {
    return array;
}

void test2() {
    Vector array(32);
    array = Func(array);
}

void test3() {
	double da[] = { 1, 2, 3, 4, 5 };
	double db[] = { 0, 1, 0, 1, 0 };
	double dc[] = { -10, 10, 0, 10, 1000 };

	Vector a(da, 5);
	Vector b(db, 5);
	Vector c(dc, 5);

	Vector p = a + c;
	Vector q = a * b;
	Vector r = a * b + c;
	Vector s = c + 3.3;
	Vector t = -1000.1 + c;

	Vector u = 3.2 * a / b + c / 2.0 - 0.1;

	p.print();
	q.print();
	r.print();
	s.print();
	t.print();
	u.print();
}