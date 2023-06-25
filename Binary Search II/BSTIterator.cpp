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
/*
Intuition : 
1.It is similar to the iterative inorder traversal of the BT.
2.Take a stack and in the constructor push the nodes into stack until the 
left nodes exists.
3.stack's top always points to the next smallest element.
4.When called for the next smallest, pop the top node from the stack 
and move the right child and push into stack until the left Most node in the
right subtree is reached.
5.return the stack's top previously taken.
6.If stack is not empty there exists a next smallest node in BST

TC : O(H) or O(logN) for the next smallest
     O(1) for the hasNext function.
     O(H) or O(logN) for the constructor
SC : O(H) space for the stack,at max height of the BT nodes stored in stack.
*/
class BSTiterator
{  
public :
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        TreeNode<int>* currNode = root;
        while(currNode)
        {
            st.push(currNode);
            currNode = currNode->left;
        }
    }

    int next()
    {
        auto nextNode = st.top();
        st.pop();
        auto currNode = nextNode->right;
        while(currNode)
        {
            st.push(currNode);
            currNode = currNode->left;
        }
        return nextNode->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/ 