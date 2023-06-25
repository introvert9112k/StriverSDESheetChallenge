#include <bits/stdc++.h>
/*
Inution :
1.There may be 4 cases
case 1 : both values are less than the currNode value,then they are present
in left sub tree,so move to left Subtree.
case 2 : both values are greater than the currNode value,then they are present
in right sub tree,so move to right Subtree.
Case 3 : If one value is > and one value < than currNode then it is the LCA.
case 4 : if one is found before the other node then the found node is lca
*/
TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{

    TreeNode<int> *currNode = root;
    while (currNode)
    {
        if (currNode == P || currNode == Q)
            return currNode;                                           // case 4
        else if (currNode->data > P->data && currNode->data > Q->data) // case 1
            currNode = currNode->left;
        else if (currNode->data < P->data && currNode->data < Q->data) // case 2
            currNode = currNode->right;
        else // case 3
            return currNode;
    }
    return nullptr;
}
 