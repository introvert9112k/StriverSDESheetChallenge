#include <bits/stdc++.h>
// Implement class for minStack.
class minStack
{
    int mini;
    stack<pair<int, int>> st;

public:
    // Constructor
    minStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (st.empty())
            mini = num;
        else
            mini = min(num, st.top().second);
        st.push({num, mini});
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
            return -1;
        int val = st.top().first;
        st.pop();
        return val;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
            return -1;
        int val = st.top().first;
        return val;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
            return -1;
        int val = st.top().second;
        return val;
    }
};