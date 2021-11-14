// homework_15.11.2021_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*int countdigit(int);
int maxdigit(int**, int, int);
void printArray(int**, int, int);*/

int countdigit(int n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count += 1;
    }
    return count;
}

int maxdigit(int** M, int n, int m)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (M[i][j] > max)
            {
                max = M[i][j];
            }
        }
    }
    return max;
}

void printArray(int** M, int n, int m)
{
    int symbols = countdigit(maxdigit(M, n, m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << M[i][j] << ' ';
            int len = countdigit(M[i][j]);
            for (int k = 0; k < symbols - len; ++k)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}


void spiral(int** M, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            M[i][j] = 0;
        }
    } 


    int i = 0, j = 0, dir = 1;//dir - задаёт направление, вверх или вниз, влево или вправо идёт движение спирали
    bool isrow = true;
    for (int k = 1; k <= n * m; ++k)
    {
        M[i][j] = k;
        if (isrow)
        {
            if (j + dir > m - 1 or M[i][j + dir] != 0)
            {
                isrow = false;
                i += dir;
            }
            else
            {
                j += dir;
            }
        }
        else
        {
            if (i + dir > n - 1 or M[i + dir][j] != 0)
            {
                dir *= -1;
                isrow = true;
                j += dir;
            }
            else
            {
                i += dir;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int row, col;

    do
    {
        std::cout << "Введите количество строк: ";
        std::cin >> row;

        std::cout << "Введите количество столбцов: ";
        std::cin >> col;      
    } while (row < 1 or col < 1);


    int** M = new int* [row];

    for (int i = 0; i < row; ++i)
    {
        M[i] = new int[col];
    }

    spiral(M, row, col);
    printArray(M, row, col);

    for (int i = 0; i < col; ++i)
    {
        delete[] M[i];
    }
    delete[] M;
    
}

