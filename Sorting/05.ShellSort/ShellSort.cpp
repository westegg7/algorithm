#include <iostream>

using namespace std;

void InsertionSort(int* arr, int n, int gap) 
{
    for (int i = gap; i < n; i++)
    {
        int key = arr[i];
        int j = i;
        while (j >= gap && arr[j - gap] > key)
        {
            arr[j] = arr[j - gap];
            j -= gap;
        }
        arr[j] = key;
    }
}

void ShellSort(int* arr, int n)
{
    int gap = n / 2;
    while (gap >= 1)
    {
        InsertionSort(arr, n, gap);
        gap /= 2;
    }
}   

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 21, 37, 84, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, n);  
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}   