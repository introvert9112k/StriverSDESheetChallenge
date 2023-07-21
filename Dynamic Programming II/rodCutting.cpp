int recursion(int ind, vector<int> &price, int n)
{
    if (ind == 0)
        return n * price[0];
    int notTake = recursion(ind - 1, price, n);
    int take = INT_MIN;
    if (ind + 1 <= n)
        take = price[ind] + recursion(ind, price, n - ind - 1);
    return max(notTake, take);
}
int memoization(int ind, vector<int> &price, int n, vector<vector<int>> &dp)
{
    if (ind == 0)
        return n * price[0];
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int notTake = memoization(ind - 1, price, n, dp);
    int take = INT_MIN;
    if (ind + 1 <= n)
        take = price[ind] + memoization(ind, price, n - ind - 1, dp);
    return dp[ind][n] = max(notTake, take);
}

int Tabulation(vector<int> &price, int n)
{
    int m = price.size();
    vector<vector<int>> dp(m, vector<int>(n + 1, INT_MIN));
    for (int i = 0; i <= n; ++i)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (i + 1 <= j)
                take = price[i] + dp[i][j - i - 1];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[m - 1][n];
}

int spaceOptimization(vector<int> &price, int n)
{

    int m = price.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; ++i)
    {
        prev[i] = i * price[0];
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (i + 1 <= j)
                take = price[i] + curr[j - i - 1];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}

int cutRod(vector<int> &price, int n)
{
    int m = price.size();
    vector<vector<int>> dp(m, vector<int>(n + 1, -1));
    // return recursion(m-1,price,n);
    // return memoization(m-1,price,n,dp);
    // return Tabulation(price,n);
    return spaceOptimization(price, n);
}
