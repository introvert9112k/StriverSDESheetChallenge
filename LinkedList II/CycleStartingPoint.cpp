/*
usingHashMap
1.use a hashMap to keep track of visited nodes so far,the node which is
first visited twice is the cycle start Node
Refer the isCycleExists question for code.
*/
/*
Intuition :
1.Using the fast and slow pointers check whether the cycle exists.
2.Then reset the fast pointer to head and move the slow and fast pointers
one step at a time.
3.The point where they meet is the start of the cycle

TC : O(N) near about O(n)
SC : O(1)
*/
Node *firstNode(Node *head)
{
    Node *slow = head, *fast = head;
    bool isCycleExists = false;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            isCycleExists = true;
            break;
        }
    }
    if (isCycleExists)
    {
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    else
        return nullptr;
} 