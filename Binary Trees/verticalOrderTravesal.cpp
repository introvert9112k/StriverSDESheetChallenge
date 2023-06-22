#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
void levelOrderTravsalApproach(TreeNode<int> *root, map<int, vector<int>>
                                                        &verticalMap)
{
    queue<pair<TreeNode<int> *, int>> q; /*q stores pair in which first points
      to the node and second is vertical line on which node is present*/
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *currNode = it.first;
        int currVerticalLevel = it.second;
        verticalMap[currVerticalLevel].push_back(currNode->data);
        if (currNode->left) /*If level exists then its -1 of parent vertical level*/
            q.push({currNode->left, currVerticalLevel - 1});
        if (currNode->right) /*right child is +1 of parent vertical level*/
            q.push({currNode->right, currVerticalLevel + 1});
    }
}
void recursive(TreeNode<int> *root, int currVerticalLevel, map<int, vector<int>> &verticalMap)
{
    if (root == nullptr)
        return;
    verticalMap[currVerticalLevel].push_back(root->data);
    recursive(root->left, currVerticalLevel - 1, verticalMap);
    recursive(root->right, currVerticalLevel + 1, verticalMap);
}
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> verticalOrder;         /*Stores the vertical order*/
    map<int, vector<int>> verticalMap; /*key is the vertical Line and value is
     the vector storing the nodes on that vertical line.
     As we need from left to right,we take map which stores keys in sorted order*/

    levelOrderTravsalApproach(root, verticalMap);

    // recursive(root,0,verticalMap);

    for (auto it : verticalMap)
    {
        for (auto val : it.second)
            verticalOrder.push_back(val);
    }
    return verticalOrder;
} 