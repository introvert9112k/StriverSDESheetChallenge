/*

    Time Complexity : O(L)
    Space Complexity : O(L / K)

    Where L is the number of nodes in the Linked-List.
    Where K is the minimum block size from the array B.

*/

Node *reverseKElements(Node *head, int n, int b[], int idx)
{
    // Base case: List is empty or entire block array have been considered.
    if (head == NULL || idx >= n)
    {
        return head;
    }

    // K will be the size of the current block.
    int K = b[idx];

    // Just move to the next block if size of the current block is zero.
    if (K == 0)
    {
        return reverseKElements(head, n, b, idx + 1);
    }

    Node *first = head, *second = nullptr, *third = nullptr;

    // Variable to keep track of the number of nodes reversed in the current block.
    int cnt = 0;

    // Reverse nodes until end of list is reached or current block has been reversed.
    while (first != nullptr && cnt < K)
    {
        third = second;
        second = first;
        first = first->next;
        second->next = third;
        ++cnt;
    }

    // Reverse the next block.
    head->next = reverseKElements(first, n, b, idx + 1);
    return second;
}
Node *recursive(Node *head, int n, int b[])
{
    // If linked list is empty, return head of the linked list.
    if (head == nullptr)
    {
        return nullptr;
    }

    // Calling reverseKElements function to modify the given linked list.
    head = reverseKElements(head, n, b, 0);

    // Return the head of the linked list.
    return head;
}
Node *iterative(Node *startNode, int n, int b[])
{
    /*Dummy Head next points to the head of the answer linkedList*/
    /*We need to four pointers to make necessary connections after reversal
    of the one set of nodes
    beforeHead --> points to the head of the before set of nodes before
    reversal.
    head --> points to current set of nodes that is to be reversed.
    tail --> Tail is the last node in the before set of nodes before reversal,
    or first node after reversal
    tailsNext -->Next node of tail Node*/
    Node *dummyHead = new Node(-1);
    /*Intially dummyHead acts as before Head node for the first set of nodes*/
    Node *beforeHead = dummyHead, *head = startNode;
    Node *tail = nullptr, *tailsNext = nullptr;

    int ind = 0;
    /*Iterate until the linkedList is finished or array is empty*/
    while (head && ind < n)
    {
        int k = b[ind];
        ind++;
        if (k == 0)
            continue;
        int cnt = 0;
        Node *first = head, *second = nullptr, *third = nullptr;
        /*Iterate until the linkedList is empty or the k nodes are reached*/
        while (first && cnt < k)
        {
            third = second;
            second = first;
            first = first->next;
            second->next = third;
            ++cnt;
        }
        /*Now second points to the tail node of the current set and
        first points to next of tail node,this acts head for the next set*/
        tail = second;
        tailsNext = first;
        /*Inserting the current reversed group in betwen the previous and
        next group*/
        beforeHead->next = tail;
        head->next = tailsNext;
        /*Current set head becomes beforeHead*/
        beforeHead = head;
        /*TailsNext become the head of next set*/
        head = tailsNext;
    }
    /*In case the original likedList is not reversed at all,then dummyHead->next
    points to nullptr,so return the head of linkedList at this case.*/
    return dummyHead->next ? dummyHead->next : startNode;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    return iterative(head, n, b);
}