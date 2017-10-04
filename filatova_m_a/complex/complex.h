#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>

struct Complex
{
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	Complex& Power(const Complex& comp_num, const int power);


	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

std::ostream& operator<<(std::ostream& ostrm, Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);

bool testParse(const std::string& str);

#endif