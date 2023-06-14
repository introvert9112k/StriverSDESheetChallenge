void connectNode(Node<int> *&prevNode, Node<int> *&ListNode)
{
    Node<int> *currNode = ListNode;
    ListNode = ListNode->next;
    prevNode->next = currNode;
    currNode->next = nullptr;
    prevNode = currNode;
}
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
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