/*
Intution :
1.Construct a new LinkedList and store the old node and its corresponding node
in the map.
2.Using the Map assign the random pointers now

TC : O(n + n)
n -- For creating a new LinkedList
n -- For assiging the random Pointers.
SC : O(n)
Space for the Map.
*/
LinkedListNode<int> *approach1(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> nodesMap;
    LinkedListNode<int> *currNode = head;
    LinkedListNode<int> *dummyHead = new LinkedListNode<int>(-1);
    LinkedListNode<int> *previousNode = dummyHead;
    while (currNode)
    {
        LinkedListNode<int> *newListNode = new LinkedListNode<int>(currNode->data);
        previousNode->next = newListNode;
        nodesMap[currNode] = newListNode;
        previousNode = previousNode->next;
        currNode = currNode->next;
    }
    currNode = head;
    while (currNode)
    {
        LinkedListNode<int> *randomNode = currNode->random;
        nodesMap[currNode]->random = randomNode ? nodesMap[randomNode] : nullptr;
        currNode = currNode->next;
    }
    return dummyHead->next;
}
LinkedListNode<int> *approach2(LinkedListNode<int> *head)
{
    LinkedListNode<int> *currNode = head;
    /*Inserting new nodes in between the original nodes*/
    while (currNode)
    {
        LinkedListNode<int> *newListNode = new LinkedListNode<int>(currNode->data);
        newListNode->next = currNode->next;
        currNode->next = newListNode;
        currNode = currNode->next->next;
    }
    currNode = head;
    /*Assigining the random Pointers*/
    while (currNode)
    {
        if (currNode->random)
            currNode->next->random = currNode->random->next;
        else
            currNode->next->random = nullptr;
        currNode = currNode->next->next;
    }
    /*Seperating the two linkedLists*/
    LinkedListNode<int> *oldListNode = head, *newListNode = head->next;
    LinkedListNode<int> *ans = head->next;
    while (oldListNode)
    {
        oldListNode->next = oldListNode->next->next;
        if (newListNode->next)
            newListNode->next = newListNode->next->next;
        else
            newListNode->next = nullptr;
        oldListNode = oldListNode->next;
        newListNode = newListNode->next;
    }
    return ans;
}
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (head == nullptr)
        return nullptr;
    return approach2(head);
}
