#include <bits/stdc++.h>

/*
Intuition :
1.collect all the nodes in level in a queue.
2.Assign the next pointer between two consecutive nodes using the nodes in the
queue.
3.We can use the extra vector to store the nodes in the level,iterater over the
vector and connect the consecutive nodes. or else we can pop each node from the
queue connect its next to the queue's front and again push the node into  queue.

TC : o(2n)
n -- for travesing the binary tree
n -- for conneccting the next pointers.
SC : O(n)
space for the queue.
*/
void appraoch1(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    for (int level = 0; !q.empty(); ++level)
    {
        for (int i = q.size(); i > 0; --i)
        {
            auto currNode = q.front();
            q.pop();
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
        int size = q.size();
        for (int i = 0; i < size - 1; ++i)
        {
            auto currNode = q.front();
            q.pop();
            currNode->next = q.front();
            q.push(currNode);
        }
        /*there would be one node left in queue i.e last node so remove it and
        push back to queue*/
        auto currNode = q.front();
        q.pop();
        q.push(currNode);
    }
}
/*
Intuition :
1.Maintain a previousNode which points to the previous node in current level
and keep on connecting the next node in current level with previous node and updating
previous node to current node

TC : O(n)
Sc : O(1)
*/
void approach2(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    for (int level = 0; !q.empty(); ++level)
    {
        BinaryTreeNode<int> *prevNode = nullptr;
        for (int i = q.size(); i > 0; --i)
        {
            auto currNode = q.front();
            q.pop();
            if (currNode->left)
            {
                if (prevNode != nullptr)
                    prevNode->next = currNode->left;
                prevNode = currNode->left;
                q.push(currNode->left);
            }
            if (currNode->right)
            {
                if (prevNode != nullptr)
                    prevNode->next = currNode->right;
                prevNode = currNode->right;
                q.push(currNode->right);
            }
        }
    }
}
void connectNodes(BinaryTreeNode<int> *root)
{
    approach2(root);
} 