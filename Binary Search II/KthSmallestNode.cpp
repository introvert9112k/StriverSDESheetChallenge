#include <bits/stdc++.h> 
/*
Intution : 
1.find the kth smallest element in BST by traversing,when found return form there.

TC : O(n)
SC : O(n)
*/
int findKthSmallest(TreeNode<int>* root,int &k)
{
    if(root == nullptr) return -1;
    int left = findKthSmallest(root->left,k);
    if(left != -1) return left;
    --k;
    if(k == 0) return root->data;
    int right = findKthSmallest(root->right,k);
    if(right != -1) return right;
    return -1;
}
int kthSmallest(TreeNode<int> *root, int k)
{
   return findKthSmallest(root,k);	
}  