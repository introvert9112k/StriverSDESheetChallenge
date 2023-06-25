#include <bits/stdc++.h>
// see the TUf article
TreeNode<int> *constructTree(vector<int> &preorder, int preStart, int preEnd,
                             vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int rootInd = inMap[preorder[preStart]];
    int numsLeft = rootInd - inStart;
    root->left = constructTree(preorder, preStart + 1, preStart + numsLeft, inorder,
                               inStart, rootInd - 1, inMap);
    root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd, inorder,
                                rootInd + 1, inEnd, inMap);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> inMap;
    int n = inorder.size();
    for (int i = 0; i < n; ++i)
        inMap[inorder[i]] = i;
    return constructTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
} 