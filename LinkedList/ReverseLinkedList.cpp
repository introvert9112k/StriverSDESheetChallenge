
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   LinkedListNode<int>* first = head,*second = nullptr,*third = nullptr;
   while(first)
   {
       third = second;
       second = first;
       first = first->next;
       second->next = third;
   }
   return second;
} 