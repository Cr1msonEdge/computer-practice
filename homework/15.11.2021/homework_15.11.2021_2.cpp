// homework_15.11.2021_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void shiftArray(int* M, int n, int k)
{
    int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
        A[i] = M[(k + i) % n];
    }
    for (int i = 0; i < n; ++i)
    {
        M[i] = A[i];
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int n = 0;
    do
    {
        std::cout << "Введите размер массива - ";
        std::cin >> n;
    } while (n < 0);

    int* M = new int[n];

    std::cout << "Поочерёдно введите элементы массива: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> M[i];
    }

    int k = 0;
    
    std::cout << "Введите размер сдвига - ";
    std::cin >> k;

    shiftArray(M, n, k);
    for (int i = 0; i < n; ++i)
    {
        std::cout << M[i] << ' ';
    }

}

