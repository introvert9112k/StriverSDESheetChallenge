#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
/*
Intuition :
1.The last node in the every vertical level gives the bottom View of the binary tree

TC : O(nlogn)
m -- No of vertical levels.
level Order Traversal runs for the O(n) and we are inserting the node into the map
which taks logm time.
SC : O(m + n)
m -- space for the map
n -- space for the queue
*/
void findBottomView(BinaryTreeNode<int> * root,map<int,int> &bottomViewMap)
{  
    /*In queue stores pair in which 
    first  -- currNode
    second -- vertical level of the node*/
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *currNode = it.first;
        int currVerticalLevel = it.second;
        /*As we are doing level order traversal the maps value get updated as we 
        processed each level,so at last the node which is in the last level
        i.e bottom most node will be stored*/
        bottomViewMap[currVerticalLevel] = currNode->data;
        if(currNode->left)
           q.push({currNode->left,currVerticalLevel-1});
        if(currNode->right)
          q.push({currNode->right,currVerticalLevel+1});   
    }
} 
vector<int> bottomView(BinaryTreeNode<int> * root){
    /*In map
    key   -- vertical level
    value -- last node in that vertical level*/
    map<int,int> bottomViewMap;
    vector<int> ans;
    findBottomView(root,bottomViewMap);
    for(auto it : bottomViewMap)
      ans.push_back(it.second);
    return ans;
}  