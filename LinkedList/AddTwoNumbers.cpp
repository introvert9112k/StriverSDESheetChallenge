Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *head1 = num1, *head2 = num2;
    int carry = 0;
    Node *newHead = new Node(-1);
    Node *previousNode = newHead;
    while (head1 && head2)
    {
        int sum = (head1->data + head2->data) + carry;
        int nodeValue = sum % 10;
        carry = (sum >= 10) ? 1 : 0;
        previousNode->next = new Node(nodeValue);
        previousNode = previousNode->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1)
    {
        int sum = (head1->data) + carry;
        int nodeValue = sum % 10;
        carry = (sum >= 10) ? 1 : 0;
        previousNode->next = new Node(nodeValue);
        previousNode = previousNode->next;
        head1 = head1->next;
    }
    while (head2)
    {
        int sum = (head2->data) + carry;
        int nodeValue = sum % 10;
        carry = (sum >= 10) ? 1 : 0;
        previousNode->next = new Node(nodeValue);
        previousNode = previousNode->next;
        head2 = head2->next;
    }
    /*If still carry exists create a new node with value 1*/
    if (carry)
        previousNode->next = new Node(1);
    return newHead->next;
}
