#include "rational.h"
#include <iostream>

int main()
{
	using namespace std;

	Rational obj0;
	cout << "obj0() = " << obj0 << endl;
	Rational obj1 = Rational(4, 5);
	cout << "obj1(4, 5) = " << obj1 << endl;
	Rational obj2 = Rational(3);
	cout << "obj2(3) = " << obj2 << endl;

	Rational a = Rational(2, 3);
	Rational b = Rational(4, 5);

	cout << "(a == b) : " << (a == b) << endl;
	cout << "(a != b) : " << (a != b) << endl;
	cout << "(a > b) : " << (a > b) << endl;
	cout << "(a < b) : " << (a < b) << endl;

	a = Rational(3, 4);
	b = Rational(4, 3);
	Rational c = a + b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << c << endl;
	c = b - a;
	cout << "b - a = " << c << endl;
	int exit;
	cin >> exit;

	

}
