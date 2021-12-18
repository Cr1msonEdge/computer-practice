// HevViewer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>


int to_hex(int ch)
{
    int symb = 0;
    if (ch >= 10)
    {
        symb = 'A' + ch - 10;
    }
    else
        symb = '0' + ch;
    return symb;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    /*std::cout << to_hex(24);
    system("pause");*/
    char ifname[256];
    char ofname[256];
    char hex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    if (argc < 2)
    {
        std::cout << "Введите название файла для чтения: ";
        std::cin.getline(ifname,256);
    }
    else
    {
        strcpy_s(ifname, argv[1]);
    }
    if (argc < 3)
    {
        std::cout << "Введите название файла вывода: ";
        std::cin.getline(ofname, 256);
    }
    else
    {
        strcpy_s(ofname, argv[2]);
    }

    std::ifstream inFile (ifname, std::ios_base::binary);
    if (!inFile)
    {
        std::cout << "Не удалось открыть файл: " << ifname << std::endl;
        return 1;
    }
    std::ofstream outFile(ofname);

    if (!outFile)
    {
        std::cout << "Не удалось открыть файл: " << ofname << std::endl;
        inFile.close();
        return 2;
    }

    int ch;
    int counter = 0;
    int str[16];
    size_t strsize = 16;
    while (inFile.peek() != EOF)
    {
        int col = 16*counter;
        std::string col1 = "";
        while (col != 0)
        {
            int tmp = col % 16;
            col1.push_back(to_hex(tmp));
            col /= 16;
        }
        int k = col1.size();
        for (int i = 0; i < (10 - k); ++i)
        {
            col1.push_back('0');
        }
        std::cout << col1;
        for (int i = 0; i < (col1.size() / 2); ++i)
        {
            std::swap(col1[i], col1[col1.size() - i - 1]);
        }
        col1 += ": ";
        outFile << col1;
        // первый стобик ^
        for (size_t i = 0; i < 16; ++i)
        {
            if (inFile.peek() != EOF)
            {
                str[i] = inFile.get();
            }
            else
            { 
                strsize = i + 1 ;
                break;
            }
        }
        for ( int i = 0 ; i < strsize - 1; ++i)
        {
            if (i == 8)
            {
                outFile << "| ";
            }
            outFile.put(to_hex(str[i] / 16));
            outFile.put(to_hex(str[i] % 16));
            outFile.put(' ');
        }
        if (strsize != 16) // допроблелить последнюю строку
        {
            for (int i = 0; i < (16 - strsize); ++i)
            {
                if (i == (16 - strsize - 8) + 1 && strsize > 8)
                    outFile << ("|");
                else if (i == (16 - strsize - 8) + 1 && strsize <= 8)
                    outFile << ("| ");
                outFile << "  ";
                outFile << " ";
            }
        }
        if (strsize == 16)
            for (int i = 0; i < strsize; ++i)
            {
                if (str[i] >= 32)
                    outFile.put(char(str[i]));
                else
                    outFile.put('.');
            }
        else
            for (int i = 0; i < strsize - 1; ++i)
            {
                if (str[i] >= 32)
                    outFile.put(char(str[i]));
                else
                    outFile.put('.');
            }
        outFile.put('\n');
        ++counter;
    }
    inFile.close();
    outFile.close();

}
