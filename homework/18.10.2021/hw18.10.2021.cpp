// hw18.10.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

unsigned long long pow(int x, int n);
bool compare(double a, double b, int n);

int main()
{
	setlocale(LC_ALL, "rus");
	int delta;
	int r;
	unsigned long long N = 0, hits = 0, x, y;
	double a = 4.0, b; // b предыдущее число, с которым сравниваем
	std::cout << "Задайте точность вычисления: " << std::endl;
	std::cin >> delta;
	std::cout << "Введите радиус круга" << std::endl;
	std::cin >> r;
	do
	{
		b = a;
		++N;
		if (N % 2 == 0)
		{
			a += 4.0 / (2.0 * double(N) + 1.0);
		}
		else
		{
			a -= 4.0 / (2.0 * double(N) + 1.0);
		}
	} while (compare(a,b,delta));
	++N;
	std::cout << "Pi = " << std::setprecision(delta + 1) << a << std::endl;
	std::cout << "N = " << N << std::endl;
	for (unsigned long long i = 0; i < N; ++i)
	{
		x = rand() % (r + 1);
		y = rand() % (r + 1);
		if (x * x + y * y <= r*r)
		{
			++hits;
		}
	}
	std::cout << "Pi = " << std::setprecision(delta + 1) << 4.0 * double(hits) / double(N) << std::endl;
	return 0;
}

unsigned long long pow(int x, int n)
{
	unsigned long long number = 1;
	for (int i = 0; i < n; i++)
	{
		number *= x;
	}
	return number;
}

bool compare(double a, double b, int n)
{
	if (unsigned long long(a * pow(10, n)) == unsigned long long(b * pow(10, n)) )
	{
		return false;
	}
	else
	{
		return true;
	}
}
