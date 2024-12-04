#include <iostream>

using namespace std;

void MySwapPtr(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MySwapRef(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void MySwapArithmetic(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void MySwapXor(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() 
{
    int a = 1;
    int b = 5;

    cout << a << " " << b << endl;
    MySwapPtr(&a, &b);
    cout << a << " " << b << endl;
    MySwapRef(a, b);
    cout << a << " " << b << endl;  
    MySwapArithmetic(a, b);
    cout << a << " " << b << endl;  
    MySwapXor(a, b);
    cout << a << " " << b << endl;  

    return 0;
}