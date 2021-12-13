#include <iostream>
#include <vector>
#include <string>


template <typename T>

void reverse_array(T* arr,  int start,  int end) {
    --start;
    --end;
    int n = 0;
    for ( int i = start; i < start + ((end - start + 1)) / 2; ++i)
    {
        std::swap(arr[i], arr[end - n]);
        ++n;
    }
}
template <typename T>

void shiftArray(T A[], int n, int k)
{
    int shift;
    std::cout << "Enter the shift index: ";
    std::cin >> shift;
    if (shift < 0)
    {
        shift = -shift % n;
        shift = n - shift;

    }
    else
        shift %= n;
    if (shift)
    {   // 1 2 3 4 5 .пусть сдвиг на 2
        reverse_array(A, 1, shift); // 2 1 | 3 4 5
        reverse_array(A, shift + 1, n); // 2 1 | 5 4 3
        reverse_array(A, 1, n); // 3 4 5 1 2 
    }

}


int main() {
    int arr[5] = { 1,2,3,4,5 };
    int len;
    std::cout << "Enter the length of array" << std::endl;
    std::cin >> len;
    shiftArray(arr, len, 2);
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << ' ';
    }
}
