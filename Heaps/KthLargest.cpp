#include <bits/stdc++.h>
/*
sort the arr and return kth largest and smallest
TC : O(nlogn)
SC : O(1)
*/
vector<int> sorting(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
}
/*
Use the minHeap and maxHeap to find out the kth largest and smallest
TC : O(2nlogk)
Sc : O(2k)
*/
vector<int> usingPriorityQueue(vector<int> &arr, int n, int k)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; ++i)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    return {maxHeap.top(), minHeap.top()};
}
/*partition algorthim*/
int partitionArray(vector<int> &arr, int low, int high)
{
    int i = low, j = high;
    int pivot = arr[low];
    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
            ++i;
        while (j >= i && arr[j] > pivot)
            --j;
        if (i <= j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}
int findKthSmallest(int low, int high, int k, vector<int> &arr)
{
    while (low <= high)
    {
        int pivotIndex = partitionArray(arr, low, high);
        if (pivotIndex + 1 == k)
            return arr[pivotIndex];
        pivotIndex < k ? low = pivotIndex + 1 : high = pivotIndex - 1;
    }
}
vector<int> usingQuickSelect(vector<int> &arr, int n, int k)
{
    int kthSmallest = findKthSmallest(0, n - 1, k, arr);
    /*kth largest is n-k+1 smallest element.*/
    int kthLargest = findKthSmallest(0, n - 1, n - k + 1, arr);
    return {kthSmallest, kthLargest};
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // return sorting(arr,n,k);
    // return usingPriorityQueue(arr,n,k);
    return usingQuickSelect(arr, n, k);
} 