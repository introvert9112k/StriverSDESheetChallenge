#include <bits/stdc++.h>
/*
Intuition :
1.Merge the two sorted arrays into one and return the kth element.

Time Complexity  : O(m+n)
Space Complexity : O(m+n)
space for the merged array.
*/
int mergeTwoSortedArrays1(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    vector<int> arr(n + m);
    int i = 0, j = 0, p = 0;
    while (i < m || j < n)
    {
        if (i < m && j < n)
            arr[p++] = a[i] <= b[j] ? a[i++] : b[j++];
        else
            arr[p++] = i < m ? a[i++] : b[j++];
    }
    return arr[k - 1];
}
/*
Intuiton :
1.We are only concerned about the kth element.
2.We can keep track of the value which would be our kth element,when we found the
value we can return from there.

Time Complexiy : O(n+m)
Space Complexity : O(1)
*/
int mergeTwoSortedArrays2(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    int i = 0, j = 0;
    int value = -1;
    while (i < m || j < n)
    {
        if (i < m && j < n)
            value = a[i] <= b[j] ? a[i++] : b[j++];
        else
            value = i < m ? a[i++] : b[j++];
        --k;
        if (k == 0)
            return value;
    }
    return value;
}
/*
use the maxHeap to find out the kth smallest element.

Time complexity : O((m+n)logk)
Space Complexity : O(k)
*/
int usingPriorityQueue(vector<int> &a, vector<int> &b, int k)
{
    priority_queue<int> pq;
    for (auto val : a)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
    }
    for (auto val : b)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
int usingBinarySearch(vector<int> &a, vector<int> &b, int k)
{
    /*always apply binary search on the minimum length array.
    If first array is not minimum then swap the arrays.*/
    if (b.size() < a.size())
        return usingBinarySearch(b, a, k);
    /*
    n1 - length of the smaller array.
    n2 - length of the larger array.
    */
    int n1 = a.size(), n2 = b.size();
    /*
     Our intuition is to partition the arrays in such way that the left half
     has size equal to k and right half has rest of the length.
     There are some edge cases here :
     case 1 : k > n1. i.e k is greater than the size of the minimum array.
     At max smaller array can contribute n1 elements to the left Half.
     So partition can be made until n1,only so high should be
     high = max(n1,k)

     case 2 : k > n2. i.e k is > the larger array
     so pick all the elements from larger array,still we don't get the k elements
     in left Half, compulsarly some elements should be picked from the left half.
     In that case low != 0, we cannot pick 0 elements from smaller array.
     Compulsarly we should pick remaing elements k-n2,from smaller array.
     So low should be low = max(0,k-n2);
    */
    int low = max(0, k - n2), high = min(n1, k);
    while (low <= high)
    {
        int partitionA = (low + high) >> 1;
        int partitionB = k - partitionA;
        int maxLeftA = partitionA == 0 ? INT_MIN : a[partitionA - 1];
        int maxLeftB = partitionB == 0 ? INT_MIN : b[partitionB - 1];
        int minRightA = partitionA == n1 ? INT_MAX : a[partitionA];
        int minRightB = partitionB == n2 ? INT_MAX : b[partitionB];
        /*It is a valid partition,so the left Half has k elements.
        So last element in the left half is the kth smallest.*/
        if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            return max(maxLeftA, maxLeftB);
        else if (maxLeftA > minRightB)
            high = partitionA - 1;
        else
            low = partitionA + 1;
    }
    return 0;
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    //    return mergeTwoSortedArrays2(row1,row2,m,n,k);
    // return usingPriorityQueue(row1,row2,k);
    return usingBinarySearch(row1, row2, k);
}  