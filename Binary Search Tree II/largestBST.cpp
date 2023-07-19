#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> findLargestBST(TreeNode<int> *root)
{
    if (root == nullptr)
        return {0, INT_MIN, INT_MAX};
    vector<int> left = findLargestBST(root->left);
    vector<int> right = findLargestBST(root->right);
    int leftMax = left[1], rightMax = right[1];
    int leftMin = left[2], rightMin = right[2];
    int leftBSTSize = left[0], rightBSTSize = right[0];
    if (leftMax <= root->data && rightMin >= root->data)
    {
        int subTreeMax = max(root->data, rightMax);
        int subTreeMin = min(root->data, leftMin);
        int currBSTSize = 1 + leftBSTSize + rightBSTSize;
        return {currBSTSize, subTreeMax, subTreeMin};
    }
    else
        return {max(leftBSTSize, rightBSTSize), INT_MAX, INT_MIN};
}
int largestBST(TreeNode<int> *root)
{
    vector<int> arr = findLargestBST(root);
    return arr[0];
} 