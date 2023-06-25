/*
Intuition :
1.similar to the construct BT from inorder and preorder problem.

TC : O(n)
SC : O(n)
*/
#include <bits/stdc++.h>
TreeNode<int> *constructBT(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inMap)
{
    if (inStart > inEnd || postStart > postEnd)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(postorder[postEnd]);
    int ind = inMap[postorder[postEnd]];
    int numsLeft = inEnd - ind;
    root->left = constructBT(inorder, inStart, ind - 1, postorder,
                             postStart, postEnd - numsLeft - 1, inMap);
    root->right = constructBT(inorder, ind + 1, inEnd, postorder,
                              postEnd - numsLeft, postEnd - 1, inMap);
    return root;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    int n = inOrder.size();
    int inStart = 0, inEnd = n - 1;
    int postStart = 0, postEnd = n - 1;
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; ++i)
        inMap[inOrder[i]] = i;
    return constructBT(inOrder, inStart, inEnd, postOrder, postStart, postEnd, inMap);
} 