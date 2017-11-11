#ifndef MatrixU_H
#define MATRIXU_H 

#include <iosfwd>

class MatrixU
{
public:
	MatrixU() = default;
	~MatrixU();
	MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol);
	int& At(ptrdiff_t iRow, ptrdiff_t iCol);
	const int& At(ptrdiff_t iRow, ptrdiff_t iCol) const;
	void Resize(Matrix& mat, const ptrdiff_t nRow, ptrdiff_t nCol);

private:
	ptrdiff_t nRow_ { 0 };
	ptrdiff_t nCol_ { 0 };
	*pdata_ = { nullptr };


}


#endif
