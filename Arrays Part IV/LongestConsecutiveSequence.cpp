#include <bits/stdc++.h>
/*
Intuition : 
Here asked for the sequence not the subsequence,so the order of the numbers
doesn't matter here only matters that they are present in the array or not.

1.First find out all the unique elements in the array.
2.We need to find the consecutive elements,so upon sorting we would get all
the consecutive elements together as there are no duplicates.
3.Find the largest consecutive sequence among them.

TC : O(nlogn)
SC : O(n) 
*/
int approach1(vector<int> &arr,int n)
{
   unordered_map<int,int> map;
   for(auto val : arr) ++map[val];
   vector<int> temp;
   for(auto it : map)
      temp.push_back(it.first);
   sort(temp.begin(),temp.end());
   int longestSequence = 1,i = 0;
   n = temp.size();
   while(i < n-1)
   {  
      int currLength = 1;
      while(i < n-1 && (temp[i] + 1 == temp[i+1])) ++currLength,++i;
      longestSequence = max(longestSequence,currLength);
      ++i;
   }
   return longestSequence;
}
/*
In the preivous approach we are using the unique array to find out all 
the unique elements,later we are finding the longest consecutive sequence.
Here we avoid the extra space.

Intution :
1.Sort the array.
2.Take arr[0] as prevMinimum and currSequence as 1.
prevMinimum states what is the minimum value observed other than the current
value in the visited array so far.
3.Suppose if the prevMinimum is equal to current value,that mean it is duplicate
we cannot add it to the sequence,if we go ahead we may find the consecutive
value so move ahead without doing nothing.
4.If prevMinimum == currVal-1,that is we can add the current value to the 
sequence,so incremeent the sequence length and now the new miniumum is 
current Value.
5.If both of the cases fails,that mean the sequence is ended.So we should
start the new sequence from here.

TC : O(nlogn)
SC : O(1) 
*/
int approach2(vector<int> &arr,int n)
{
   sort(arr.begin(),arr.end());
   int longestSequence = 1,prevMinimum = arr[0];
   int currSequence = 1;
   for(int i = 1; i<n; ++i)
   {
       if(prevMinimum == arr[i]) continue;
       else if (prevMinimum == arr[i] - 1) {
         prevMinimum = arr[i];
         ++currSequence;
       } else {
         prevMinimum = arr[i];
         longestSequence = max(currSequence, longestSequence);
         currSequence = 1;
       }
   }
   longestSequence = max(longestSequence,currSequence);
   return longestSequence;
} 
/*
In summary, the code utilizes an unordered set to efficiently store 
unique elements from the array. It iterates over the array, checking 
for the start of potential consecutive sequences, and then iterates 
further to determine the length of each consecutive sequence. 
By keeping track of the longest sequence encountered, 
it returns the length of the longest consecutive sequence in the array.


Basically we are finding the length of the consecutive sequence,for those
numbers which can be the starting of the sequence.
TC : O(N)
SC : O(N)
*/
int optimal(vector<int> &arr,int n)
{
   unordered_set<int> set;
   int longestSequence = 0,currLength = 0;
   for(auto val : arr) set.insert(val);
   for(auto val : arr)
   {  
      /*If the previous value is not in sequence,then sequence
      should start from the current value.*/
      if(set.find(val-1) == set.end()) 
      {
         int currNum = val;
         currLength = 0;
         /*Finding the length of the consecutive sequence.*/
         while(set.find(currNum) != set.end())
         {
            currNum+=1;
            currLength+=1;
         }
         longestSequence = max(longestSequence,currLength);
      }
   }
   return longestSequence;
} 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
   return optimal(arr,n);
} 