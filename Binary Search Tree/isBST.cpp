#include <bits/stdc++.h>

/*
Intution :
1.We keep track of the range of the values the currNode can have,if currnode
value is out of the range then it is not BST.

TC : O(n)
SC : O(n)
*/
bool isBST(BinaryTreeNode<int> *root, int minValue, int maxValue)
{
    if (root == nullptr)
        return true;
    if (root->data > maxValue || root->data < minValue)
        return false;
    return isBST(root->left, minValue, root->data) &&
           isBST(root->right, root->data, maxValue);
}
/*
Intuiton :
We know that the inorder traversal of the BST gives the sorted output.
So keep track of the prevNode,if the prevNode->data > currNode->data then it is not BST

TC : O(n)
SC : O(n)
*/
bool isBST2(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&prevNode)
{
    if (root == nullptr)
        return true;
    if (!isBST2(root->left, prevNode))
        return false;
    if (prevNode && prevNode->data > root->data)
        return false;
    prevNode = root;
    if (!isBST2(root->right, prevNode))
        return false;
    return true;
}
bool validateBST(BinaryTreeNode<int> *root)
{
    //    return isBST(root,INT_MIN,INT_MAX);
    BinaryTreeNode<int> *prevNode = nullptr;
    return isBST2(root, prevNode);
} 