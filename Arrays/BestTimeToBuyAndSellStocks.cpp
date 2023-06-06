#include <bits/stdc++.h> 
/*
Intuition : 
1.If we are on the current day and bought the stock on this day,we can only
sell after this day.
2.So intution is to find the maximum price of the stack on further days for
each current day and take the maximum among them.

Time Complexity : O(N)
Space Complexity : O(n)
*/
int maximumProfit(vector<int> &prices){
   int n = prices.size();
   vector<int> rightMax(n);
   /*rightMax[i] stores the maximum element in the range [i,n-1]*/
   rightMax[n-1] = prices[n-1];
   for(int i = n-2; i>=0; --i)
     rightMax[i] = max(rightMax[i+1],prices[i]);
   /*If prices are in descending order,then we won't get any profit by 
   buying stock on any day,so it is better to not buy anything.
   so intially maximumProfit is 0*/
   int maximumProfit = 0;
   /*For each day i,find the maximum price in days [i+1,n-1]*/
   for(int i = 0; i < n-1; ++i)
      maximumProfit = max(maximumProfit,rightMax[i+1]-prices[i]);
   return maximumProfit;
} 

#include <bits/stdc++.h> 
/*Another approach
1.Suppose if we want to sell the stock on current day,we should have 
bought the stock before,So for each current day we find the minimum stock
price earlier on which we can buy the stock to get maximum profit*/
int maximumProfit(vector<int> &prices){
    int minPriceSoFar = prices[0];
    int maximumProfit = 0,n = prices.size();
    for(int i = 1; i < n; ++i)
    {
        maximumProfit = max(maximumProfit,prices[i]-minPriceSoFar);
        minPriceSoFar = min(minPriceSoFar,prices[i]);
    }
    return maximumProfit;
} 