#include <bits/stdc++.h>
/*
Intuition :
1.sort the intervals based on the end time.
2.If the end time matches,sort them as they appear in input.
3.Find out the non overlapping intervals

TC : O(n + nlogn + n)
n -- Building the array
nlogn - sorting the array
n -- Finding the non overlapping intervals.
SC : O(n)
Space for the array.
*/
vector<int> sorting(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = {start[i], end[i], i + 1};
    sort(arr.begin(), arr.end(), [&](vector<int> &v1, vector<int> &v2)
         {
        if(v1[1] < v2[1]) return true;
        else if(v1[1] == v2[1]) return v1[2] < v2[2];
        else return false; });
    vector<int> ans;
    int currEnd = arr[0][1];
    ans.push_back(arr[0][2]);
    for (int i = 1; i < n; ++i)
    {
        if (currEnd < arr[i][0])
        {
            ans.push_back(arr[i][2]);
            currEnd = arr[i][1];
        }
    }
    return ans;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    return sorting(start, end);
} 