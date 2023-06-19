#include <bits/stdc++.h>
/*
Intutition :
1.use hashMap to store the nodes in LinkedList1.
2.Iterate over the linkedList 2 and find out the node of linkedList 2 which
is in LL1 using hashMap.
TC : O(M + N)
let M be the no of nodes in LL1 and N in LL2.
We are iterating over the LL1 for hashing the nodes and LL2 for finding
out the intersection Point.
SC : O(M)
Space for storing the LL1 nodes.
*/
Node *usingHashMap(Node *head1, Node *head2)
{
    unordered_map<Node *, bool> nodesMap;
    while (head1)
    {
        nodesMap[head1] = true;
        head1 = head1->next;
    }
    while (head2)
    {
        if (nodesMap[head2])
            return head2;
        head2 = head2->next;
    }
    return nullptr;
}
/*
Intuition2 :
1.Find the length of LL1 and LL2.
2.Move the head of the longest LL by the differnce of lengths,so that the
both the LLs has same length now.
3.Now move the heads simulatenously and check for the common node.

TC : O(M + N + M)
M -- for length of LL1
N -- for length of LL2
M -- For finding the intersection point.(This includes movement also)
SC : O(1)
*/
Node *optimal1(Node *head1, Node *head2)
{
    /*finding the length of LL*/
    auto findLength = [](Node *currNode)
    {
        int len = 0;
        for (; currNode; currNode = currNode->next, ++len)
            ;
        return len;
    };
    int n = findLength(head1);
    int m = findLength(head2);
    /*Moving the head of Longer LL*/
    if (n > m)
    {
        for (int i = 0; i < (n - m); ++i)
            head1 = head1->next;
    }
    else
    {
        for (int i = 0; i < (m - n); ++i)
            head2 = head2->next;
    }
    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}
/*
1.Start the two dummy nodes from the head1 and head2.
2.When one of the dummy nodes reaches the end,the reintailze it with other
linkedList head.
3.The momenet when two dummy nodes becomes equal that is the intersection point

Explanation :
1.Suppose let d1,d2 are dummy nodes of two LLs.
2.let d1 reaches the end of LL1,then d2 at a distance of (m-n) from reaching
the end of LL2.Because LL2 is greater than LL1 by (m-n) nodes.
3.Now intialzing the d1 to start of the LL2,when d2 reaches the end d1
occurs a distance (m-n) in the LL2.
4.Now intialize d2 to start of LL1, so now d1 and d2 points the Nodes from
which the length of two linkedLists equal.
5.Now as discussed in previous approach start the two dummy nodes simulatenously
to find the intersection point.

NOTE : Read the article for Visual understanding

M - length of LL1
N - length of LL2.
M < N.
TC : O(M + (N-M) + M) = O(M + N)
M -- d1 reaches the end of LL1.
(N-M) -- d2 reaches the end of LL2.
M -- both moves simulatenously.
SC : O(1)

*/
Node *optimal2(Node *head1, Node *head2)
{
    Node *d1 = head1, *d2 = head2;
    while (d1 != d2)
    {
        /*d1 reaches end,set it to head2,else move front*/
        d1 = (d1 == nullptr) ? head2 : d1->next;
        /*d2 reaches end,set it to head1,else move front*/
        d2 = (d2 == nullptr) ? head1 : d2->next;
    }
    /*If there is no intersection,both d1 and d2 becomes equal when
    both are nullptr*/
    return d1;
}
Node *reverseLinkedList(Node *currNode)
{
    Node *first = currNode, *second = nullptr, *third = nullptr;
    while (first)
    {
        third = second;
        second = first;
        first = first->next;
        second->next = third;
    }
    return second;
}
Node *findCycleStart(Node *head)
{
    Node *slow = head, *fast = head;
    bool isCycleExists = false;
    while (fast && fast->next)
    {
        if (slow == fast)
        {
            isCycleExists = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (isCycleExists)
    {
        slow = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    else
        return nullptr;
}
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // return usingHashMap(firstHead, secondHead);

    // Node *reverseHead = reverseLinkedList(firstHead);
    // firstHead->next = secondHead;
    // return findCycleStart(reverseHead);

    // return optimal1(firstHead,secondHead);
    return optimal2(firstHead, secondHead);
}