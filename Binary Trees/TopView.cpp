#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*
Intuition :
1.The first node in the every vertical level gives the top View of the binary tree

TC : O(nlogn)
m -- No of vertical levels.
level Order Traversal runs for the O(n) and we are inserting the node into the map
which taks logm time.
SC : O(m + n)
m -- space for the map
n -- space for the queue
*/
void findTopView(TreeNode<int> *root, map<int, int> &topViewMap)
{
    /*In queue stores pair in which
    first  -- currNode
    second -- vertical level of the node*/
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *currNode = it.first;
        int currVerticalLevel = it.second;
        /*update only first time when the vertical level is encountered*/
        if (topViewMap.find(currVerticalLevel) == topViewMap.end())
            topViewMap[currVerticalLevel] = currNode->val;
        if (currNode->left)
            q.push({currNode->left, currVerticalLevel - 1});
        if (currNode->right)
            q.push({currNode->right, currVerticalLevel + 1});
    }
}
vector<int> getTopView(TreeNode<int> *root)
{
    if (root == nullptr)
        return vector<int>();
    /*In map
    key   -- vertical level
    value -- first node in that vertical level*/
    map<int, int> topViewMap;
    vector<int> ans;
    findTopView(root, topViewMap);
    for (auto it : topViewMap)
        ans.push_back(it.second);
    return ans;
}