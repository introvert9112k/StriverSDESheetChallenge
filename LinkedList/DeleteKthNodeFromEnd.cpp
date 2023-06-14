Node *removeKthNode(Node *head, int K)
{
    Node *currNode = head, *KthNode = head;
    for (int i = 0; i < K; ++i)
        currNode = currNode->next;
    Node *previousNode = nullptr;
    while (currNode)
    {
        previousNode = KthNode;
        KthNode = KthNode->next;
        currNode = currNode->next;
    }
    if (previousNode)
    {
        previousNode->next = KthNode->next;
        KthNode->next = nullptr;
        delete KthNode;
    }
    /*If previous Node is null,that mean we should delete the first Node*/
    else
    {
        Node *deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
    }
    return head;
}
