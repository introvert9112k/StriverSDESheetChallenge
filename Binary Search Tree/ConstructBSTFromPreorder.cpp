#include <bits/stdc++.h>
/*
Approach 2 :
1.Sorting the preorder gives the inorder.
2.We have the inorder and preorder,construct the BST from the inorder and preorder

TC : O(nlogn + 2n)
n -- for copying the preorder into inorder
nlogn -- for sorting the inorder
n -- for building the binary search tree
SC : O(2n)
n -- recursion stack space
n -- space for the inorder
*/
TreeNode<int> *constructTree(vector<int> &preorder, int preStart, int preEnd,
                             vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int rootInd = inMap[preorder[preStart]];
    int numsLeft = rootInd - inStart;
    root->left = constructTree(preorder, preStart + 1, preStart + numsLeft, inorder,
                               inStart, rootInd - 1, inMap);
    root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd, inorder,
                                rootInd + 1, inEnd, inMap);
    return root;
}
TreeNode<int> *approach2(vector<int> &preOrder)
{
    vector<int> inorder(preOrder.begin(), preOrder.end());
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> inMap;
    int n = inorder.size();
    for (int i = 0; i < n; ++i)
        inMap[inorder[i]] = i;
    return constructTree(preOrder, 0, n - 1, inorder, 0, n - 1, inMap);
}
/*Approach 1 :
In this approach, it can be observed that the first element of the preorder array
will always be the root of the BST. We can then note that all the elements
after the first element, which are less than the root, will be in the left
subtree of the root, and all the elements that are larger than the root
will be in the right subtree of the root.

Therefore for each root, we create two arrays leftPreOrder, rightPreOrder,
then divide the elements of the preOrder traversal into two arrays according
to whether the elements are greater than the root element or not.

Time Complexity
O(N^2), Where ‘N’ is the number of nodes in the tree.
We are iterating over each element in the preorder array, and for each element,
we are dividing the array into two subarrays, which will cost O(N^2) time.
Hence the final time complexity is O(N^2).

Space Complexity
O(N^2), Where ‘N’ is the number of nodes in the tree.
The recursion stack will take O(N) space. For each recursive call,
we make two arrays that. will take O(N) space each.
Hence the overall space complexity is O(N^2).
*/
TreeNode<int> *constructBST(vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(arr[0]);
    vector<int> leftTree, rightTree;
    for (int i = 1; i < arr.size(); ++i)
        arr[i] < arr[0] ? leftTree.push_back(arr[i]) : rightTree.push_back(arr[i]);
    root->left = constructBST(leftTree);
    root->right = constructBST(rightTree);
    return root;
}
/*
In this approach, instead of separating the array,
we will use the keep a variable preIndex, which will keep track of the
current root node, in the preorder array. We will use ranges because,
for any node in the right subtree,it has to be larger than the root,
so for every subtree in the tree we can maintain a range.

TC : O(n)
SC : O(n)
*/
TreeNode<int> *constructBSTOptimal(vector<int> &preorder, int &ind, int lowerBound,
                                   int upperBound)
{
    if (ind >= preorder.size())
        return nullptr;
    /*If node is in the range,then make a node*/
    if (preorder[ind] > lowerBound && preorder[ind] < upperBound)
    {
        // creating a new node
        TreeNode<int> *root = new TreeNode<int>(preorder[ind]);
        // incrementing the index
        ind += 1;
        // If there exists some nodes left in the preorder
        if (ind < preorder.size())
            // for the left subtree nodes upper bound is root->data
            root->left = constructBSTOptimal(preorder, ind, lowerBound, root->data);
        if (ind < preorder.size())
            // for the right subtree nodes lower bound is root->data
            root->right = constructBSTOptimal(preorder, ind, root->data, upperBound);
        return root;
    }
    return nullptr;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    int ind = 0;
    return constructBSTOptimal(preOrder, ind, INT_MIN, INT_MAX);
} 