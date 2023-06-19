/*
Intuition :
1.It is similar to merging to two sorted LinkedLists,but here there are more than two.
2.Take two linkedLists and merge them,merge the result with another linkedList,and so on
until all the LinkedLists are done.

TC : O(Sum of all the linked List Nodes)
SC : O(1)
*/
Node *flattenLinkedList(Node *head)
{
    /*Head2 points to the linkedList i.e to be merged with the resultant LinkedList
    so far*/
    Node *head1 = head, *head2 = head1->next;
    Node *dummyHead = new Node(-1), *previousNode;
    /*To delete the next pointer of each head*/
    Node *previousHead = head;
    /*Iterate until there are no linked List left*/
    while (head2)
    {
        /*Intially we merge LL1 and LL2,after the result will be pointing to dummyHead->child
        so intially merge LL1 and LL2,in later stages currNode1 points to resultant list
        i.e dummyHead->child*/
        Node *currNode1 = dummyHead->child ? dummyHead->child : head;
        Node *currNode2 = head2;
        /*Every time reset the previousNode,as we are merging new set of
        linkedLists now*/
        previousNode = dummyHead;
        while (currNode1 || currNode2)
        {
            if (currNode1 && currNode2)
            {
                if (currNode1->data <= currNode2->data)
                {
                    previousNode->child = currNode1;
                    currNode1 = currNode1->child;
                }
                else
                {
                    Node *nextNode = currNode2->child;
                    previousNode->child = currNode2;
                    currNode2->child = currNode1;
                    currNode2 = nextNode;
                }
                previousNode = previousNode->child;
            }
            else if (currNode1)
            {
                previousNode->child = currNode1;
                break;
            }
            else if (currNode2)
            {
                previousNode->child = currNode2;
                break;
            }
        }
        /*Removing the next pointer*/
        previousHead->next = nullptr;
        /*Updating the previous head to the current merged linkedList*/
        previousHead = head2;
        /*Updating the linkedList i.e to be merge with the resultant LinkedList*/
        head2 = head2->next;
    }
    /*Return the dummyHead->child,as it is the resultant LinkedList*/
    return dummyHead->child;
} 