#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
/*
Intution : 
1.There may be three case possible
Case 1 : if currNode->val == x then it is the least element which is >= x,
so return x
Case 2 : if currNode->val > x this might be ans,if we go left we might found better value > x and nearer.
Case 3 : if currNode->val < x then go to right.
*/
int findCeil(BinaryTreeNode<int> *node, int X){
   BinaryTreeNode<int>* currNode = node;
   int ans = -1;
   while(currNode)
   {
       if(currNode->data == X) return X; //case 1
       else if (currNode->data > X) { // case 2
         ans = currNode->data;
         currNode = currNode->left;
       }    
       else // case 3
         currNode = currNode->right;
   }
   return ans;
}  