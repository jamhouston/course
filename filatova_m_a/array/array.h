#ifndef Array_H
#define ARRAY_H

#include <iostfwd>
#include <string>

class Array

{

public:
	Array() = default;
	~Array() = default;
	Array(const int item);
	Array& operator=(const Array& rhs) = default;

private:
    ptrdiff_t capacity_ { 0 };
    ptrdiff_t size_ { 0 };
    int* pdata_ { nullptr };
    void add();
    int size() const;
    void insert(const int item, const int position);


};


#endif
