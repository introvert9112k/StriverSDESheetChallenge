#include <bits/stdc++.h>
void recursion(int ind, int n, vector<int> &arr, vector<int> &subset,
               vector<vector<int>> &ans)
{
    if (ind == n)
    {
        ans.push_back(subset);
        return;
    }
    subset.push_back(arr[ind]);
    recursion(ind + 1, n, arr, subset, ans);
    subset.pop_back();
    recursion(ind + 1, n, arr, subset, ans);
}
vector<vector<int>> recursionDriverCode(vector<int> &arr)
{
    int n = arr.size();
    vector<int> subset;
    vector<vector<int>> ans;
    recursion(0, n, arr, subset, ans);
    return ans;
}
vector<vector<int>> usingBitManipulation(vector<int> &arr)
{
    int n = arr.size();
    int pow = 1 << n;
    vector<vector<int>> ans;
    for (int i = 1; i < pow; ++i)
    {
        int num = i;
        vector<int> subset;
        while (num > 0)
        {
            int rsbm = num & -num;
            subset.push_back(arr[log2(rsbm)]);
            num = num - rsbm;
        }
        ans.push_back(subset);
    }
    return ans;
}
vector<vector<int>> pwset(vector<int> v)
{
    // return recursionDriverCode(v);
    return usingBitManipulation(v);
} 