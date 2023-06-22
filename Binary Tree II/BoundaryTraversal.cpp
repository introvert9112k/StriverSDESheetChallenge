/*
Intuition :
1.Boundary of the Binary Tree include
Boundary = left Boundary + leaf nodes + right Boundary.
In boundary root node will be the first node,so take it into the ans.

Left Boundary travesal :
1.Now start from the root->left take the nodes in the left boundary.
2.start moving from the root->left and if there exists left child of currnode then
move left,if left doesn't exists the move right.
3.When the leaf node is reached stop the iteration.

Leaf Nodes :
Traverse the tree and find all the leaves nodes.

RightBoundary travesal :
1.Now start from the root->right take the nodes in the right boundary.
2.start moving from the root->right and if there exists right child of currnode then
move right,if right doesn't exists the move left.
3.When the leaf node is reached stop the iteration.
4.In the final we would get the right boundary in clockwise we need in anticlock
wise so just reverse the right boundary obtained.

NOTE : In case of single node,it is taken twice as root and the leaf node,so handle
it expliclty.
Always start the root->left and root->right,if we start from the root,in case of teh
skew trees we right and left bound becomes same.

TC : O(3n)
n -- for left boundary
n -- for all leaf nodes
n -- for right boundary
SC : O(n)
for the right boundary.
*/
void findAllLeafNodes(TreeNode<int> *root, vector<int> &ans)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        ans.push_back(root->data);
    findAllLeafNodes(root->left, ans);
    findAllLeafNodes(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    ans.push_back(root->data);
    /*special case*/
    if (root->left == nullptr && root->right == nullptr)
        return ans;
    /*Finding the left boundary*/
    TreeNode<int> *currNode = root->left;
    while (currNode)
    {
        if (currNode->left == nullptr && currNode->right == nullptr)
            break;
        ans.push_back(currNode->data);
        if (currNode->left)
            currNode = currNode->left;
        else if (currNode->right)
            currNode = currNode->right;
    }
    /*Finding all the leaf nodes*/
    findAllLeafNodes(root, ans);
    /*Finding the right boundary*/
    currNode = root->right;
    vector<int> rightBoundary;
    while (currNode)
    {
        if (currNode->left == nullptr && currNode->right == nullptr)
            break;
        rightBoundary.push_back(currNode->data);
        if (currNode->right)
            currNode = currNode->right;
        else if (currNode->left)
            currNode = currNode->left;
    }
    /*reversing the right boundary*/
    reverse(rightBoundary.begin(), rightBoundary.end());
    /*Adding the right boundary to ans*/
    for (auto val : rightBoundary)
        ans.push_back(val);
    return ans;
} 