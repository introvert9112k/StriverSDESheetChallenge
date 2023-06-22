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
void inorderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
/*
TC : O(n)
SC : O(n)
space for the stack.
*/
void inorderTraversalIterative(TreeNode *root, vector<int> &inorder)
{
    stack<TreeNode *> st;
    TreeNode *currNode = root;
    while (!st.empty() || currNode)
    {
        while (currNode)
        {
            st.push(currNode);
            currNode = currNode->left;
        }
        currNode = st.top();
        st.pop();
        inorder.push_back(currNode->data);
        currNode = currNode->right;
    }
}
/*
Inutition :
1.If we write the inorder traversal that for the current node,in the traversal
the previous node will be the right Most node in the left subtree of the node.
ex : For the tree given in the question inorder traversal is
5 3 2 1 7 4 6
let's take node 1,the previous node is 2,it is the rightMost node in the left
subtree of node 1.
If we take 3 it's previous node is 5, it is the rightMost node in the left subtree
of node 3.

In itreative or the recursion approach if we are at 2,we backtrack until we reach 1.
What if we directly go to the node 1 from node 2.This is where threading comes into
picture.

Morris Traversal Algo :
1.If we are at the currNode before going to the left child,we connect the rightMost
node in the left subtree of the currnode to the currnode,and move to left child.
2.follow the process for the rest of the nodes.
3.There may be 3 cases while simulating this process

Case 1: When the current node has no left subtree. In this scenario,
there is nothing to be traversed on the left side, so we simply print the value
of the current node and move to the right of the current node.

Case 2: When there is a left subtree and the right-most child of this left subtree
is pointing to null. In this case we need to set the right-most child to point to
the current node, instead of NULL and move to the left of the current node.

Case 3: When there is a left subtree and the right-most child of this left-subtree
is already pointing to the current node. In this case we know that the left subtree
is already visited so we need to print the value of the current node and
move to the right of the current node.

Note: Case 3 is very important as we need to remove the new links added to restore
the original tree.

To summarize, at a node whether we have to move left or right is determined
whether the node has a left subtree. If it doesn’t we move to the right.
 If there is a left subtree then we see its rightmost child.
 If the rightmost child is pointing to NULL, we move the current node to its left.
 If the rightmost child is already pointing towards the current node,
 we remove that link and move to the right of the current node. We will stop the
 execution when the current points to null and we have traversed the whole tree.
*/
void morrisInorderTraversal(TreeNode *root, vector<int> &inorder)
{
    TreeNode *currNode = root;
    while (currNode)
    {
        // case 1 : when there is no left child
        if (currNode->left == nullptr)
        {
            inorder.push_back(currNode->data); // take into inorder
            currNode = currNode->right;        // move to right child
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
                currNode = currNode->left;  // moving to the leftChild
            }
            // case 3 : rightMost node's right point to currNOde
            else
            {
                prevNode->right = nullptr;         // removing the thread
                inorder.push_back(currNode->data); // taking into inorder
                currNode = currNode->right;        // moving to the right child
            }
        }
    }
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    //    inorderTraversal(root,inorder);
    //    inorderTraversalIterative(root,inorder);
    morrisInorderTraversal(root, inorder);
    return inorder;
} 