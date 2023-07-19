int maxDepth(TreeNode<int> *root)
{
    if (root == nullptr)
        return -1;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
} 