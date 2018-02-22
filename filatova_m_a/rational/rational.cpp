#include "rational.h"
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <cmath>


bool Rational::operator==(const Rational& lhs) const { return num == lhs.num && den == lhs.den; }


bool Rational::operator!=(const Rational& a) const { return !operator==(a); }



inline std::ostream& operator<<(std::ostream& ostrm, Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

Rational::Rational(const int numenator, const int denominator) : num(numenator), den(denominator) {}

Rational::Rational(const int numenator) : Rational(numenator, 1) {}


bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational x;
	istrm >> x;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << x << endl;
	}
	else {
		cout << "Read error: " << str << " -> " << x << endl;
	}
	return istrm.good();
}

int GCD(int lhs, int rhs)
{
	return (rhs == 0) ? abs(lhs) : GCD(rhs, lhs % rhs);
}

int LCM(int lhs, int rhs)
{
	return abs(lhs * rhs) / GCD(lhs, rhs);
}

Rational Reduce(Rational& ratio)
{
	int gcd = GCD(ratio.num, ratio.den);
	ratio.num /= gcd;
	ratio.den /= gcd;
	return ratio;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	using namespace std;
	ostrm << leftBrace << num << separator << den << rightBrace << endl;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	int numenator(0.0);
	char comma(0);
	int denominator(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> num >> comma >> den >> rightBrace;
	if (istrm.good())
	{
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == comma) && (Rational::rightBrace == rightBrace))
		{
			num = numenator;
			den = denominator;
		}
		else {
			istrm.setstate((std::ios_base::failbit));
		}
	}
	return istrm;
}


bool Rational::operator<(const Rational& lhs) const
{
	int lcm = LCM(den, lhs.den);
	return num * (lcm / den) < lhs.num * (lcm / lhs.den);
}


bool Rational::operator>(const Rational& lhs) const
{
	int lcm = LCM(den, lhs.den);
	return num * (lcm / den) > lhs.num*(lcm / lhs.den);
}


bool Rational::operator>=(const Rational& lhs) const
{
	return operator==(lhs) || operator>(lhs);
}


bool Rational::operator<=(const Rational& lhs) const
{
	return operator==(lhs) || operator<(lhs);
}


Rational& Rational::operator+=(const Rational& lhs)
{
	int lcm = LCM(den, lhs.den);
	num = num * (lcm / den) + lhs.num * (lcm / lhs.den);
	den = lcm;
	Reduce(*this);
	return *this;
}


Rational& Rational::operator-=(const Rational& lhs)
{
	int lcm = LCM(den, lhs.den);
	num = num * (lcm / den) - lhs.num * (lcm / lhs.den);
	den = lcm;
	Reduce(*this);
	return *this;
}

Rational& Rational::operator+=(const int lhs)
{
	Rational lhs_r = Rational(lhs);
	return operator+=(lhs_r);
}


Rational& Rational::operator-=(const int lhs)
{
	Rational lhs_r = Rational(lhs);
	return operator-=(lhs_r);
}


Rational& operator+(const Rational& rhs, const Rational& lhs)
{
	using namespace std;
	Rational res = Rational(rhs);
	res += lhs;
	Reduce(res);
	return res;
}


Rational& operator+(const Rational& rhs, const int lhs)
{
	Rational res = Rational(rhs);
	Rational lhs_r = Rational(lhs);
	res += lhs;
	Reduce(res);
	return res;
}


Rational& operator+(const int rhs, const Rational& lhs)
{
	Rational res = Rational(lhs);
	Rational rhs_r = Rational(rhs);
	res += rhs;
	Reduce(res);
	return res;
}


Rational& operator-(const Rational& rhs, const Rational& lhs)
{
	Rational res = Rational(rhs);
	res -= lhs;
	Reduce(res);
	return res;
}


Rational& operator-(const Rational& rhs, const int lhs)
{
	Rational res = Rational(rhs);
	Rational lhs_r = Rational(lhs);
	res -= lhs;
	Reduce(res);
	return res;
}


Rational& operator-(const int rhs, const Rational& lhs)
{
	Rational res = Rational(lhs);
	Rational rhs_r = Rational(rhs);
	res -= rhs;
	Reduce(res);
	return res;
}


Rational& Rational::operator*=(const Rational& lhs)
{
	num = num * lhs.num;
	den = den * lhs.den;
	Reduce(*this);
	return *this;
}


Rational& Rational::operator/=(const Rational& lhs)
{
	num = num / lhs.num;
	den = den / lhs.den;
	Reduce(*this);
	return *this;
}


Rational& Rational::operator*=(const int lhs)
{
	Rational lhs_r = Rational(lhs);
	return operator*=(lhs_r);
}


Rational& Rational::operator/=(const int lhs)
{
	Rational lhs_r = Rational(lhs);
	return operator/=(lhs_r);
}


Rational& operator*(const Rational& rhs, const Rational& lhs)
{
	Rational res = Rational(rhs);
	res *= lhs;
	Reduce(res);
	return res;
}


Rational& operator*(const Rational& rhs, const int lhs)
{
	Rational res = Rational(rhs);
	Rational lhs_r = Rational(lhs);
	res *= lhs;
	Reduce(res);
	return res;
}


Rational& operator*(const int rhs, const Rational& lhs)
{
	Rational res = Rational(lhs);
	Rational rhs_r = Rational(rhs);
	res *= rhs;
	Reduce(res);
	return res;
}


Rational& operator/(const Rational& rhs, const Rational& lhs)
{
	Rational res = Rational(rhs);
	res *= lhs;
	Reduce(res);
	return res;
}


Rational& operator/(const Rational& rhs, const int lhs)
{
	Rational res = Rational(rhs);
	Rational lhs_r = Rational(lhs);
	res *= lhs;
	Reduce(res);
	return res;
}


Rational& operator/(const int rhs, const Rational& lhs)
{
	Rational res = Rational(lhs);
	Rational rhs_r = Rational(rhs);
	res *= rhs;
	Reduce(res);
	return res;
}
