#include <bits/stdc++.h>
int bruteForce(vector<int> &arr)
{  
  int n = arr.size(),maxlen = 0;
  for(int i = 0; i<n; ++i)
  { 
      int sum = 0;
      for(int j = i; j < n; ++j)
      {
         sum += arr[j];
         if(sum == 0)
          maxlen = max(maxlen,j-i+1);
      }
  }
  return maxlen;
} 
int optimal(vector<int> &arr)
{
  int n = arr.size();
  vector<int> prefix(n+1,0);;
  for(int i = 0; i<n; ++i)
    prefix[i+1] = prefix[i] + arr[i];
  unordered_map<int,int> map;
  map[0] = 0;
  int maxlen = 0;
  for(int i = 1; i<=n; ++i)
  {
     if(map.find(prefix[i]) != map.end())
      maxlen = max(maxlen,i-map[prefix[i]]);
     else 
        map[prefix[i]] = i;
  }
  return maxlen;
} 
int LongestSubsetWithZeroSum(vector < int > arr) {
    //  return bruteForce(arr);
    return optimal(arr);
} 