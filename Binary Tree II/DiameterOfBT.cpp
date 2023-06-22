/*intuition :
1.For every node find the height of the left and right subtree
2.diameter is the maximum among the (leftHeight + rightHeight +1) of every node

TC : O(n)
sC : o(n)*/
#include <bits/stdc++.h>
int findDiameter(TreeNode<int> *root, int &diameter)
{
    if (root == nullptr)
        return 0;
    int leftMaxHeight = findDiameter(root->left, diameter);
    int rightMaxHeight = findDiameter(root->right, diameter);
    diameter = max(diameter, rightMaxHeight + leftMaxHeight + 1);
    return 1 + max(leftMaxHeight, rightMaxHeight);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = INT_MIN;
    findDiameter(root, diameter);
    return diameter - 1;
} 