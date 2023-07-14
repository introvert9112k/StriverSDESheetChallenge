#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    vector<int> arr;
    int rear = -1, n;
    Stack(int capacity)
    {
        // Write your code here.
        n = capacity;
        arr.resize(capacity);
    }

    void push(int num)
    {
        if (rear != n - 1)
        {
            ++rear;
            arr[rear] = num;
        }
    }

    int pop()
    {
        if (rear == -1)
            return -1;
        else
            return arr[rear--];
    }

    int top()
    {
        return rear == -1 ? -1 : arr[rear];
    }

    int isEmpty()
    {
        return rear == -1;
    }

    int isFull()
    {
        return rear == n - 1;
    }
}; 