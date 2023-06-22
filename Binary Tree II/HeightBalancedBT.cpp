#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
/*
Intuition :
1.For each subtree check if the tree is height balanced or not
TC :  O(n)
SC :  O(n)
*/
int isTreeBalanced(BinaryTreeNode<int> *root, bool &isBalanced)
{
    if (root == nullptr)
        return 0;
    int leftHeight = isTreeBalanced(root->left, isBalanced);
    int rightHeight = isTreeBalanced(root->right, isBalanced);
    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;
    return 1 + max(leftHeight, rightHeight);
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    bool isBalanced = true;
    isTreeBalanced(root, isBalanced);
    return isBalanced;
} 