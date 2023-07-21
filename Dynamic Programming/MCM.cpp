#include <bits/stdc++.h>
int recursion(int i, int j, vector<int> arr)
{
    /*If there is only one matrix then no multipication is needed*/
    if (i == j)
        return 0;
    int mini = 1e9;
    for (int k = i; k < j; ++k)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + recursion(i, k, arr) + recursion(k + 1, j, arr);
        mini = min(steps, mini);
    }
    return mini;
}

int memoization(int i, int j, vector<int> arr, vector<vector<int>> &dp)
{
    /*If there is only one matrix then no multipication is needed*/
    if (i == j)
        return 0;
    int mini = 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i; k < j; ++k)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + memoization(i, k, arr, dp) + memoization(k + 1, j, arr, dp);
        mini = min(steps, mini);
    }
    return dp[i][j] = mini;
}

int Tabulation(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;
    /*i running from 1 to n-1 in recursion, so it should be opposite
    here so n-1 to 1.
    j is running from n-1 to 1 it should be opposite here i.e 1 to n-1.
    but the i should be less than j, so j range is [i+1,n-1]*/
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int mini = 1e9;
            for (int k = i; k < j; ++k)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    /*recursion call is called from 1,n-1*/
    return dp[1][n - 1];
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    // return recursion(1,N-1,arr);
    // return memoization(1,N-1,arr,dp);
    return Tabulation(arr, N);
} 