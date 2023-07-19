#include <bits/stdc++.h>
void mergeTwoSortedArrays(vector<int> &arr, int low, int mid, int high)
{
    int len = high - low + 1;
    vector<int> sortedArray(len);
    for (int i = low, j = mid + 1, k = 0; i <= mid || j <= high;)
    {
        if (i <= mid && j <= high)
            sortedArray[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        else if (i <= mid)
            sortedArray[k++] = arr[i++];
        else
            sortedArray[k++] = arr[j++];
    }
    for (int k = 0; k < len; ++k)
        arr[low + k] = sortedArray[k];
}
int countReversePairs(vector<int> &arr, int low, int mid, int high)
{
    int pairs = 0, right = mid + 1;
    for (int i = low; i <= mid; ++i)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            ++right;
        pairs += (right - (mid + 1));
    }
    return pairs;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countReversePairs(arr, low, mid, high);
        mergeTwoSortedArrays(arr, low, mid, high);
    }
    return cnt;
}
int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
} 