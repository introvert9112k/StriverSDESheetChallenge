#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

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
Intution :
1.There may be three case possible
Case 1 : if currNode->val == x then it is the greaterst element which is <= x,
so return x
Case 2 : if currNode->val > x if we go right we found all values > x so go left
Case 3 : if currNode->val < x take it into ans,if we go right we might found a better
value nearer to the x,so go right */
int floorInBST(TreeNode<int> *root, int X)
{
    TreeNode<int> *currNode = root;
    int ans;
    while (currNode)
    {
        if (currNode->val == X)
            return X; // case 1
        else if (currNode->val > X)
            currNode = currNode->left; // case 2
        else                           // case 3
        {
            ans = currNode->val;
            currNode = currNode->right;
        }
    }
    return ans;
} 