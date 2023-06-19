#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = {start[i], finish[i]};
    sort(arr.begin(), arr.end(), [&](vector<int> &v1, vector<int> &v2)
         {
        if(v1[1] < v2[1]) return true;
        else if(v1[1] == v2[1]) return v1[0] < v2[0];
        else return false; });
    int tasks = 1;
    int currEnd = arr[0][1];
    for (int i = 1; i < n; ++i)
    {
        if (currEnd <= arr[i][0])
        {
            currEnd = arr[i][1];
            tasks++;
        }
    }
    return tasks;
} 