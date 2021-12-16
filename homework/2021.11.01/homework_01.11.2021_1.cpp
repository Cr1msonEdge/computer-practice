// homework1_1.11.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int day, month, year;

    std::cout << "Поочередно введите день, месяц, год" << std::endl;
    do
    {
        std::cout << "Введите день: ";
        std::cin >> day;
    } while (day < 1 or day > 31);
    do
    {
        std::cout << "Введите месяц: ";
        std::cin >> month;
    } while (month < 1 or month > 31);
    std::cout << "Введите год: ";
    std::cin >> year;
    
    int d = (14 - month) / 12;
    int m = month + 12 * d - 2;
    int y = year - d + 1;// добавил единицу, поскольку считаем со следующего года, насколько я понял
    int mayday = 0;

    while (mayday != 5)
    {
        mayday = ((day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7);
        y += 1;
    }
    std::cout << y - 1 << std::endl;
}

