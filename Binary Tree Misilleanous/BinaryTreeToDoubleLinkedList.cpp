void convertBtToDLL(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&prevNode,
                    BinaryTreeNode<int> *&DLLHead)
{
    if (root == nullptr)
        return;
    convertBtToDLL(root->left, prevNode, DLLHead);
    root->left = prevNode;
    if (prevNode == nullptr)
        DLLHead = root;
    else
        prevNode->right = root;
    prevNode = root;
    convertBtToDLL(root->right, prevNode, DLLHead);
}
BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *prevNode = nullptr;
    BinaryTreeNode<int> *DLLHead = nullptr;
    convertBtToDLL(root, prevNode, DLLHead);
    return DLLHead;
} 