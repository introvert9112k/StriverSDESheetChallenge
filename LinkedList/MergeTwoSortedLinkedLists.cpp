void connectNode(Node<int> *&prevNode, Node<int> *&ListNode)
{
    Node<int> *currNode = ListNode;
    ListNode = ListNode->next;
    prevNode->next = currNode;
    currNode->next = nullptr;
    prevNode = currNode;
}
/*Intution :
1. In this approach we are taking out the smallest node from the linkedList
and attaching it to the new linkedlist.

TC : O(m + n)
SC : O(1)*/
Node<int> *approach1(Node<int> *first, Node<int> *second)
{
    Node<int> *newHead = new Node<int>(-1);
    Node<int> *prevNode = newHead;
    while (first && second)
    {
        if (first->data <= second->data)
            connectNode(prevNode, first);
        else
            connectNode(prevNode, second);
    }
    if (first)
        prevNode->next = first;
    else
        prevNode->next = second;
    return newHead->next;
}
/*
Intuition :
1. In this approach we are merging the two linkedlists into first linkedlist

TC : O(m + n)
SC : O(1)
*/
Node<int> *approach2(Node<int> *first, Node<int> *second)
{
    Node<int> *dummyHead = new Node<int>(-1), *previous = dummyHead;
    /*Intially dummyHead->next points to the head of first linkedlist*/
    dummyHead->next = first;
    while (first && second)
    {
        if (first->data <= second->data)
        {
            previous = first;
            first = first->next;
        }
        else
        {
            Node<int> *nextNode = second->next;
            previous->next = second;
            second->next = first;
            previous = second;
            second = nextNode;
        }
    }
    if (second)
        previous->next = second;
    return dummyHead->next;
}
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    return approach2(first, second);
} 