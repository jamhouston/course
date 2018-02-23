#ifndef MATRIX_U
#define  MATRIX_U

#include <iosfwd>
#include <iostream>
#include <string>

class MatrixU
{
public:
	explicit MatrixU() = default;
	~MatrixU();
	MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol);
	ptrdiff_t getRowCount();
	ptrdiff_t getColCount();

	ptrdiff_t At(ptrdiff_t iCol, ptrdiff_t iRow);
	void Set(ptrdiff_t iRow, ptrdiff_t iCol, ptrdiff_t item);
	void Set(ptrdiff_t item);
	void SumMat(MatrixU& mat);
	void MultInt(ptrdiff_t value);
	void MultMat(MatrixU& mat);
	void SubMat(MatrixU& mat);


private:
	int* pData_{ nullptr };
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
};


#endif
