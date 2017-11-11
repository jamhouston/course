#include <iostream>
#include <cmath>

class Interval2d
{
public:
	double begin1 {0.0};
	double end1{0};
	double begin2{0.0};
	double end2{0.0};
	explicit Interval2d(double begin_i, double end_i);
	Interval2d(double length);
	Interval2d()  = default;
	~Interval2d() = default;
	bool operator==(const Interval2d& rhs) const;
	bool operator!=(const Interval2d& rhs) const;
	Interval2d& Unite(const Interval2d& first, const Interval2d& second);
	Interval2d& Intersection(const Interval2d& first, const Interval2d& second);
	bool IfBelong(const double point, const Interval2d interval);
	Interval2d& Move(const double movement, const Interval2d& interval);
	double Length(const Interval2d& interval);
	std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
	double E = 1.0e-8;
	static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };

};

inline std::ostream& operator<<(std::ostream& ostrm, Interval2d& rhs)
{
    return rhs.writeTo(ostrm);
}
 
inline std::istream& operator >> (std::istream& istrm, Interval2d& rhs)
{
    return rhs.readFrom(istrm);
}

Interval2d::Interval2d(double begin_i, double end_i) : begin1(begin_i), end2(end_i), end1((begin_i + end_i) / 2), begin2((begin_i + end_i) / 2)
{}


Interval2d::Interval2d(double length) :
    begin1(0.0),
    end2(length),
    end1(length / 2),
	begin2(length / 2)
{}


bool Interval2d::operator==(const Interval2d& rhs) const
{
	return (abs(begin1 - rhs.begin1) < E && abs(end1 - rhs.end1) < E && (begin2 - rhs.begin2) < E && abs(end2 - rhs.end2) < E);
}


bool Interval2d::operator!=(const Interval2d& rhs) const
{
	return !(operator==(rhs));
}


Interval2d& Interval2d::Unite(const Interval2d& first, const Interval2d& second)
{
    Interval2d res;
    if (first.end2 < second.begin1) 
    {
         res.begin1 = first.begin1;
         res.end1 = first.end2;
         res.begin2 = second.begin1;
         res.end2 = second.end2;
    }
    else
    {
    	res.begin1 = std::min(first.begin1, second.begin1);
    	res.end2 = std::max(first.end2, second.end2);
    	res.end1 = (res.begin1 + res.end2) / 2;
    	res.end2 = (res.begin1 + res.end2) / 2;
    }
    return res;

}

bool Interval2d::IfBelong(const double point, const Interval2d interval)
{
	return ((point > interval.begin1) && (point < interval.end2));
}


Interval2d& Interval2d::Move(const double movement, const Interval2d& interval)
{
	Interval2d res(interval.begin1 + movement, interval.end2 + movement);
	return res;
}


double Interval2d::Length(const Interval2d& interval)
{
	return (abs(interval.begin1 - interval.end2));	

}

std::ostream& Interval2d::writeTo(std::ostream& ostrm) const
{
    using namespace std;
    ostrm << leftBrace << begin1<< separator << end2 << rightBrace << endl;
    return ostrm;
}
 
std::istream& Interval2d::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double begin(0.0);
    char comma(0);
    double end(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> begin >> comma >> end >> rightBrace;
    if (istrm.good())
    {
        if ((Interval2d::leftBrace == leftBrace) && (Interval2d::separator == comma) && (Interval2d::rightBrace == rightBrace))
        {
            begin1 = begin;
            end2 = end;
        }
        else {
            istrm.setstate((std::ios_base::failbit));
        }
    }
    return istrm;
}

int main()
{
	Interval2d obj(2, 4);
	std::cout << obj << std::endl;
	return 0;
}
