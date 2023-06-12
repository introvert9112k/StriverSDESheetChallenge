#include <bits/stdc++.h>
/*
Intution : 
1.Use the map to find out the which elements has frequency > n/3.
2.At max there can be 2 elements whose frequency is > n/3.
*/
vector<int> usingMap(vector<int> &arr)
{
    unordered_map<int,int> map;
    /*Intially take val1 and val2 as -1.That mean they are not found yet*/
    int val1 = -1,val2 = -1,n = arr.size();
    vector<int> ans;
    for (auto val : arr) {
      ++map[val];
      /*If frequency of val > n/3*/
      if(map[val] > n/3)
      {  
          /*If first value is not yet found,then take it.*/
          if(val1 == -1) val1 = val;
          /*The second value is not found and it should not be equal to val1
          then take it as val2.
          Because of val1 and val2 should be different,if they exists*/
          else if(val2 == -1 && val != val1) val2 = val;
      }
    }
    if(val1 != -1) ans.push_back(val1);
    if(val2 != -1) ans.push_back(val2);
    return ans;
}
/* 
   Time Complexity   -- O(N)
   Space Complexity -- O(1) 
   See the TUF article.
*/ 
vector<int> mooresVotingAlgo(vector<int> &arr)
{
    int ele1 = -1,ele2 = -1;
    int cnt1 = 0,cnt2 = 0,n = arr.size();
    for(int i = 0; i < n; ++i)
    {
        if(cnt1 == 0 && arr[i] != ele2)
        {
            ele1 = arr[i];
            cnt1++;
        }
        else if(cnt2 == 0 && arr[i] != ele1)
        {
           ele2 = arr[i];
           ++cnt2;
        }
        else if(arr[i] == ele1) ++cnt1;
        else if(arr[i] == ele2) ++cnt2;
        else --cnt1,--cnt2;
    }
    vector<int> ans;
    cnt1 = 0,cnt2 = 0;
    /*Chekcking whether the two elements we got are actually valid or not*/
    for(auto val : arr)
    {
        if(val == ele1) ++cnt1;
        else if(val == ele2) ++cnt2;
    } 
    if(cnt1 > n/3) ans.push_back(ele1);
    if(cnt2 > n/3) ans.push_back(ele2);
    return ans;
} 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
//    return usingMap(arr);
   return mooresVotingAlgo(arr);
} 