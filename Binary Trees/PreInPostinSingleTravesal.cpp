#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
/*
Intuition :
1.Just do the recursive traversals and store the preorder,inorder and postorder
at their respective positions.

TC : O(N)
SC : O(n)
excluding the space for the ans.
*/
void findAllTraversals(BinaryTreeNode<int> *root, vector<vector<int>> &traversals)
{
    if (root == nullptr)
        return;
    traversals[1].push_back(root->data);
    findAllTraversals(root->left, traversals);
    traversals[0].push_back(root->data);
    findAllTraversals(root->right, traversals);
    traversals[2].push_back(root->data);
}
/*
Intuition :
In preorder traversal, we print a node at the first visit itself.
Whereas, in inorder traversal at the first visit to a node, we simply traverse to
the left child. It is only when we return from the left child and visit that node
the second time, that we print it.
Similarly, in postorder traversal, we print a node in its third visit
after visiting both its children.
The same logic is employed here

stack stores the pair in which
first -- node
second -- visit of the node {1,2,3}
If visit
1 -- preorder
2 -- inorder
3 -- postorder.

TC : O(3N)
We are visiting each node thrice,so tC is O(3N)
Sc : O(n)
Recursive stack space,excluding the space for traversals.
*/
void traversalsIterative(BinaryTreeNode<int> *root, vector<vector<int>> &traversals)
{
    /*intially we are at the root node and it is first visit.
    So stack stores the root and 1*/
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        BinaryTreeNode<int> *currNode = it.first;
        int num = it.second;
        /*Current visit is one,so it should be in preorder.*/
        if (num == 1)
        {
            traversals[1].push_back(currNode->data); // taking into preorder
            /*this should again should be visited in inorder,so push intot the
            stack the same node with visit 2*/
            st.push({currNode, 2});
            /*If currnode->left exists then move to left,as we are visiting the left
            child for the first time visit equal to 1*/
            if (currNode->left)
                st.push({currNode->left, 1});
        }
        /*Current visit is 2,so it should be inorder*/
        else if (num == 2)
        {
            traversals[0].push_back(currNode->data); // taking into inorder
            /*This node must be visited again in the 3rd visit,so push the
            currNode with visit 3 into stack.*/
            st.push({currNode, 3});
            /*If the visit is 2,that mean the left subtree of the currNode has been
            traversed,so now it's time for the right subtree.
            IF there exists a right child,push into the stack with visit as 1.
            Because as of now we just finished the currnode and leftsubtree,the righ
            subtree is not travesed yet,so it is first visit for the right sub tree*/
            if (currNode->right)
                st.push({currNode->right, 1});
        }
        /*if current visit is 3,that is we are visiting this node for the 3 time
        so it should be in postorder,as the left subtree and right subtree of the
        currNode is already traversed so no need push anything into stack.*/
        else
        {
            traversals[2].push_back(currNode->data);
        }
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return vector<vector<int>>();
    vector<vector<int>> traversals(3, vector<int>());
    // findAllTraversals(root,traversals);
    traversalsIterative(root, traversals);
    return traversals;
} 