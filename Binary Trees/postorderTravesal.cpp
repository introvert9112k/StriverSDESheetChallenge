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
   TC : O(n)
   SC : O(n)
*/
void postOrderTraversal(TreeNode *root, vector<int> &postorder)
{
    if (root == nullptr)
        return;
    postOrderTraversal(root->left, postorder);
    postOrderTraversal(root->right, postorder);
    postorder.push_back(root->data);
}
void iterativePostorder(TreeNode *root, vector<int> &postorder)
{
    stack<TreeNode *> stack1;
    stack<int> stack2;
    // take two stacks one for storing the nodes and other for storing the postorder traversal
    // push the root into stack
    stack1.push(root);
    while (!stack1.empty())
    {
        // pop the node from the stack1 and push the popped nodes data into stack2
        TreeNode *temp = stack1.top();
        stack1.pop();
        stack2.push(temp->data);
        // if left child exists then push it into stack1
        if (temp->left)
            stack1.push(temp->left);
        // if right child exists push into stack1
        if (temp->right)
            stack1.push(temp->right);
    }
    // after the iteration the stack2 contains the post order traversal of the tree
    // print the stack elements one by one
    while (!stack2.empty())
    {
        postorder.push_back(stack2.top());
        stack2.pop();
    }
}
void iterativePostorder2(TreeNode *root, vector<int> &postorder)
{
    TreeNode *cur = root;
    stack<TreeNode *> st;
    while (cur != NULL || !st.empty())
    {

        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return vector<int>();
    vector<int> postorder;
    // postOrderTraversal(root,postorder);
    // iterativePostorder(root,postorder);
    iterativePostorder2(root, postorder);
    return postorder;
} 