#include "MatrixMulti.h"
#include <iostream>
using namespace std;

MatrixMulti::MatrixMulti(int *pArray1, int nRow, int nCol1, int *pArray2, int nCol2, int *pResult)
{
	for (int i = 0; i < nRow; i++)
	{
		for (int z = 0; z < nCol2; z++)
		{
			int t = 0;
			for (int j = 0; j < nCol1; j++)
			{
				t = t + (pArray1[i*nCol1 + j])*(pArray2[j*nCol2 + z]);
			}
			pResult[i*nCol2 + z] = t;
			cout << pResult[i*nCol2 + z] << " ";
		}
		cout << endl;
	}
}


MatrixMulti::~MatrixMulti()
{
}
