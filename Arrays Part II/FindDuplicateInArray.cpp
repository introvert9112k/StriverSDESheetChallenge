#include <bits/stdc++.h>
/*
1.Given that all the values in array are in range [1,N-1]
2.So for the current value mark the value at the index equal to current
value to -ve,indicating that the value is found.
3.If for any of the value if the index is already marked that mean it is
the duplicate element,so return that value.

   Time Complexity   -- O(N)
   Space Complexity -- O(1) 
*/
int arrayMasking(vector<int> &arr,int n)
{
	for(int i = 0; i<n; ++i)
	{
		int ind = abs(arr[i]);
		if(arr[ind] < 0) return abs(arr[i]);
		arr[ind] = -1*arr[ind];
	}
	return 0;
}
int frequencyApproach(vector<int> &arr,int n)
{
	unordered_map<int,int> freqMap;
	for(auto val : arr)
	{
       ++freqMap[val];
	   if(freqMap[val] > 1) return val;
	}
	return 0;
}
int findDuplicate(vector<int> &arr, int n){
	// return arrayMasking(arr,n);
	return frequencyApproach(arr,n);
} 
