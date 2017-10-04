#include "complex.h"

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

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

Complex::Complex(const double real) : Complex(real, 0.0) {}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator+=(const double rhs)
{
	return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) // ya sdelyal'
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator-=(const double rhs)
{
	return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs) // ya sdelyal
{
	re = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	return *this;
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) // ya sdelyal'
{
	Complex dif(lhs);
	dif -= rhs;
	return dif;
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

Complex& Complex::Power(const Complex& comp_num, const int power)
{
	double phi = atan2(comp_num.im, comp_num.re);
	double modulus = comp_num.re * comp_num.re + comp_num.im * comp_num.im;
	double res_modulus = pow(modulus, power);
	double res_phi = power * phi;
	Complex res = Complex();
	res.re = res_modulus * cos(res_phi);
	res.im = res_modulus * sin(res_phi);
	return res;
}
/*
std::vector<Complex>& Root(const Complex& comp_num, const int power)
{
	double phi = atan2(comp_num.im, comp_num.re);
	double modulus = comp_num.re * comp_num.re + comp_num.im * comp_num.im;
	double res_modulus = pow(modulus, 1 / power);
	double res_phi = power / phi;
}
*/