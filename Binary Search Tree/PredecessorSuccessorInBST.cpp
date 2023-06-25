#include <bits/stdc++.h>
/*
1.Keep track of the previous value in the inorder traversal.
2.If currnode is equal to key then previousvalue equal to the predecessor.
3.If previousValue equal to key then sucessor == root->data

We can even do the morris and iterative inorder traversal to find the predecessor
and successor.
TC : O(n)
sc : O(1)
*/
void findPredecessorSuccessor(BinaryTreeNode<int> *root, int key, int &previousValue,
                              int &predecessor, int &successor)
{
    if (root == nullptr)
        return;
    findPredecessorSuccessor(root->left, key, previousValue, predecessor, successor);
    if (root->data == key)
        predecessor = previousValue;
    else if (previousValue == key)
        successor = root->data;
    previousValue = root->data;
    findPredecessorSuccessor(root->right, key, previousValue, predecessor, successor);
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int previousValue = -1;
    int predecessor = -1, successor = -1;
    findPredecessorSuccessor(root, key, previousValue, predecessor, successor);
    return {predecessor, successor};
}
