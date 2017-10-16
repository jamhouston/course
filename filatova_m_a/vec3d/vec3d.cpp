#include "Vec3d.h"
#include <iostream>
#include <iostream>


Vec3d::Vec3d(double x_i, double y_i, double z_i) : x = x_i, y = y_i, z = z_i; {}


bool Vec3d::Vec3d& operator ==(const Vec3d& rhs) {return (abs(x - rhs.x)) < E && (abs(y - rhs.y) < E) && (abs(z - rhs.z) < E); }


bool Vec3d::Vec3d& operator !=(const Vec3d& rhs) { return !operator==(rhs); }


Vec3d& Vec3d::operator +=(const Vec3d& rhs) 
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}


Vec3d& Vec3d::operator +=(const Vec3d& rhs) 
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}


Vec3d& Vec3d::operator *=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}


Vec3d& Vec3d::operator /=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}


Vec3d Vec3d::operator +(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.x + rhs.y;
	res.z = lhs.z + rhs.z;
	return res;
}

Vec3d Vec3d::Vec3d operator -(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.x - rhs.y;
	res.z = lhs.z - rhs.z;
	return res;
}


 Vec3d Vec3d::operator *(const double lhs, const Vec3d& rhs)
 {
    Vec3d res;
	res.x = lhs * rhs.x;
	res.y = lhs * rhs.y;
	res.z = lhs * rhs.z;
	return res;
 }


 Vec3d Vec3d::operator *(const Vec3d& lhs, const double rhs)
 {
    return operator *(const double lhs, const Vec3d& rhs);
 }


 Vec3d Vec3d::operator *(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d res;
	for(int i = 0; i < 3; i++)
	{
         res[i] = lhs[i + 1] * rhs[i + 2] - lhs[i + 2] * rhs[i + 1];
	}
	return res;
}


 Vec3d Vec3d::operator /(const Vec3d& lhs, const double rhs)
 {
    Vec3d res;
	res.x = lhs.x / rhs;
	res.y = lhs.y / rhs;
	res.z = lhs.z / rhs;
	return res;
 }


std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
	using namespace std;
    ostrm << leftBrace << x << separator << y << separator << z << rightBrace << endl;
    return ostrm;
}


std::istream& Vec3d::readFrom(std::istream& istrm)
{
	char leftBrace_i(0);
	double x_i(0.0);
	char sep1(0);
	double y_i(0.0);
	char sep2(0);
	double z_i(0.0);
	char rightBrace_i(0);
	istrm >> leftBrace >> x >> sep1 >> y >> sep2 >> z >> rightBrace;
	if (istrm.good())
	{
		if ((leftBrace == leftBrace_i) && (separator == sep1) && (separator == sep2) (rightBrace == rightBrace_i))
		{
			x = x_i;
			y = y_i;
			z = z_i;
		}
		else {
			istrm.setstate((std::ios_base::failbit));
		}
	}
	return istrm;
}

std::ostream& operator<<(std::ostream& ostr, const Vec3d& a)
{
    return a.writeTo(ostr);
}
std::istream& operator>>(std::istream& istr, Vec3d& a)
{
    return a.readFrom(istr);
}

