#include <iostream>

using namespace std;

void Print(int* arr, int n) 
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int* arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool early_return_flg = true;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                early_return_flg = false;
                Print(arr, n);
            }
        }
        count++;
        if (early_return_flg) break;
    }
    // outer loop count
    cout << count << endl;
}

int main()
{
    int arr[] = {1, 7, 8, 9, 11, 5, 21, 37, 84, 6};
    // int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // sorted arr
    int n = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;
    
    return 0;
}        