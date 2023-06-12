#include <bits/stdc++.h> 
int recursion(int row,int  col)
{
	if(row == 0 && col == 0) return 1;
	int up = 0,left = 0;
	if(row >= 1)
	  up = recursion(row-1,col);
	if(col >= 1)
	  left = recursion(row,col-1);
	return up + left;
}
int memoization(int row,int col,vector<vector<int>> &dp)
{
	if(row == 0 && col == 0) return 1;
	if(dp[row][col] != -1) return dp[row][col];
	int up = 0,left = 0;
	if(row >= 1)
	  up = recursion(row-1,col);
	if(col >= 1)
	  left = recursion(row,col-1);
	return dp[row][col] = (up + left);
} 
int Tabulation(int m,int n,vector<vector<int>> &dp)
{
	dp[0][0] = 1;
	for(int i = 0; i<=m; ++i)
	{
		for(int j = 0; j<=n; ++j)
		{
			if(i == 0 && j == 0) continue;
			int up = 0,left = 0;
			if(i >= 1) up   = dp[i-1][j];
			if(j >= 1) left = dp[i][j-1];
			dp[i][j] = (up+left);
		}
	}
	return dp[m][n];
} 
int spaceOptimization(int m,int n,vector<vector<int>> &dp)
{
	vector<int> curr(n+1),prev(n+1);
	curr[0] = 1;
	for(int i = 0; i<=m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			int up = 0, left = 0;
			if (i >= 1)
				up =prev[j];
			if (j >= 1)
				left = curr[j - 1];
			curr[j] = (up + left);
		}
		prev = curr;
    }
	return curr[n];
} 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,-1));
	// return recursion(m-1,n-1);
	// return memoization(m-1,n-1,dp);
	// return Tabulation(m-1,n-1,dp);
	return spaceOptimization(m-1,n-1,dp);
}  