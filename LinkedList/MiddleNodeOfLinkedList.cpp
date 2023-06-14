Node *findMiddle(Node *head) {
    // Write your code here
    Node* slow = head,*fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
