#include <bits/stdc++.h> 
int recursion(int m,int n,vector<vector<int>> &grid)
{
    if(m == 0 && n == 0) return grid[0][0];
    int up = INT_MAX,left = INT_MAX;
    if(m-1 >= 0)
       up = grid[m][n] + recursion(m-1,n,grid);
    if(n-1 >= 0)
       left = grid[m][n] + recursion(m,n-1,grid);
    return min(up,left);
}
int memoization(int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(m == 0 && n == 0) return grid[0][0];
    if(dp[m][n] != -1) return dp[m][n];
    int up = INT_MAX,left = INT_MAX;
    if(m-1 >= 0)
       up = grid[m][n] + memoization(m-1,n,grid,dp);
    if(n-1 >= 0)
       left = grid[m][n] + memoization(m,n-1,grid,dp);
    return dp[m][n] = min(up,left);
}
int Tabulation(vector<vector<int>> &grid)
{    
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0] = grid[0][0];
    for(int i = 0; i<m; ++i)
    {
        for(int j =0; j<n; ++j)
        {
            if(i == 0 && j == 0) continue;
            int up = INT_MAX,left = INT_MAX;
            if(i-1 >= 0)
              up = grid[i][j] + dp[i-1][j];
            if(j-1 >= 0)
              left = grid[i][j] + dp[i][j-1];
            dp[i][j] = min(up,left);
        }
    }
    return dp[m-1][n-1];
} 
int spaceOptimization(vector<vector<int>> &grid)
{    
    int m = grid.size(),n = grid[0].size();
    vector<int> prev(n),curr(n);
    curr[0] = grid[0][0];
    for(int i = 0; i<m; ++i)
    {
        for(int j =0; j<n; ++j)
        {
            if(i == 0 && j == 0) continue;
            int up = INT_MAX,left = INT_MAX;
            if(i-1 >= 0)
              up = grid[i][j] + prev[j];
            if(j-1 >= 0)
              left = grid[i][j] + curr[j-1];
            curr[j] = min(up,left);
        }
        prev = curr;
    }
    return prev[n-1];
} 
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    // return recursion(m-1,n-1,grid);
    // return memoization(m-1,n-1,grid,dp);
    // return Tabulation(grid);
    return spaceOptimization(grid);
}  