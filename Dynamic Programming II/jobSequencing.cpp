#include <bits/stdc++.h>
/*
Intuition :
1.sort the jobs based on the maxProfit.
2.Try to do the jobs on the day as last as possible because the remaining days would
be available for the rest of the jobs to do.

TC : O(nlogn + n*n)
nlogn -- for sorting based on profit.
n*n -- For finding the maximum Profit
SC : O(max(deadlines))
space for the deadlines array.
*/
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    /*sort the jobs based on the profit*/
    sort(jobs.begin(), jobs.end(), [&](vector<int> &v1, vector<int> &v2)
         { return v1[1] > v2[1]; });
    /*Finding out the maxDeadline*/
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i)
        maxDeadline = max(maxDeadline, jobs[i][0]);
    /*Intially no job is done,so all deadlines are set to -1*/
    vector<int> deadlines(maxDeadline + 1, -1);
    int maxProfit = 0;
    /*Iterate from the last possible deadline of the job,peform the
    job on the deadline which is available*/
    for (int i = 0; i < n; ++i)
    {
        for (int j = jobs[i][0]; j > 0; --j)
        {
            if (deadlines[j] == -1)
            {
                deadlines[j] = i;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }
    return maxProfit;
} 