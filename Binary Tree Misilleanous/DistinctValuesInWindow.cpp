#include <bits/stdc++.h>
/*
Intuition :
1.use the hashMap to keep track of the unique elements in the current Window.

Time Complexity  : O(n)
Space Compelxity : O(k)
*/
vector<int> usingHashTable(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> freqMap;
    vector<int> ans;
    /*Finding the unique elements in first window*/
    for (int i = 0; i < k; ++i)
        ++freqMap[arr[i]];
    /*pushing into ans vector*/
    ans.push_back(freqMap.size());
    for (int i = k; i < n; ++i)
    {
        if (--freqMap[arr[i - k]] == 0)
            freqMap.erase(arr[i - k]);
        ++freqMap[arr[i]];
        ans.push_back(freqMap.size());
    }
    return ans;
}
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    return usingHashTable(arr, k);
} 