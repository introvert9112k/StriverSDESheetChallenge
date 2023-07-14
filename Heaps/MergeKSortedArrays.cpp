#include <bits/stdc++.h>
void mergeTwoSortedArrays(vector<int> &ans, vector<int> &arr)
{
    int n = ans.size(), m = arr.size();
    vector<int> temp(n + m);
    for (int i = 0, j = 0, k = 0; i < n || j < m; ++k)
    {
        if (i < n && j < m)
            temp[k] = ans[i] <= arr[j] ? ans[i++] : arr[j++];
        else
            temp[k] = i < n ? ans[i++] : arr[j++];
    }
    for (int i = 0; i < n + m; ++i)
    {
        if (i < n)
            ans[i] = temp[i];
        else
            ans.push_back(temp[i]);
    }
}
vector<int> usingSorting(vector<vector<int>> &kArrays, int k)
{
    int k = kArrays.size();
    if (k == 1)
        return kArrays[0];
    vector<int> ans;
    for (auto val : kArrays[0])
        ans.push_back(val);
    for (int i = 1; i < k; ++i)
        mergeTwoSortedArrays(ans, kArrays[i]);
    return ans;
}
vector<int> usingPriorityQueue(vector<vector<int>> &kArrays, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> ans;
    for (int i = 0; i < k; ++i)
        pq.push({kArrays[i][0], i, 0});
    while (!pq.empty())
    {
        auto it = pq.top();
        int val = it[0];
        int arrayInd = it[1];
        int ind = it[2];
        pq.pop();
        ans.push_back(val);
        if (ind + 1 < kArrays[arrayInd].size())
        {
            int nextValue = kArrays[arrayInd][ind + 1];
            int nextInd = ind + 1;
            pq.push({nextValue, arrayInd, nextInd});
        }
    }
    return ans;
}
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    //  return usingSorting(kArrays,k);
    return usingPriorityQueue(kArrays, k);
} 