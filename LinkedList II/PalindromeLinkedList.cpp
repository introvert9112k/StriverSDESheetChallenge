/*
Intuition :
1.Find the middle Node of the LinkedList.
2.Reverse the second half of the linkedList and check with the firstHalf.

TC : O(n/2 + n/2 + n/2)
n/2 for finding the middle Node
n/2 for reversing the LL
n/2 for checking the palindrome property
SC : O(1)
*/
LinkedListNode<int> *findMiddleNode(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *first = head, *second = nullptr, *third = nullptr;
    while (first)
    {
        third = second;
        second = first;
        first = first->next;
        second->next = third;
    }
    return second;
}
bool isPalindrome(LinkedListNode<int> *head)
{
    LinkedListNode<int> *middleNode = findMiddleNode(head);
    LinkedListNode<int> *reverseHead = reverseLinkedList(middleNode);
    LinkedListNode<int> *frontHead = head;
    while (reverseHead)
    {
        if (frontHead->data != reverseHead->data)
            return false;
        frontHead = frontHead->next;
        reverseHead = reverseHead->next;
    }
    return true;
} 