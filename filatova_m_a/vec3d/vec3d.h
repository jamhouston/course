#ifndef Vec3d_H
#define VEC3D_H

#include <iosfwd>
#include <iostream>
#include <sstream>

class Vec3d {
public:
	Vec3d() = default;
	explicit Vector(const double x_i, const double y_i, const double z_i);
	~Vec3d() = default;
	Vec3d& operator=(const Vec3d& rhs) = default;
    bool operator ==(const Vec3d& rhs) const;
    bool operator !=(const Vec3d& rhs) const;
    Vec3d& operator +=(const Vec3d& rhs);
    Vec3d& operator -=(const Vec3d& rhs);
    Vec3d& operator *=(const double rhs);
    Vec3d& operator /= (const double rhs);
    std::ostream& writeTo(std::ostream& ostr) const;
    std::istream& readFrom(std::istream& istr);
    Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);
    Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);
    Vec3d operator*(const double lhs, const Vec3d& rhs);
    Vec3d operator*(const Vec3d& lhs, double rhs);
    Vec3d operator/(const Vec3d& a, const double b);
    std::ostream& operator << (std::ostream& ostr, const Vec3d& a);
    std::istream& operator >> (std::istream& istr, Vec3d& a);

    double x {0.0};
    double y {0.0};
    double z {0.0};

private:
	const double EPS{ 1.0e-8 };
    static const char leftBrace{ '{' };
    static const char separator{ ';' };
    static const char rightBrace{ '}' };

}
#endif
