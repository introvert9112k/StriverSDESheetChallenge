/*
Intuition :
1.Given only the node to be deleted,inorder to delete the currNode 
we should know the previous node, in any case we cannot find the preivous 
node by knowing the currNode.
2.Given that node to be deleted is not the last Node,so we can overwrite the
values.
3.That is shift the values one step left,so that the value at the currNode changes.
that is it is deleted.
4.But there is extra node in the linkedList,i.e last Node.
5.Delete the LastNode of linkedList to get answer.

TC : O(N)
SC : O(1) 
*/
void approach1(LinkedListNode<int> * node)
{
    LinkedListNode<int> *currNode = node,*previousNode = nullptr;
    while(currNode->next)
    {
        currNode->data = currNode->next->data;
        previousNode = currNode;
        currNode = currNode->next;
    }
    previousNode->next = nullptr;
    delete currNode;
}
/*
Intuition :
1.In this we are simply copying the value of next node to that of node to 
be deleted in the deleted node,making deleted node next points to next of next
node.
2.In this we can solve the problem in O(1) TC
TC : O(1)
SC : O(1)
*/
void approach2(LinkedListNode<int> * node)
{
    node->data = node->next->data;
    node->next = node->next->next;
}
void deleteNode(LinkedListNode<int> * node) {
    approach2(node);
}  