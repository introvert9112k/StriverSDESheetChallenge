#include <bits/stdc++.h>
/*
Intuition :
1. Suppose if we start doing the preorder traversal i.e root left right,then we first
convert the left subtree to the linkedlist and then the right subtree to linkedlist
and we attach left subtree linkedlist head to the root and connect right subtree
linkedlist to the end of left subtree linkedlist
2.Here we need leftHead,leftTail rightHead and rightTail.
3.suppose if we traverse in such way that right left root,first we wound encounter
the last nodes in the preorder travesal, if we keep track of the previously visited
node we can connect the currnode to the previous node and make currnode as previous
node.
4.Then our task is done,So we do reverse post order traversal (right left root) and
maintain a previous node to keep track of the previous visited node.

TC : o(n)
Sc : o(n)
*/
TreeNode<int> *flattenToLinkedList(TreeNode<int> *root, TreeNode<int> *&prevNode)
{
    if (root == nullptr)
        return nullptr;
    flattenToLinkedList(root->right, prevNode);
    flattenToLinkedList(root->left, prevNode);
    root->right = prevNode; // connecting current node to prevNode
    root->left = nullptr;   // making the currnode left point to nullptr
    prevNode = root;        // making currnode as prevNode
    return root;
}
/*Here we just use the iterative method to flatten BT to linkedList
First we push the root into stack,we pop and
There after we push the right child first and left child later
Now we don't bother about the changing the links of the root,because we interseted
in the left and right subtrees only,as already we have the heads of the right and
left subtrees,we can change the links of the roots.

So we would mark the root->left = nullptr and root->right points to the left child
as we want the preorder traversal.
That is why we are pushing the right child first and later left child into stack,
so that stack's top always points to the left child.
*/
TreeNode<int> *flattenToLinkedListIterative(TreeNode<int> *root)
{
    stack<TreeNode<int> *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode<int> *currNode = st.top();
        st.pop();
        if (currNode->right)
            st.push(currNode->right);
        if (currNode->left)
            st.push(currNode->left);
        if (!st.empty())                // stack's top contains the left child
            currNode->right = st.top(); // making left child as right pointer
        currNode->left = nullptr;       // making left pointer as nullptr
    }
    return root;
}
/*
If we do the preorder traversal i.e root left right.
We can observe that the right most node in the left subtree comes befor the
head of the right subtree.
So if we can make the right pointer of the rightMost node in left subtree to the
right subtree head for every node then our work would be done
*/
TreeNode<int> *morris(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            // prev points to the right Most node in the left subtree
            TreeNode<int> *prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            /*making right pointer of the rightMost node point to the currodes
            right or rightsubtree's head*/
            prev->right = curr->right;
            /*As we alredy made the connection,we don't bother about the links
            of the currnode so making currnode right point to currnode left*/
            curr->right = curr->left;
            curr->left = NULL; // making currNode->left nullptr
        }
        curr = curr->right; // as left child is now right side of the currnode,moving
        // to right.
    }
    return root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prevNode = nullptr;
    // return flattenToLinkedList(root,prevNode);
    // return flattenToLinkedListIterative(root);
    return morris(root);
} 