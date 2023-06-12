#include <bits/stdc++.h>
/* 
   Time Complexity  -- O(N)
   Space Complexity -- O(N) 
*/ 
int usingMap(int arr[],int n)
{
	unordered_map<int,int> freqMap;
	for(int i = 0; i < n; ++i)
	{
		++freqMap[arr[i]];
		if(freqMap[arr[i]] > n/2) return arr[i];
	}
	return -1;
}
/*
Given that the majority element occurs more than n/2 times
See the article : TUF article 
TC : O(N)
SC : O(1)
*/
int mooresVotingAlgorithm(int arr[],int n )
{
	int value,cnt;
	for(int i = 0; i<n; ++i)
	{
		if(cnt == 0)
		{
			value = arr[i];
			cnt = 1;
		}
		else if(arr[i] == value) ++cnt;
		else --cnt;
	}
	cnt = 0;
	for(int i = 0; i<n; ++i)
	   if(arr[i] == value) ++cnt;
	return cnt > n/2 ? value : -1;
}
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	return usingMap(arr,n);
}  