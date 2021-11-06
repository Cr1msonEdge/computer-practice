// homework1_25.10.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
	int n, count = 0;
	do
	{
		std::cout << "Введите натуральное число ";
		std::cin >> n;
	} while (n < 1);

	int max = n;
	while (n != 1) 
	{
		if (n % 2 == 0) 
		{
			n /= 2;
		}
		else 
		{
			n *= 3;
			n += 1;
		}
		if (n > max) 
		{ 
		max = n;
		}
		++count;
	}
	std::cout << "Число шагов равно: " << count << std::endl;
	std::cout << "Наибольшее значение равно: " << max << std::endl;
}
