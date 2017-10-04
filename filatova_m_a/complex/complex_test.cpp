#include <iostream>
#include <sstream>
#include "complex.h"


int main()
{
	using namespace std;

	Complex z;
	z += Complex(8.0);
	z += 8;
	cout << z << endl;
	z -= 4;
	z -= Complex(5.0, 3.0);
	cout << "-=" << z << endl;
	z *= 2;
	cout << "*= double" << z << endl;
	z *= Complex(2.0, -1.0);
	cout << "*= complex" << z << endl;
	z = z.Power(z, 3);
	cout << "power" << z << endl;
	testParse("{8.0,9}");
	testParse("{8.0, 9}");
	testParse("{8.9,9");
	return 0;
};