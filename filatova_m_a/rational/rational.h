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
	bool operator==(const Rational& lhs);
	bool operator!=(const Rational& lhs);
	bool operator>(const Rational& a) const;
	bool operator<(const Rational& a) const;
	bool operator>=(const Rational& a) const;
    bool operator<=(const Rational& a) const;
	Rational& operator+(const Rational& rhs, const Rational& lhs);
	Rational& operator+(const Rational& rhs, const int lhs);
	Rational& operator+(const int rhs, const Rational& lhs);
	Rational& operator-(const Rational& rhs, const Rational& lhs);
	Rational& operator-(const Rational& rhs, const int lhs);
	Rational& operator-(const int rhs, const Rational& lhs);
	Rational& operator+=(const Rational& lhs);
	Rational& operator+=(const int lhs);
	Rational& operator-=(const Rational& lhs);
	Rational& operator-=(const int lhs);
	Rational& operator*(const Rational& rhs, const Rational& lhs);
	Rational& operator*(const Rational& rhs, const int lhs);
	Rational& operator*(const int rhs, const Rational& lhs);
	Rational& operator/(const Rational& rhs, const Rational& lhs);
	Rational& operator/(const Rational& rhs, const int lhs);
	Rational& operator/(const int rhs, const Rational& lhs);
	Rational& operator*=(const Rational& lhs);
	Rational& operator*=(const int lhs);
	Rational& operator/=(const Rational& lhs);
	Rational& operator/=(const int lhs);
	std::ostream &writeTo(std::ostream &ostr) const;
	std::istream &readFrom(std::istream &istrm);


	int num { 0 };
	int den { 1 };
}

std::ostream& operator<<(std::ostream& ostrm, Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);

private int GCD(int lhs,  int rhs);
private int LCM(int lhs, int rhs);
private void Reduce(ational& ratio);
bool testParse(const std::string& str);


#endif
