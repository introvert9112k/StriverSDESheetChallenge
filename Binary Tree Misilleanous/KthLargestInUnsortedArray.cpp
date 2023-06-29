#include <bits/stdc++.h>
/*
The most obvious brute force approach would be to sort the array in descending
order and return the ‘K’th element from the beginning of the array.

Time Complexity : O( N * log(N) )
where ‘N’ is the size of the array.
We can sort an array in O(N * log(N)).
Space Complexity : O(1).
No extra space is used.
*/
int usingSorting(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k - 1];
}
/*
Time Complexity : O(nlogk)
inserting a number in priority queue takes logk time in worst case.
Space Complexity : O(k)
At most k elements would be there in the priroty queue
*/
int usingPriorityQueue(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
int kthLargest(vector<int> &arr, int size, int K)
{
    // return usingSorting(arr,K);
    return usingPriorityQueue(arr, K);
} 