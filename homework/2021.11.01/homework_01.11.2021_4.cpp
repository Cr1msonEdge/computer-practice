// homework_01.11.2021_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


std::string tens(long long n)
{
    std::string x;
	switch (n)
	{
	case 10:
		x = "десять ";
		break;
	case 11:
		x = "одиннадцать ";
		break;
	case 12:
		x = "двенадцать ";
		break;
	case 13:
		x = "тринадцать ";
		break;
	case 14:
		x = "четырнадцать ";
		break;
	case 15:
		x = "пятнадцать ";
		break;
	case 16:
		x = "шестнадцать ";
		break;
	case 17:
		x = "семнадцать ";
		break;
	case 18:
		x = "восемнадцать ";
		break;
	case 19:
		x = "девятнадцать ";
		break;
	}
	return x;
}
std::string onenumbm(long long n)
{
	std::string x;
	switch (n)
	{
	case 1:
		x = "один ";
		break;

	case 2:
		x = "два ";
		break;
	case 3:
		x = "три ";
		break;
	case 4:
		x = "четыре ";
		break;
	case 5:
		x = "пять ";
		break;
	case 6:
		x = "шесть ";
		break;
	case 7:
		x = "семь ";
		break;
	case 8:
		x = "восемь ";
		break;
	
	case 9:
		x = "девять ";
		break;
	}
	return x;
}
std::string onenumbf(long long n)
{
	std::string x;
	switch (n)
	{
	case 1:
		x = "одна ";
		break;

	case 2:
		x = "две ";
		break;
	case 3:
		x = "три ";
		break;
	case 4:
		x = "четыре ";
		break;
	case 5:
		x = "пять ";
		break;
	case 6:
		x = "шесть ";
		break;
	case 7:
		x = "семь ";
		break;
	case 8:
		x = "восемь ";
		break;

	case 9:
		x = "девять ";
		break;
	}
	return x;
}
std::string doublenumb(long long n)
{
	std::string x;
	switch (n)
	{
	case 1:
		x = "десять ";
		break;
	case 2:
		x = "двадцать ";
		break;
	case 3:
		x = "тридцать ";
		break;
	case 4:
		x = "сорок ";
		break;
	case 5:
		x = "пятьдесят ";
		break;
	case 6:
		x = "шестьдесят ";
		break;
	case 7:
		x = "семьдесят ";
		break;
	case 8:
		x = "восемьдесят ";
		break;

	case 9:
		x = "девяносто ";
		break;
	}
	return x;
}
std::string triplenumb(long long n)
{
	std::string x;
	switch (n)
	{
	case 1:
		x = "сто ";
		break;
	case 2:
		x = "двести ";
		break;
	case 3:
		x = "триста ";
		break;
	case 4:
		x = "четыреста ";
		break;
	case 5:
		x =  "пятьсот ";
		break;
	case 6:
		x = "шестьсот ";
		break;
	case 7:
		x = "семьсот ";
		break;
	case 8:
		x = "восемьсот ";
		break;

	case 9:
		x = "девятьсот ";
		break;
	}
	return x;
}
int main()
{
	setlocale(LC_ALL, "rus");
	long long n;
	std::string number = "";
	do
	{
		std::cout << "Введите положительное число, не превышающее одного миллиарда: ";
		std::cin >> n;
	} while (n < 1 || n > 1000000000);

	if (n == 1000000000)
	{
		std::cout << "Один миллиард" << std::endl;
		return 0;
	}
	

	long long forsize = n;
	int lg = 0;
	while (forsize != 0)
	{
		lg += 1;
		forsize /= 10;
	}
	switch (lg)
	{
	case 9:
	{
		int tmp = n / 100000000 % 10;
		number += triplenumb(tmp);
	}
	case 8:
	{
		int tmp = (n / 1000 / 1000 % 100);
		if (tmp >= 10 && tmp <= 19)
		{
			number += tens(tmp);
		}
		else
		{
			tmp = (n / 10 / 1000 / 1000) % 10;
			number += doublenumb(tmp);
			tmp = n / 1000 / 1000% 10;
			number += onenumbm(tmp);
		}
	}
	case 7:
	{
		int tmp = n / 1000 / 1000 % 100;
		if (tmp == 1)
		{
			number += "миллион ";
		}
		else if (tmp <= 4)
		{
			number += "миллиона ";
		}
		else
		{
			number += "миллионов ";
		}
	}
	case 6:
	{
		int tmp = n / 100000 % 10;
		number += triplenumb(tmp);
	}
	case 5:
	{
		int tmp = (n /1000 % 100);
		if (tmp >= 10 && tmp <= 19)
		{
			number += tens(tmp);
		}
		else
		{
			tmp = (n / 10 / 1000) % 10;
			number += doublenumb(tmp);
			tmp = n / 1000 % 10;
			number += onenumbm(tmp);
		}
	}
	case 4:
	{
		
		int tmp = n / 1000 % 100;
		if (tmp == 1)
		{
			number += "тысяча ";
		}
		else if(tmp <= 4)
		{
			number += "тысячи ";
		}
		else
		{
			number += "тысяч ";
		}
	}
	case 3:
	{
		int tmp = n / 100 % 10;
		number += triplenumb(tmp);
	}
	case 2:
	{
		int tmp = (n % 100);
		if (tmp >= 10 && tmp <= 19)
		{
			number += tens(tmp);
		}
		else
		{
			tmp = (n / 10) % 10;
			number += doublenumb(tmp);
			tmp = n % 10;
			number += onenumbm(tmp);
		}
		break;
	}	
	case 1:
	{
		int tmp = n % 10;
		number += onenumbm(tmp);
		break;
	}
	}
	if (1000 <= n && n <= 9999) {
		int tmp = n / 1000;
		number = onenumbf(tmp) + number;
	}
	else if (1000000 <= n && n <= 9999999) {
		int tmp = n / 1000000;
		number = onenumbm(tmp) + number;
	}
	std::cout << number;
}
