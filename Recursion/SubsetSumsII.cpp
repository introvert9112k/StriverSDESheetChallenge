#include <bits/stdc++.h>
/*
1.Sort the array so that all the duplicates come to one place.
2.In each level of the recursion tree,we are finding all the unqiue subsets of size
equal to that level.

TC : O(2^n*k)
k is the average length of all the subsets.
at max there can be 2^n unique subsets.
SC : O(2^n*k)
Space for storing the unique subsets.
*/
void findUniqueSubSets(int ind, int n, vector<int> &arr, vector<int> &subset, vector<vector<int>> &ans)
{
    ans.push_back(subset);
    if (ind == n)
        return;
    for (int i = ind; i < n; ++i)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        subset.push_back(arr[i]);
        findUniqueSubSets(i + 1, n, arr, subset, ans);
        subset.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> subset;
    findUniqueSubSets(0, n, arr, subset, ans);
    return ans;
} 