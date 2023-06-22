/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    /*
    Inutition :
    1.stores the nodes in the array representation.
    2.At each level calculate the difference between location of the first Node and last node in that level in array.
    3.Take the maximum among.

    In array :
    if node is at index i, then its left and right child are at indexes 2*i,2*i+1 if it is
    1 based indexing.
    IF it is zero based indexing then it is 2*i+1,2*i+2.

    This might cause a oveflow,because every time we are multipying with the 2 to get the
    next level,i.e indireclty 2 power is increasing,in case of skew tree of size 100
    in would be 2^100. Which ultimately gives the overflow.

    To avoid this in which level we start the count from the 1,inorder get this we need
    to subtract min location from the parent level,so that next level starts from the
    1.

    TC : O(n)
    Sc : O(n)
    */
    int maxWidthOfBTBFs(TreeNode *root)
    {
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int Maxwidth = INT_MIN;
        while (!q.empty())
        {
            int size = q.size();
            int Leftmostind, Rightmostind;
            int minInd = q.front().second; /*min value in current level*/
            for (int i = 0; i < size; i++)
            {
                TreeNode *Curr = q.front().first;
                /*subtracting from parent index,so the child numbers start from 1
                or any minmum value.*/
                int NodeIndex = q.front().second - minInd;
                q.pop();
                if (i == 0)
                    Leftmostind = NodeIndex;
                if (i == size - 1)
                    Rightmostind = NodeIndex;
                if (Curr->left)
                    q.push({Curr->left, 1LL * 2 * NodeIndex + 1});
                if (Curr->right)
                    q.push({Curr->right, 1LL * 2 * NodeIndex + 2});
            }
            Maxwidth = max(Maxwidth, Rightmostind - Leftmostind + 1);
        }
        return Maxwidth;
    }
    /*
    Intuition :
    1.same as in BFs approach but we employed DFs here.
    2.Just find the location of first node in the current level,as DFs performs when
    we reach the node of that current level we will subtract curr node location from the first node location in the current level, so ultimately maximum would be given by
    the difference between first and last node in current level.
    3.map is used to keep track of the level and index of first node in the level.

    TC : O(n)
    SC : o(n + n)
    Space for the map and recursive stack space.
    */
    void DFs(TreeNode *root, int depth, long long index, unordered_map<int, long long> &map,
             long long &maxWidth)
    {
        if (root == nullptr)
            return;
        if (map.find(depth) == map.end())
            map[depth] = index;
        maxWidth = max(maxWidth, index - map[depth] + 1);
        DFs(root->left, depth + 1, 2 * (index - map[depth]) + 1, map, maxWidth);
        DFs(root->right, depth + 1, 2 * (index - map[depth]) + 2, map, maxWidth);
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        long long maxWidth = LONG_LONG_MIN;
        unordered_map<int, long long> map;
        DFs(root, 0, 0, map, maxWidth);
        return int(maxWidth);
    }
}; 