/*
 Intuition :
 1.Find the kth node from last and previous node of the kth node.
 2.Delete the link to the kthnode from previous node,and connect the tail node
 to the head of linkedlist

 TC : O(n + n)
 n -- finding the length of linkedList
 n -- For rotating the linkedlist
 SC : O(1)
 */
Node *rotate(Node *head, int k)
{

    int len = 0;
    for (Node *currNode = head; currNode; currNode = currNode->next, ++len)
        ;
    k = k % len;
    if (k == 0)
        return head;
    Node *previousNode = nullptr, *KthNode = nullptr;
    Node *currNode = head, *tailNode = nullptr;
    for (int i = 0; i < k; ++i)
        currNode = currNode->next;
    KthNode = head;
    while (currNode)
    {
        previousNode = KthNode;
        KthNode = KthNode->next;
        if (currNode->next == nullptr)
            tailNode = currNode;
        currNode = currNode->next;
    }
    previousNode->next = nullptr;
    tailNode->next = head;
    return KthNode;
} 