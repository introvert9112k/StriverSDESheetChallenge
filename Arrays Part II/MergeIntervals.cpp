#include <bits/stdc++.h> 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{  
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> mergedIntervals;
    int n = intervals.size();
    int start = intervals[0][0],end = intervals[0][1];
    for(int i = 0; i < n; ++i)
    {
       if(intervals[i][0] <= end)
         end = max(end,intervals[i][1]);
       else 
       {
           mergedIntervals.push_back({start,end});
           start = intervals[i][0];
           end = intervals[i][1];
       }
    }
    mergedIntervals.push_back({start,end});
    return mergedIntervals;
}
