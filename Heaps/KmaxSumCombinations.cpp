#include <bits/stdc++.h>
/*
TC : O(n^2 + O(n^2log(n^2)) + k)
n^2 for finding all the combinations
n^2log(n^2) for the sorting all the combinations
k -- for finding the maximum sum combinations
SC : O(n*n) space for storing the combinations
*/
vector<int> bruteForce(vector<int> &a, vector<int> &b, int n, int k)
{
    vector<int> combinations(n * n);
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            combinations[p++] = (a[i] + b[j]);
        }
    }
    sort(combinations.begin(), combinations.end());
    vector<int> ans(k);
    for (int i = 0; i < k; ++i)
        ans[i] = combinations[n * n - i - 1];
    return ans;
}
/*
TC : O(n^2(logk) + klogk)
n^2logk for finding the combinations and inserting into the minHeap
klogk -- for finding the maximums sum combinations
SC : O(k)
Space for the minHeap
*/
vector<int> usingPriorityQueue(vector<int> &a, vector<int> &b, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            minHeap.push(a[i] + b[j]);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }
    vector<int> ans(k);
    for (int i = k - 1; i >= 0; --i)
    {
        ans[i] = minHeap.top();
        minHeap.pop();
    }
    return ans;
}
vector<int> usingPriorityQueue2(vector<int> &a, vector<int> &b, int n, int k)
{
    priority_queue<vector<int>, vector<vector<int>>> pq;
    set<pair<int, int>> set;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    pq.push({a[n - 1] + b[n - 1], n - 1, n - 1});
    set.insert({n - 1, n - 1});
    vector<int> ans;
    while (k > 0)
    {
        auto it = pq.top();
        int combinationSum = it[0];
        int x = it[1], y = it[2];
        pq.pop();
        ans.push_back(combinationSum);
        if (set.find({x - 1, y}) == set.end())
        {
            pq.push({a[x - 1] + b[y], x - 1, y});
            set.insert({x - 1, y});
        }
        if (set.find({x, y - 1}) == set.end())
        {
            pq.push({a[x] + b[y - 1], x, y - 1});
            set.insert({x, y - 1});
        }
        --k;
    }
    return ans;
}
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    return usingPriorityQueue2(a, b, n, k);
} 