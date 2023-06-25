/*Intuition :
1.This is similar to the identical tree question.
2.Take two pointers root1 and root2 which explores left and right subtree
and check for the symmetry

TC : O(n)
SC : O(n)
Recursive stack space*/
bool isSymmetricTree(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == nullptr || root2 == nullptr)
        return root1 == root2;
    if (root1->data != root2->data)
        return false;
    return isSymmetricTree(root1->left, root2->right) &&
           isSymmetricTree(root1->right, root2->left);
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return true;
    return isSymmetricTree(root->left, root->right);
} 