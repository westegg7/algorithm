#include <iostream>

using namespace std;

void Merge(int* arr, int n, int mid)
{
    int* temp = new int[n];
    int i = 0, j = mid, k = 0;
    while (i < mid && j < n)
    {
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }   
    while (i < mid) 
        temp[k++] = arr[i++];
    while (j < n) 
        temp[k++] = arr[j++];
    for (int i = 0; i < n; i++) 
        arr[i] = temp[i];
    delete[] temp;
}

void MergeSort(int* arr, int n)
{
    if (n <= 1) return;
    int mid = n / 2;
    MergeSort(arr, mid);
    MergeSort(arr + mid, n - mid);
    Merge(arr, n, mid);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 21, 37, 84, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}   