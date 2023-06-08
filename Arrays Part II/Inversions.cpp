#include <bits/stdc++.h> 
/*
TC : O(nlogn)
SC : O(n) 
*/
long long mergeTwoSortedArrays(long long *arr,int low,int mid,int high)
{    
    long long inversions = 0;
    int len = (high-low+1);
    vector<int> temp(len);
    int i = low,j = mid+1;
    for(int ind = 0; ind<len; ++ind)
    {
        if(i <= mid && j <= high)
        {
           if(arr[i] <= arr[j])
            temp[ind] = arr[i++];
           else 
            inversions+=(mid-i+1),temp[ind] = arr[j++];
        }
        else if(i <= mid)
         temp[ind] = arr[i++];
        else 
         temp[ind] = arr[j++];
    }
    for(int ind = 0; ind < len; ++ind)
        arr[low+ind] = temp[ind];
    return inversions;
}
long long mergeSort(long long *arr,int low,int high,long long &totalInversions)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;
        // cout<<low<<" "<<high<<endl;
        mergeSort(arr,low,mid,totalInversions);
        mergeSort(arr,mid+1,high,totalInversions);
        totalInversions += mergeTwoSortedArrays(arr, low, mid, high);
    }
}
long long getInversions(long long *arr, int n){
    long long totalInversions = 0;
    mergeSort(arr,0,n-1,totalInversions);
    return totalInversions;
}  