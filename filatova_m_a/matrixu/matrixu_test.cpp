#include "matrixu.h"
#include <iostream>


int main()
{
	using namespace std;
	int row = 3;
	int col = 3;
	MatrixU mat = MatrixU(row, col);
	mat.Set(0);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << mat.At(i, j);
		}
		cout << endl;
	}
}
