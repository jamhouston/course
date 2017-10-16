#include "rational.h"
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <cmath>

inline std::ostream& operator<<(std::ostream& ostrm, Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

Rational::Rational(const int numenator, const int denominator) : num(numenator), den(denominator) {}

Rational::Rational(const int numenator) : Complex(numenator, 1.0) {}

bool operator==(const Rational& rhs, const Rational& lhs)
{

}

inline std::ostream& operator<<(std::ostream& ostrm, Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}


bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error: " << str << " -> " << z << endl;
	}
	return istrm.good();
}

private int GCD(int lhs, int rhs)
{
	int temp;
	while(rhs) 
	{
        temp = lhs % rhs;
        lhs = rhs;
        rhs = temp;
	}
	return abs(lhs);
}

private int LCM(int lhs, int rhs)
{
    return (lhs * rhs) / gcd(lhs, rhs)
}

private void Reduce(Rational& ratio)
{
    int gcd = GCD(ratio.num, ratio.den);
    ratio.num /= gcd;
    ratio.den /= gcd;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	using namespace std;
	ostrm << leftBrace << re << separator << im << rightBrace << endl;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good())
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
		{
			re = real;
			im = imaginary;
		}
		else {
			istrm.setstate((std::ios_base::failbit));
		}
	}
	return istrm;
}

