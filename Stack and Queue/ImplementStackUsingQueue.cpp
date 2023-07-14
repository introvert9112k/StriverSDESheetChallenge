class Stack
{
    // Define the data members.
    queue<int> q1, q2;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q1.size();
    }

    bool isEmpty()
    {
        return q1.empty();
    }

    void push(int element)
    {
        q2.push(element);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        return q1.empty() ? -1 : q1.front();
    }
}; 