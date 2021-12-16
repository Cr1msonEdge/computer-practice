// codewarsPLEASEDUDE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "matrix.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	/*std::cout << digitcount(-0.08);
	std::cout << digitcount(-3.7);
	std::cout << digitcount(0.3) << std::endl;
	system("pause");*/
	do
	{
		std::cout << "Введите размерность квадратной матрицы ";
		std::cin >> n;
	} while (n < 1);
	double** M = inputmatrix<double>(n, n);
	std::cout << "Определитель = " << determinant(M, n) << std::endl;
	try//если определитель равен нулю, то поймаем ошибку
	{ 
		double** A = inversematrix(M, n);
		std::cout << "Обратная матрица: " << std::endl;
		printmatrix(A, n, n);
		deletematrix(A, n);
	}
	catch (const char str[])
	{
		std::cout << str << std::endl;
	}
	catch (...)
	{
		std::cout << "Неизвестная ошибка" << std::endl;
	}
	deletematrix(M, n);
}
