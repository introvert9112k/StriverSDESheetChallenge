#include <bits/stdc++.h>
/*
Intuition :
1.This is similar to the unique subset question,just we want to find the
those subset whose sum is equal to the target.

TC : O(2^n*k)
k -- average length of all the subsets.
There will be 2^n combinations/subsets and when subset sum equal to target
we are inserting them into unqiue combinations which take O(n) time.
SC : O(2^n*k)
There are 2 ^n subsets we are storing them into the ans.
*/
void findValidCombinations(int ind, int n, int target, vector<int> &arr,
                           vector<int> &combination, vector<vector<int>> &uniqueCombinations)
{
    if (ind == n || target == 0)
    {
        if (target == 0)
            uniqueCombinations.push_back(combination);
        return;
    }
    for (int i = ind; i < n; ++i)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] <= target)
        {
            combination.push_back(arr[i]);
            findValidCombinations(i + 1, n, target - arr[i], arr, combination, uniqueCombinations);
            combination.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> uniqueCombinations;
    vector<int> combination;
    findValidCombinations(0, n, target, arr, combination, uniqueCombinations);
    return uniqueCombinations;
} 