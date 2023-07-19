#include <bits/stdc++.h>
long recursion(int ind, int *denominations, int value)
{
    if (value == 0)
        return 1;
    if (ind == 0)
        return value % denominations[0] == 0;
    long pick = 0, notPick = 0;
    if (denominations[ind] <= value)
        pick = recursion(ind, denominations, value - denominations[ind]);
    notPick = recursion(ind - 1, denominations, value);
    return pick + notPick;
}

long memoization(int ind, int *denominations, int value, vector<vector<long>> &dp)
{
    if (value == 0)
        return 1;
    if (ind == 0)
        return value % denominations[0] == 0;
    if (dp[ind][value] != -1)
        return dp[ind][value];
    long pick = 0, notPick = 0;
    if (denominations[ind] <= value)
        pick = memoization(ind, denominations, value - denominations[ind], dp);
    notPick = memoization(ind - 1, denominations, value, dp);
    return dp[ind][value] = (pick + notPick);
}
long Tabulation(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n + 1, vector<long>(value + 1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][0] = 1;
    for (int j = 0; j <= value; ++j)
    {
        if (j % denominations[0] == 0)
            dp[0][j] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= value; ++j)
        {
            long pick = 0, notPick = 0;
            if (denominations[i] <= j)
                pick = dp[i][j - denominations[i]];
            notPick = dp[i - 1][j];
            dp[i][j] = (pick + notPick);
        }
    }
    return dp[n - 1][value];
}

long spaceOptimization(int *denominations, int n, int value)
{
    vector<long> prev(value + 1), curr(value + 1);
    for (int j = 0; j <= value; ++j)
    {
        if (j % denominations[0] == 0)
            prev[j] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        curr[0] = 1;
        for (int j = 1; j <= value; ++j)
        {
            long pick = 0, notPick = 0;
            if (denominations[i] <= j)
                pick = curr[j - denominations[i]];
            notPick = prev[j];
            curr[j] = (pick + notPick);
        }
        prev = curr;
    }
    return prev[value];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n + 1, vector<long>(value + 1, -1));
    // return recursion(n-1,denominations,value);
    // return memoization(n-1,denominations,value,dp);
    // return Tabulation(denominations,n,value);
    return spaceOptimization(denominations, n, value);
} 