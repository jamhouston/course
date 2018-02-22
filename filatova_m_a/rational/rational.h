#ifndef RATIONAL_H
#define RATIONAL_H

#include <iosfwd>
#include <iostream>
#include <sstream>

struct Rational
{
	Rational() {}
	explicit Rational(const int numenator, const int denominator);
	Rational(const int numenator);
	bool operator==(const Rational& lhs) const;
	bool operator!=(const Rational& lhs) const;
	bool operator>(const Rational& lhs) const;
	bool operator<(const Rational& lhs) const;
	bool operator>=(const Rational& lhs) const;
	bool operator<=(const Rational& lhs) const;
	Rational& operator+=(const Rational& lhs);
	Rational& operator+=(const int lhs);
	Rational& operator-=(const Rational& lhs);
	Rational& operator-=(const int lhs);
	Rational& operator*=(const Rational& lhs);
	Rational& operator*=(const int lhs);
	Rational& operator/=(const Rational& lhs);
	Rational& operator/=(const int lhs);


	std::ostream &writeTo(std::ostream &ostr) const;
	std::istream &readFrom(std::istream &istrm);


	long int num{ 0 };
	long int den{ 1 };
	static const char leftBrace{ '{' };
	static const char separator{ '/' };
	static const char rightBrace{ '}' };
};


Rational& operator+(const Rational& rhs, const Rational& lhs);
Rational& operator+(const Rational& rhs, const int lhs);
Rational& operator+(const int rhs, const Rational& lhs);
Rational& operator-(const Rational& rhs, const Rational& lhs);
Rational& operator-(const Rational& rhs, const int lhs);
Rational& operator-(const int rhs, const Rational& lhs);

Rational& operator*(const Rational& rhs, const Rational& lhs);
Rational& operator*(const Rational& rhs, const int lhs);
Rational& operator*(const int rhs, const Rational& lhs);
Rational& operator/(const Rational& rhs, const Rational& lhs);
Rational& operator/(const Rational& rhs, const int lhs);
Rational& operator/(const int rhs, const Rational& lhs);

std::ostream& operator<<(std::ostream& ostrm, Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

int GCD(int lhs, int rhs);
int LCM(int lhs, int rhs);
Rational Reduce(Rational& ratio);
bool testParse(const std::string& str);


#endif
