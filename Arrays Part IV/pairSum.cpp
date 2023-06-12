#include <bits/stdc++.h>
vector<vector<int>> bruteForce(vector<int> &arr, int s)
{
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((arr[i] + arr[j]) == s)
            {
                int mini = min(arr[i], arr[j]);
                int maxi = max(arr[i], arr[j]);
                ans.push_back({mini, maxi});
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
vector<vector<int>> usingMap(vector<int> &arr, int s)
{
    int n = arr.size();
    vector<vector<int>> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i)
    {
        int requiredVal = (s - arr[i]);
        for (int j = 0; j < map[requiredVal]; ++j)
        {
            int mini = min(arr[i], requiredVal);
            int maxi = max(arr[i], requiredVal);
            ans.push_back({mini, maxi});
        }
        ++map[arr[i]];
    }
    sort(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    // return bruteForce(arr,s);
    return usingMap(arr, s);
    // return twoPointers(arr,s);
} 