#include "matrix.h"
#include <iostream>
#include <cmath>

void swapcol(double** arr, double n, int col1, int col2) { //нужно чтобы получить ненулевые элементы на главной диагонали
	for (int i = 0; i < n; ++i) {
		std::swap(arr[col1], arr[col2]);
	}
}

int digitcount(double x)
{
	x = int(x * 100);
	x /= 100;
	int count = 0;
	if (0 < abs(x) && abs(x) < 1) // -0.8
	{
		count += 2;
		while (double(x) != int(x))
		{
			x *= 10;
			++count;
		}
		if (x < 0)
			return ++count;
		return count;
	}
	
	if (double(x) != int(x)) // -2.7
	{
		++count;
		while (double(x) != int(x))
		{
			x *= 10;
		}
		
		while ((int)x != 0)
		{
			++count;
			x /= 10;
		}
		if (x < 0) return ++count;
		return count;
	}
	
}

int maxdigitcount(double** M, int n, int m)
{
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			max = (max > digitcount(M[i][j]) ? max : digitcount(M[i][j]));
		}
	}
	return max;
}

void printmatrix(double** M, int n, int m)
{
	int spaces = maxdigitcount(M, n, m);
	std::cout << spaces << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < (spaces - digitcount(M[i][j])); ++k)
			{
				std::cout << ' ';
			}
			
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
			M[i][j] = int(M[i][j] * 100);
			M[i][j] /= 100;
			//во избежании появления -0
		}
	}
	return M;
}