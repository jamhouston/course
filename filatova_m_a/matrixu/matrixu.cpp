#include "matrixu.h"
#include <iostream>

MatrixU::~MatrixU()
{
	delete[] pData_;
	pData_ = nullptr;
	nRow_ = ptrdiff_t{ 0 };
	nCol_ = ptrdiff_t{ 0 };
}

MatrixU::MatrixU(ptrdiff_t iCol, ptrdiff_t iRow)
{
	if (iCol > 0 && iRow > 0)
	{
		pData_ = new int[iCol * iRow];
		nCol_ = iCol;
		nRow_ = iRow;
	}
	else
	{
		throw "Index out of range";
	}
}

ptrdiff_t MatrixU::getColCount()
{
	return nCol_;
}

ptrdiff_t MatrixU::getRowCount()
{
	return nRow_;
}

ptrdiff_t MatrixU::At(ptrdiff_t iCol, ptrdiff_t iRow)
{
	if (iCol < 0 || iRow < 0 || iCol > nCol_ || iRow > nRow_)
	{
		throw "Index out of range";
	}
	else
	{
		return *(pData_ + nCol_ * iRow + iCol);
	}
}

void MatrixU::Set(ptrdiff_t iCol, ptrdiff_t iRow, ptrdiff_t item)
{
	if (iCol < 0 || iRow < 0 || iCol > nCol_ || iRow > nRow_)
	{
		throw "Index out of range";
	}
	else
	{
		*(pData_ + nCol_ * iRow + iCol) = item;
	}
}

void MatrixU::Set(ptrdiff_t item)
{

	for (ptrdiff_t i = 0; i < nCol_ * nRow_; ++i)
	{
		*(pData_ + i) = item;
	}
}


void MatrixU::SumMat(MatrixU& mat)
{
	if (nCol_ == mat.nCol_ && nRow_ == mat.nRow_)
	{
		for (ptrdiff_t i = 0; i < nCol_ * nRow_; ++i)
		{
			*(pData_ + i) = *(pData_ + i) + *(mat.pData_ + i);
		}
	}
	else
	{
		throw "This operation cannot be done.";
	}
}

void MatrixU::SubMat(MatrixU& mat)
{
	if (nCol_ == mat.nCol_ && nRow_ == mat.nRow_)
	{
		for (ptrdiff_t i = 0; i < nCol_ * nRow_; ++i)
		{
			*(pData_ + i) = *(pData_ + i) - *(mat.pData_ + i);
		}
	}
	else
	{
		throw "This operation cannot be done.";
	}
}

void MatrixU::MultInt(ptrdiff_t value)
{
	for (ptrdiff_t i = 0; i < nCol_ * nRow_; ++i) 
	{
		*(pData_ + i) *= value;
	}
}

void MatrixU::MultMat(MatrixU& mat)
{
	if (nCol_ != mat.nRow_)
	{
		throw "This operation cannot be done.";
	}
	else
	{
		MatrixU temp(nRow_, mat.nCol_);
		int cursum;
		for (ptrdiff_t i = 0; i < nRow_; ++i) // rows
		{
			for (ptrdiff_t j = 0; j < mat.nCol_; ++i) //col
			{
				cursum = 0;
				for (ptrdiff_t k = 0; k < nCol_; ++i)
				{
					cursum += At(i, k) * mat.At(k, j);
				}
				temp.Set(i, j, cursum);
			}
		}

		std::swap(temp.pData_, pData_);
		nCol_ = mat.nCol_;
	}
}
