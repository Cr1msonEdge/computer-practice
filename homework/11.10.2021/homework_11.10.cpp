// homework_11.10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    void spacex(int space, int x);
    int n, m;
    std::cout << "Введите первое число: "<< std::endl;
    std::cin >> n;

    std::cout << "Введите второе число: " << std::endl;

    std::cin >> m;
    int spaces = n - 1;
    int stars = 1; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            spacex(spaces, stars);
        }
        std::cout << std::endl;
        if (spaces != 0)
        {
            spaces -= 1;
            stars += 2;
        }
        else
        {
            spaces += 1;
            stars -= 2;
        }
    }

    for (int q = 0; q < n - 1; q++)
    {
        for (int p = 0; p < m; p++)
        {
            spacex(spaces, stars);
        }
        std::cout << std::endl;
        spaces += 1;
        stars -= 2;
    }
}
void spacex(int space,int x)
{
    for (int i = 0; i < space; i++)
    {
        std::cout << " ";
    }
    for (int j = 0; j < x; j++)
    {
        std::cout << "*";
    }
    for (int i = 0; i < space; i++)
    {
        std::cout << " ";
    }
}
