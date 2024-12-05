#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& arr, int low, int high) 
{
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    // int pivot = arr[size_t(floorf((high - low) / 2.0f)) + low];
    int i = low, j = high;

    while (true)
    {
        while (arr[i] < pivot) 
            i++;
        while (arr[j] > pivot) 
            j--;
        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }

}

void QuickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int p = Partition(arr, low, high);
        QuickSort(arr, low, p);
        QuickSort(arr, p + 1, high);
    }
}

void PrintArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5, 21, 37, 84, 6};
    int n = arr.size();
    QuickSort(arr, 0, n - 1);
    PrintArray(arr);
    
    return 0;
}