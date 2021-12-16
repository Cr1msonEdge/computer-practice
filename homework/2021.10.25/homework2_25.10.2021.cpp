// homework2_25.10.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
int main()
{
    setlocale(LC_ALL, "rus");


    int x, tmp, n, m = 0;

    std::cout << "Введите число: ";
    std::cin >> x;
    std::cout << "Введите систему счисления: ";
    std::cin >> n;

    tmp = x;

    while (tmp) {
        ++m;
        tmp /= n;
    }

    m = m > 0 ? m - 1 : 0;

    tmp = 1;
    for (int i = 0; i < m; ++i) 
    {
        tmp *= n;
    }
    m = tmp;

    tmp = x;
    while (m) 
    {
        int digit = tmp / m;
        if (digit < 10)
        {
            std::cout << digit;
        }
        else
        {
            std::cout << char('A' + digit - 10);
        }
        tmp %= m;
        m /= n;
    }
}

