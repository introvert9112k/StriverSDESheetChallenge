vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    for (int level = 0; !q.empty(); ++level)
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; ++i)
        {
            auto currNode = q.front();
            q.pop();
            if (level & 1)
                temp[size - i - 1] = currNode->data;
            else
                temp[i] = currNode->data;
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
        for (auto val : temp)
            ans.push_back(val);
    }
    return ans;
} 