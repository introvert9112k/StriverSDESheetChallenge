class Solution {
private : 
/*
    Intuition : 
    1.Just take an extra array and fill the array using the logic of 
    merging two sorted arrays.
    2. Then copy the extra array elements into the arr1.
    TC : O(m+n)
    SC : O(m+n) 
*/
    void optimal1(vector<int> &arr1,vector<int> &arr2,int m,int n)
    {
        vector<int> temp(m+n);
        int i = 0,j = 0,ind = 0;
        for(; i < m && j < n;)
        {
            if(arr1[i] <= arr2[j])
            {
                temp[ind] = arr1[i];
                ++ind;
                ++i;
            }
            else
            {
                temp[ind] = arr2[j];
                ++ind;
                ++j;
            }
        }
        for(; i < m; ++ind,++i)
            temp[ind] = arr1[i];
        for(; j < n; ++ind,++j)
           temp[ind] = arr2[j];
        for(int i = 0; i<(n+m); ++i)
            arr1[i] = temp[i];
    } 
    /*
    Create a copy of the arr1 elements till size of m in arr1Copy
    Now apply the logic of merging two sorted arrays on arr1Copy and arr2
    Overwrite the elements in arr1.

    TC : O(n+m)
    SC : O(m) 
    */
    void optimal2(vector<int> &arr1,vector<int> &arr2,int m,int n)
    {
        vector<int> arr1Copy(m);
        for(int i = 0; i<m; ++i)
            arr1Copy[i] = arr1[i];
        int i = 0,j = 0;
        for(int ind = 0; ind < n+m; ++ind)
        {  
            if(i < m && j < n)
            arr1[ind] = (arr1Copy[i] <= arr2[j] ) ? arr1Copy[i++] :arr2[j++];
            else if(i < m) 
              arr1[ind] = arr1Copy[i++];
            else 
              arr1[ind] = arr2[j++];
        } 
    } 
    /*
    Instead of iterating from the left,start from interaing from m-1 and n-1.
    Now fill the arr1 from m+n-1 using the merging two sorted arrays logic.
    
    so i = m-1, j = n-1 and ind = m+n-1.
    i is n distance apart from the ind. So in any case ind won't cross 
    the i,so we can safely assume that the arr[ind,m+n-1] is sorted.

    By this we are utilizing the redundant space in arr1,
    TC : O(m+n)
    SC : O(1)
    */
    void optimal3(vector<int> &arr1,vector<int> &arr2,int m,int n)
    {
        int i = m-1,j = n-1;
        for(int ind = n+m-1; ind >= 0; --ind) 
        {  
            if(i >= 0 && j >= 0)
            arr1[ind] = (arr1[i] >= arr2[j] ) ? arr1[i--] :arr2[j--];
            else if(i >= 0) 
              arr1[ind] = arr1[i--];
            else 
              arr1[ind] = arr2[j--];
        } 
    } 
    
    /*
    Just copy the elements of arr2 into arr1 and sort it
    TC : O((m+n)*log(m+n))
    SC : O(1)
    */
    void bruteForce(vector<int> &arr1,vector<int> &arr2,int m,int n)
    {
        for(int i = m; i < (m+n); ++i)
        arr1[i] = arr2[i-m];
        sort(arr1.begin(),arr1.end());
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // bruteForce(nums1,nums2,m,n);
        // optimal(nums1,nums2,m,n);
        // optimal2(nums1,nums2,m,n);
        optimal3(nums1,nums2,m,n);
    }
}; 