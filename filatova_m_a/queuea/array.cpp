#include "array.h"
#undef main
#include <iostream>
#include <stdexcept>


Array::Array(const int item)
{
	pdata_ = new int[item];
	capacity_ = item;
	size_ = item;
	for (int i = 0; i < item; ++i)
	{
		*(pdata_ + i) = 0;
	}
}

void Array::Add() {
	if (size_ < capacity_) {
		size_++;
	}
	else {
		int* new_pdata = new int[capacity_ * 2];
		for (int i = 0; i < size_; i++) {
			*(new_pdata + i) = *(pdata_ + i);
		}
		std::swap(new_pdata, pdata_);
		size_++;
		capacity_ *= 2;
	}
}


Array& Array::operator=(const Array& rhs)
{
	pdata_ = new int[rhs.Size()];
	for (int i = 0; i < rhs.Size(); ++i)
	{
		*(pdata_ + i) = rhs[i];
	}
	size_ = rhs.Size();
	capacity_ = rhs.Size();
	return *this;
}



const int& Array::operator[](const ptrdiff_t index) const
{
	if (index >= 0 && index < size_)
	{
		return pdata_[index];
	}
	else
	{
		throw std::out_of_range("Index is out of range.");
	}
}



int Array::Size() const
{
	return size_;
}


void Array::Push_back(const int item)
{
	Add();
	*(pdata_ - 1 + size_) = item;
}


void Array::Insert(int pos, int item)
{
	if (pos >= 0 && pos < size_)
	{
		Push_back(item);
		for (int i = size_ - 1; i > pos; --i)
		{
			int temp{ 0 };
			temp = pdata_[i];
			pdata_[i] = pdata_[i - 1];
			pdata_[i - 1] = temp;
		}
	}
	else
	{
		throw std::out_of_range("Index is out of range.");
	}
}

