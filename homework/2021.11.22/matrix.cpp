#include "matrix.h"
#include <iostream>
#include <cmath>

void swapcol(double** arr, double n, int col1, int col2) { //нужно чтобы получить ненулевые элементы на главной диагонали
	for (int i = 0; i < n; ++i) {
		std::swap(arr[col1], arr[col2]);
	}
}


void printmatrix(double** M, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << M[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

double determinant(double** arr, int n) {
	int detsign = 1; // в случае перестановки стобцов меняет знак определителя
	double** M = matrixcopy(arr, n, n);
	double a;
	int coltoswap = 0; // запоминает столбец, который нужно свапнуть
	bool check;

	for (int i = 0; i < n - 1; ++i) {

		if (M[i][i] == 0) {//проверям, нулевой ли элемент на главной диагонали
			check = true;
			for (int j = i + 1; j < n; ++j) {
				if (M[i][j] != 0) {
					check = false;
					coltoswap = j;
					break;
				}
			}
			if (check) { // если не нашлось, то опред равен 0
				deletematrix(M, n);
				return 0;
			}
			swapcol(M, n, i, coltoswap);
			detsign *= -1;
		}

		for (int p = i + 1; p < n; ++p) {
			a = M[p][i] / M[i][i]; // коэф, с которым нужно вычитать
			for (int r = i; r < n; ++r) {// начинаем с i, поскольку слева уже нули
				M[p][r] -= a * M[i][r];
			}
		}
	}

	double result = 1;
	for (int i = 0; i < n; ++i) {
		result *= M[i][i];
	}

	deletematrix(M, n);
	return (result * detsign);
}

double** inversematrix(double** arr, int n)
{
	double** M = creatematrix<double>(n, n);
	double det = determinant(arr, n);
	if (det == 0)
	{
		throw "Нет обратной матрицы";
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			double** D = minormatrix(arr, n, j, i); // j i, потому что нужна транспонированная
			M[i][j] = double(determinant(D, n - 1)) / det;
			deletematrix(D, n - 1);
			if ((i + j) % 2)// сумма индексов столбцов и строк
			{
				M[i][j] *= -1;
			}
			if (M[i][j] == 0)
			{
				M[i][j] = 0;
			}
			//во избежании появления -0
		}
	}
	return M;
}
