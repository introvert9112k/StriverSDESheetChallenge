#include <bits/stdc++.h>
bool searchInBST1(BinaryTreeNode<int> *root, int x)
{
    if (root == nullptr)
        return false;
    if (root->data == x)
        return true;
    return (root->data < x) ? searchInBST1(root->right, x) : searchInBST1(root->left, x);
}
bool iterative(BinaryTreeNode<int> *root, int x)
{
    BinaryTreeNode<int> *currNode = root;
    while (currNode)
    {
        if (currNode->data == x)
            return true;
        currNode = currNode->data < x ? currNode->right : currNode->left;
    }
}
bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    //    return searchInBST1(root, x);
    return iterative(root, x);
} 