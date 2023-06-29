#include <bits/stdc++.h>
class Kthlargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    // TC : O(klogk)
    Kthlargest(int _k, vector<int> &arr)
    {
        k = _k;
        for (int i = 0; i < k; ++i)
            pq.push(arr[i]);
    }
    // TC : O(logk)
    void add(int num)
    {
        pq.push(num);
        if (pq.size() > k)
            pq.pop();
    }
    // TC : O(1)
    int getKthLargest()
    {
        return pq.top();
    }
}; 