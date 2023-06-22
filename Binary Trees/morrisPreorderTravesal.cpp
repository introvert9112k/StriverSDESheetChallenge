#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
/*
TC : O(N)
SC : O(N) recursive stack space.
*/
void preOrderTraversal(TreeNode *root, vector<int> &preorder)
{
    if (root == nullptr)
        return;
    preorder.push_back(root->data);
    preOrderTraversal(root->left, preorder);
    preOrderTraversal(root->right, preorder);
}
/*
TC : O(n)
SC : O(n)
space for the stack.
*/
void preOrderTraversalIterative(TreeNode *root, vector<int> &preorder)
{
    stack<TreeNode *> st;
    TreeNode *currNode = root;
    while (!st.empty() || currNode)
    {
        while (currNode)
        {
            preorder.push_back(currNode->data);
            st.push(currNode);
            currNode = currNode->left;
        }
        currNode = st.top();
        st.pop();
        currNode = currNode->right;
    }
}
void morrisPreorderTraversal(TreeNode *root, vector<int> &preorder)
{
    TreeNode *currNode = root;
    while (currNode)
    {
        // case 1 : when there is no left child
        if (currNode->left == nullptr)
        {
            preorder.push_back(currNode->data); // take into inorder
            currNode = currNode->right;         // move to right child
        }
        else
        {
            TreeNode *prevNode = currNode->left;
            /*Until any of the cases i.e either rightMost node's right is nullptr
            or rightMost node's right points to the currNode move the pointer*/
            while (prevNode->right && prevNode->right != currNode)
                prevNode = prevNode->right;

            // case 2 : rightMost Node's right is nullptr
            if (prevNode->right == nullptr)
            {
                prevNode->right = currNode; // connecting rightMost and currNode
                preorder.push_back(currNode->data);
                currNode = currNode->left; // moving to the leftChild
            }
            // case 3 : rightMost node's right point to currNOde
            else
            {
                prevNode->right = nullptr;  // removing the thread
                currNode = currNode->right; // moving to the right child
            }
        }
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    // preOrderTraversal(root,preorder);
    // preOrderTraversalIterative(root,preorder);
    morrisPreorderTraversal(root, preorder);
    return preorder;
} 