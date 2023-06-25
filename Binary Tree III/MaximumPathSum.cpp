#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

    template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*Intuition :
1.it is similar to the diameter of the binary tree,in this we need to find the
max path sum in left subtree and right subtree and add to the currnode value.
2.If there is only single leaf node we should return -1,so if the left and right
subtree value is not -1,then only take the path sum into consideration.
3.-1 is returned if there is no leaf node.

TC : O(n)
SC : O(n)*/
long long maxPathSum(TreeNode<int> *root, long long &maxSum)
{
    if (root == nullptr)
        return -1;
    long long left = maxPathSum(root->left, maxSum);
    long long right = maxPathSum(root->right, maxSum);
    if (left != -1 && right != -1)
        maxSum = max(maxSum, left + right + root->val);
    return root->val + max({1LL * 0, left, right});
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long maxSum = -1;
    maxPathSum(root, maxSum);
    return maxSum;
} 