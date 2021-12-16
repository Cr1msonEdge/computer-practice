// homework2_01.11.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    //setlocale(LC_ALL, "rus");
    int a, m, y, mayday;
    int k = 0;
    for (int iyear = 1901; iyear < 2001; ++iyear)
    {


        for (int jday = 1; jday < 13; ++jday)
        {
            a = (14 - jday) / 12;
            m = jday + (12 * a) - 2;
            y = iyear - a;
            mayday = (13 + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
            if (mayday == 5)
            {
                ++k;
            }

        }



    }
    std::cout << "Количество пятниц тринадцатых: " << k << std::endl;
    std::cout << "Вероятность равна: "<< (double)k/(100*12) << std::endl;
}
