#include "array.h"

#include "iostream"


Array::Array(const int item)
{
	pdata_ = new int[item];
	size_ = item;
	capacity_ = item;
	for(int i = 0; i < item; ++i)
	{
		*(pdata_ + i) = 0;
	}
}


void Array::add()
{
	if (size_ < capacity_) ++size_;
	else
	{
		capacity_ *= 2;
		int* newpdata_ = new int[capacity_];
		for (int i = 0; i < size_; ++i)
		{
			*(newpdata_ + i) = *(pdata_ + i);
		}
		pdata_ = newpdata_;
		++size_;
	}
}


int Array::size() const 
{ 
	return size_;#include "array.h"

#include "iostream"


Array::Array(const int item)
{
	pdata_ = new int[item];
	size_ = item;
	capacity_ = item;
	for(int i = 0; i < item; ++i)
	{
		*(pdata_ + i) = 0;
	}
}


void Array::add()
{
	if (size_ < capacity_) ++size_;
	else
	{
		capacity_ *= 2;
		int* newpdata_ = new int[capacity_];
		for (int i = 0; i < size_; ++i)
		{
			*(newpdata_ + i) = *(pdata_ + i);
		}
		pdata_ = newpdata_;
		++size_;
	}
}


int Array::size() const 
{ 
	return size_;
}


int& Array::operator[] (const ptrdiff_t item)
{
	if (item > 0 && item < size)
	{
		return pdata_[i];
	}
}




}


int& Array::operator[] (const ptrdiff_t item)
{
	if (item > 0 && item < size)
	{
		return pdata_[i];
	}
}



