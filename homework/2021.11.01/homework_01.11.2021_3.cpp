// homework3_01.11.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Hello World!\n";


    int N;

    do
    {
        std::cout << "Введите номер комнаты от 1 до 2 000 000 000: ";
        std::cin >> N;
    } while ( N < 1 or N > 2000000000);


    int roommax =  1, block = 1, floormax = 1;
    while (roommax < N)
    {
        block += 1;
        roommax += block * block;
        floormax += block;
    }
    if (roommax == N)
    {
        std::cout << "Вам на " << floormax << " этаж" << std::endl;
        return 0;
    }
    
    roommax -= block * block;
    roommax += 1;// комната на этаже с необходимым количеством комнат
    floormax -= block;
    floormax += 1;// первый этаж с необходимым количество комнат
    // в block записано количество комнат на этаже
    if (roommax == N)
    {
        std::cout << "Вам на " << floormax << " этаж" << std::endl;
        return 0;
    }
    int k = 0;

    int tmproom = roommax;
    int tmpfloor = floormax;
    while (roommax != N)
    {
        k += 1;
        roommax = tmproom + k;
        floormax = tmpfloor + (int)k / block;
    }
    std::cout << "Вам на " << floormax << " этаж"<<std::endl;

 
}
