#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*Intuition :
1.The first node in the every level gives the left View of BT.
2.For the right View the last node in the every level gives the right view of BT
3.In case of right view we can also do the reverse preorder traversal,so the
first node in the reverse traversal gives the right view of BT

TC : O(N)
SC : O(N)*/
void levelOrderTraversal(TreeNode<int> *root, vector<int> &leftView)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    for (int level = 0; !q.empty(); ++level)
    {
        bool flag = false;
        for (int i = q.size(); i > 0; --i)
        {
            if (flag == false)
                leftView.push_back(q.front()->data), flag = true;
            TreeNode<int> *currNode = q.front();
            q.pop();
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
    }
}
/*
   TC : O(N)
   SC : O(H)
*/
void findLeftView(TreeNode<int> *root, int currLevel, vector<int> &leftview)
{
    if (root == nullptr)
        return;
    if (leftview.size() < currLevel)
        leftview.push_back(root->data);
    findLeftView(root->left, currLevel + 1, leftview);
    findLeftView(root->right, currLevel + 1, leftview);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    if (root == nullptr)
        return vector<int>();
    vector<int> leftView;
    // levelOrderTraversal(root,leftView);
    findLeftView(root, 1, leftView);
    return leftView;
} 