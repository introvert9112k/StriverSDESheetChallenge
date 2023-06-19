#include <bits/stdc++.h>
/*
Intuition :
1.Suppose we are at index i,let this is the last index of the consecutive
ones,find out the j (j <= i) such that no of zeros between the subarray
arr[i,j] <= k.
2.j should be as left as possible to get the maximum consecutive sequence.
3.We can use hashMap to find out the j for given i.
4.In hashMap keys are the no of zeros and values are the first index where
the zeros count occurs.
ex : let map[1] = 3. this mean the subarray a[0,3] contains 1 zero and all
the subarray start from 0 i.e a[0,0] a[0,1] a[0,2] has less than 1 zero.
5.Suppose at the given index i, let number of zeros in subarray a[0,i]
be "zerosCount",if zerosCount <= k then subarray can be chosen,
if zerosCount >= k,then find out the index of (zerosCount-k) in map.
6.let map[zerosCount - k] = j then subarray a[j+1,i] is valid subarray in which
the zeros are <= k.
7.Take maximum consecutive sequence among them.

TC : O(n)
SC : O(n)
*/
int usingMap(vector<int> &arr, int n, int k)
{
    /*To store the location of zeros Count*/
    unordered_map<int, int> map;
    map[0] = -1;
    int zerosCountTillNow = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
            zerosCountTillNow++;
        /*Don't update the map if key is duplicated,because we want the
        maximum consecutive seqeunce*/
        if (map.find(zerosCountTillNow) == map.end())
            map[zerosCountTillNow] = i;
        int zerosRequired = (zerosCountTillNow - k);
        if (zerosRequired < 0)
            zerosRequired = 0;
        ans = max(ans, i - map[zerosRequired]);
    }
    return ans;
}
/*
Intution :
1.Extend the window until the zeros in the current window is <= k.
2.If zeroscount > k then shrink the window until zeroscount <= k.
3.Take maximum among the valid windows.

TC : O(2n)
SC : O(1)
*/
int slidingWindow(vector<int> &arr, int n, int k)
{
    int i = 0, zerosCount = 0;
    int ans = 0;
    for (int j = 0; j < n; ++j)
    {
        if (arr[j] == 0)
            ++zerosCount;
        while (i <= j && zerosCount > k)
        {
            if (arr[i] == 0)
                --zerosCount;
            ++i;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}
/*
The idea is to iterate the whole array and push the indices having value
as zero of the subarray considered in a queue.
Keep on iterating the array until the size of the queue is less than ‘K’.
When the size of the queue becomes equal to ‘K’, update the starting
index of the subarray under consideration and pop an element from
the queue and push the value of current index in the queue.
Check at every step for maximum size.
*/
int usingQueue(vector<int> &arr, int n, int k)
{
    // Starting index of array under consideration.
    int l = 0;
    int max_len = 0;
    queue<int> q;
    // i decides current ending point, i.e. the right pointer.
    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
            q.push(r);
        // Updating queue when its size becomes greater than k.
        if (q.size() > k)
        {
            // Updating starting index of array under consideration.
            l = q.front() + 1;
            q.pop();
        }
        max_len = max(max_len, r - l + 1);
    }
    return max_len;
}
int longestSubSeg(vector<int> &arr, int n, int k)
{

    return usingQueue(arr, n, k);
    // return slidingWindow(arr,n,k);
    return usingMap(arr, n, k);
} 
