#include <bits/stdc++.h>
/*
TC : O(N)
SC : O(N)
*/
bool usingHashMap(Node *head)
{
    unordered_map<Node *, bool> hashMap;
    while (head)
    {
        if (hashMap[head])
            return true;
        hashMap[head] = true;
        head = head->next;
    }
    return false;
}
/*
TC : O(N)
SC : O(1)
*/
bool usingFastAndSlowPointers(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
bool detectCycle(Node *head)
{
    // return usingHashMap(head);
    return usingFastAndSlowPointers(head);
} 