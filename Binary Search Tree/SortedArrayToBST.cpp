#include <bits/stdc++.h>
/*
1.At each step find the middle node which act as root of the tree and left
array gives left subtree and right array gives right subtree.
2.Recursively build the tree

TC : O(n)
SC : O(n)
*/
TreeNode<int> *constructBST(vector<int> &arr, int low, int high)
{
    if (low > high)
        return nullptr;
    int mid = low + (high - low) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = constructBST(arr, low, mid - 1);
    root->right = constructBST(arr, mid + 1, high);
    return root;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return constructBST(arr, 0, n - 1);
} 