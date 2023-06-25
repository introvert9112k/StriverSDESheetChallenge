#include <bits/stdc++.h>
/*
Intuition :
1.Intuition is to make sure that the children sum is greater than the parent sum
at every node.
2.Inorder to make this happen for every node,the leaf nodes should be replaced with
the maximum value in the binary tree.
3.If this is done what ever the value at the node,it's value would be <= children
sum.

TC : O(n + n)
n -- for finding the maximum value in the binary tree.
n -- for making the tree to obey the children sum property.
SC : O(n)
*/
int maximumValueinBT(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return 0;
    int left = maximumValueinBT(root->left);
    int right = maximumValueinBT(root->right);
    return max({left, right, root->data});
}
int childrenSumTree(BinaryTreeNode<int> *root, int maxValue)
{
    if (root == nullptr)
        return 0;
    int left = childrenSumTree(root->left, maxValue);
    int right = childrenSumTree(root->right, maxValue);
    /*
    Here three cases possible
    1.When node is leaf node then change value to maxvalue.
    2.When both children exists then node value = sum of children value.
    3.If any one of the child exists,then node vlaue = non null children value.
    All these can be combined into one equation
    ie. root->data = max(maxValue,left + right);

    case 1 : if(left == 0 && right == 0) root->data = maxValue;
    case 2 : else if(left != 0 && right != 0) root->data = (left + right);
    case 3 : else root->data = left ? left : right;
    */
    root->data = max(maxValue, left + right);
    return root->data;
}
void changeTree(BinaryTreeNode<int> *root)
{
    int maxValue = maximumValueinBT(root);
    childrenSumTree(root, maxValue);
} 