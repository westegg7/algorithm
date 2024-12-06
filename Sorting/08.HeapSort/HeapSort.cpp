#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>

using namespace std;

template<typename T>
class MaxHeap
{
private:
    vector<T> heap_;

public: 
    MaxHeap(int cap = 10)
    {
        heap_.reserve(cap + 1);
        heap_.push_back(0);
    }

    T Top()
    {
        return heap_[1];
    }

    bool IsEmpty()
    {
        return heap_.size() == 1;
    }

    void Push(const T& item)
    {
        cout << "Push " << item << endl;
        heap_.push_back(item);

        int current = heap_.size() - 1;

        // 부모 인덱스의 값과 비교
        while (current != 1 && item > heap_[current / 2])
        {
            heap_[current] = heap_[current / 2];
            current /= 2;
        }
        heap_[current] = item;
    }

    T Pop()
    {
        assert(!IsEmpty());

        T top = heap_[1];
        T last_item = heap_.back();
        heap_.pop_back();
        int size = heap_.size() - 1;

        int current = 1;
        int child = 2;
        while (child <= size)
        {
            child = heap_[child] > heap_[child + 1] ? child : child + 1;
            if (heap_[child] > last_item)
            {
                heap_[current] = heap_[child];
                current = child;
                child *= 2;
            } else break; 
        }
        heap_[current] = last_item;

        return top;
    }

    void Print()
	{
		cout << "Index: ";
		for (int i = 1; i <= heap_.size() - 1; i++)
			cout << setw(3) << i;
		cout << endl;

		cout << "Value: ";
		for (int i = 1; i <= heap_.size() - 1; i++)
			cout << setw(3) << heap_[i];
		cout << endl << endl;
	}
};


int main()
{
    MaxHeap<int> max_heap;

    max_heap.Push(10);
    max_heap.Push(4);
    max_heap.Push(3);
    max_heap.Push(5);
    max_heap.Push(8);
    max_heap.Push(12);
    max_heap.Print();

    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();

    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();

    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();

    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();

    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();

    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();
    
    cout << "Pop " << max_heap.Pop() << endl;
    max_heap.Print();
}