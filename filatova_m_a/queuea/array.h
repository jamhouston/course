#ifndef Array_H
#define ARRAY_H

#include <iosfwd>
#include <string>

class Array

{

public:
	Array() = default;
	~Array() = default;
	Array(const int item);
	Array& operator=(const Array& rhs);
	const int& Array::operator[](const ptrdiff_t index) const;
	void Push_back(const int item);
	void Insert(const int pos, const int item);	void Add();
	int Size() const;

private:
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	int* pdata_{ nullptr };



};


#endif