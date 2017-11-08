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
	Array& operator=(const Array& rhs) = default;
	int& operator[](const ptrdiff_t item);

private:
    ptrdiff_t capacity_ { 0 };
    ptrdiff_t size_ { 0 };
    int* pdata_ { nullptr };
    void add();
    int size() const;


};


#endif
