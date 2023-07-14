class Queue
{
    // Define the data members(if any) here.
    stack<int> s1, s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        int val = -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return -1;
        else
        {
            val = s2.top();
            s2.pop();
        }
        return val;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.empty() ? -1 : s2.top();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return s1.empty() && s2.empty();
    }
}; 