#include <bits/stdc++.h>

void findInorder(BinaryTreeNode<int> *root, vector<int> &inorder)
{
    if (root == nullptr)
        return;
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}
bool approach1(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    findInorder(root, inorder);
    int i = 0, j = inorder.size() - 1;
    while (i < j)
    {
        int sum = inorder[i] + inorder[j];
        if (sum == k)
            return true;
        else if (sum > k)
            --j;
        else
            ++i;
    }
    return false;
}

bool usingMap(BinaryTreeNode<int> *root, int k, unordered_map<int, int> &map)
{
    if (root == nullptr)
        return false;
    if (map.find(k - root->data) != map.end())
        return true;
    ++map[root->data];
    if (usingMap(root->left, k, map))
        return true;
    return usingMap(root->right, k, map);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // return approach1(root,k);

    unordered_map<int, int> map;
    return usingMap(root, k, map);
} 