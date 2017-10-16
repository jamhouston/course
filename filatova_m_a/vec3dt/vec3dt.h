#ifndef Vec3dT_H
#define Vec3dt_H_H

#include <iosfwd>
#include <iostream>
#include <sstream>

template <typename T>
class Vec3dT {
public:
	Vec3dT() = default;
	explicit VectorT(const T x_i, const T y_i, const T z_i);
	~Vec3dT() = default;
	Vec3dT& operator=(const Vec3dT<T>& rhs) = default;
    bool operator ==(const Vec3dT<T>& rhs) const;
    bool operator !=(const Vec3dT<T>& rhs) const;
    Vec3dT& operator +=(const Vec3dT<T>& rhs);
    Vec3dT& operator -=(const Vec3dT<T>& rhs);
    Vec3dT& operator *=(const double rhs);
    Vec3dT& operator /= (const double rhs);
    Vec3dT operator +(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs);
    Vec3dT operator -(const Vec3d<T>& lhs, const Vec3dT<T>& rhs);
    Vec3dT operator *(const double lhs, const Vec3d& rhs);
    Vec3dT operator *(const Vec3dT<T>& lhs, double rhs);
    Vec3dT operator *(const Vec3dT<T>& lhs, const Vec3d<T>& rhs);
    Vec3dT operator/(const Vec3dT<T>& a, const double b);
    std::ostream& writeTo(std::ostream& ostr) const;
    std::istream& readFrom(std::istream& istr);

    T x {0.0};
    T y {0.0};
    T z {0.0};


    std::ostream& operator << (std::ostream& ostr, const Vec3d& a);
    std::istream& operator >> (std::istream& istr, Vec3d& a);

private:
	const double E{ 1.0e-7 };
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };

}


template <typename T>
Vec3dT<T>::Vec3dT(T x_i, T y_i, T z_i) : x(x_i), y(y_i), z(z_i); {}


template <typename T>
bool Vec3dT<T>::Vec3dT& operator ==(const Vec3dT<T>& rhs) {return (abs(x - rhs.x)) < E && (abs(y - rhs.y) < E) && (abs(z - rhs.z) < E); }


template <typename T>
bool Vec3dT<T>::Vec3dT& operator !=(const Vec3dT<T>& rhs) { return !operator==(rhs); }


template <typename T>
Vec3dT<T>& Vec3dT<T>::operator +=(const Vec3dT<T>& rhs) 
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}


template <typename T>
Vec3dT<T>& Vec3dT<T>::operator -=(const Vec3dT<T>& rhs) 
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

template <typename T>
Vec3dT<T>& Vec3dT<T>::operator *=(const T rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}


template <typename T>
Vec3dT<T>& Vec3dT<T>::operator /=(const T rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}


template <typename T>
Vec3dT<T> Vec3dT<T>::operator +(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
{
	Vec3dT res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.x + rhs.y;
	res.z = lhs.z + rhs.z;
	return res;
}


template <typename T>
Vec3dT<T> Vec3dT<T>::operator -(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
{
	Vec3dT res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.x - rhs.y;
	res.z = lhs.z - rhs.z;
	return res;
}

template <typename T>
 Vec3dT<T> Vec3dT<T>::operator *(const T lhs, const Vec3dT<T>& rhs)
 {
    Vec3d res;
	res.x = lhs * rhs.x;
	res.y = lhs * rhs.y;
	res.z = lhs * rhs.z;
	return res;
 }


 template <typename T>
 Vec3dT<T> Vec3dT<T>::operator *(const Vec3dT<T>& lhs, const T rhs)
 {
    return operator *(const double lhs, const Vec3dT<T>& rhs);
 }


 template <typename T>
 Vec3dT<T> Vec3dT<T>::operator *(const Vec3dT<T>& lhs, const Vec3d& rhs)
{
	Vec3d res;
	for(int i = 0; i < 3; i++)
	{
         res[i] = lhs[i + 1] * rhs[i + 2] - lhs[i + 2] * rhs[i + 1];
	}
	return res;
}


template <typename T>
 Vec3dT<T> Vec3dT<T>::operator /(const Vec3dT<T>& lhs, const T rhs)
 {
    Vec3d res;
	res.x = lhs.x / rhs;
	res.y = lhs.y / rhs;
	res.z = lhs.z / rhs;
	return res;
 }


 template <typename T>
 std::ostream& Vec3dT<T>::writeTo(std::ostream& ostrm) const
{
	using namespace std;
    ostrm << leftBrace << x << separator << y << separator << z << rightBrace << endl;
    return ostrm;
}

template <typename T>
std::istream& Vec3dT<T>::readFrom(std::istream& istrm)
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


template <typename T>
std::ostream& operator<<(std::ostream& ostr, const Vec3dT<T>& a)
{
    return a.writeTo(ostr);
}


template <typename T>
std::istream& operator>>(std::istream& istr, Vec3dT<T>& a)
{
    return a.readFrom(istr);
}


#endif
