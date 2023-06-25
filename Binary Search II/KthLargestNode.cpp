#include <bits/stdc++.h>
/*
1.Traverse reverse inorder so we get the elements in the descending order.
2.Whenever found the kth largest element then return.

Tc : O(n)
Sc : O(n)
*/
int findKthLargest(TreeNode<int> *root, int &k)
{
    if (root == nullptr)
        return -1;
    int left = findKthLargest(root->right, k);
    if (left != -1)
        return left;
    --k;
    if (k == 0)
        return root->data;
    int right = findKthLargest(root->left, k);
    if (right != -1)
        return right;
    return -1;
}
int KthLargestNumber(TreeNode<int> *root, int k)
{
    return findKthLargest(root, k);
}
 