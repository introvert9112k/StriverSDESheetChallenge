/*
Tc : O(n)
sc : O(n)
*/
bool isIdenticalDFs(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    /*If any of the roots become nullptr,then other root also should be null
    if yes return true else return false*/
    if (root1 == nullptr || root2 == nullptr)
        return root1 == root2;
    /*if both nodes values are different then return false*/
    if (root1->data != root2->data)
        return false;
    /*If any subtree returned false,then return false*/
    return isIdenticalDFs(root1->left, root2->left) &&
           isIdenticalDFs(root1->right, root2->right);
}
bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // Write your code here.
    return isIdenticalDFs(root1, root2);
} 