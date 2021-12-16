#pragma once
#include <iostream>

void swapcol(double** arr, double n, int col1, int col2);
double determinant(double** arr, int n);
double** inversematrix(double** arr, int n);
int digitcount(double x);
int maxdigitcount(double** M, int n, int m);
void printmatrix(double** M, int n, int m);

template <typename T>
T** creatematrix(int n, int m)
{
	T** M = new T * [n];
	for (int i = 0; i < n; ++i)
	{
		M[i] = new T[m];
	}
	return M;
}

template <typename T>
T** inputmatrix(int n, int m)
{
	T** M = creatematrix<T>(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << '(' << i + 1 << ", " << j + 1 << "): ";
			std::cin >> M[i][j];
		}
	}
	return M;
}



template <typename T>
void deletematrix(T** M, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] M[i];
	}
	delete[] M;
}

/////////

template <typename T>
double** matrixcopy(T** M, int n, int m) // копируем матрицу, для удобства
{
	double** A = creatematrix<double>(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = double(M[i][j]);
		}
	}
	return A;
}

template <typename T>
T** minormatrix(T** arr, int n, int row, int col)
{
	T** A = creatematrix<T>(n - 1, n - 1);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			A[i][j] = arr[i][j];
		}
		for (int j = col + 1; j < n; ++j)
		{
			A[i][j - 1] = arr[i][j];
		}
	}
	for (int i = row + 1; i < n; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			A[i - 1][j] = arr[i][j];
		}
		for (int j = col + 1; j < n; ++j)
		{
			A[i - 1][j - 1] = arr[i][j];
		}
	}
	return A;
}