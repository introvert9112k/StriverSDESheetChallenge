#include <bits/stdc++.h>

int recursion(int ind, int prevInd, int n, int arr[])
{
    if (ind == n)
        return 0;
    int len = 0;
    len = recursion(ind + 1, prevInd, n, arr);
    if (prevInd == -1 || arr[ind] > arr[prevInd])
        len = max(len, 1 + recursion(ind + 1, ind, n, arr));
    return len;
}
int memoization(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    int len = 0;
    if (dp[ind][prevInd + 1] != -1)
        return dp[ind][prevInd + 1];
    len = memoization(ind + 1, prevInd, n, arr, dp);
    if (prevInd == -1 || arr[ind] > arr[prevInd])
        len = max(len, 1 + memoization(ind + 1, ind, n, arr, dp));
    return dp[ind][prevInd + 1] = len;
}
int Tabulation(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; --ind)
    {
        for (int prevInd = ind - 1; prevInd >= -1; --prevInd)
        {
            int len = 0;
            len = dp[ind + 1][prevInd + 1];
            if (prevInd == -1 || arr[ind] > arr[prevInd])
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            dp[ind][prevInd + 1] = len;
        }
    }
    return dp[0][0];
}

int spaceOptimization(int arr[], int n)
{
    vector<int> curr(n + 1, 0), next(n + 1, 0);
    for (int ind = n - 1; ind >= 0; --ind)
    {
        for (int prevInd = ind - 1; prevInd >= -1; --prevInd)
        {
            int len = 0;
            len = next[prevInd + 1];
            if (prevInd == -1 || arr[ind] > arr[prevInd])
                len = max(len, 1 + next[ind + 1]);
            curr[prevInd + 1] = len;
        }
        next = curr;
    }
    return curr[0];
}

int myTabulation(int arr[], int n)
{
    vector<vector<int>> dp(n + 1);
    /*At least longest increasing subsequence would be of length 1,when we take
    a single element,so intialize the maxlen with 1*/
    int maxLen = 1;
    /*dp[x] is the vector,suppose we are at the current index i,then dp[x] stores
    the longest increasing subsequence possible starting from the x.*/
    for (int i = 0; i < n; ++i)
    {
        /*We are starting the new subsequence with current index as start*/
        dp[i].push_back(arr[i]);
        /*for the dp[x] such that x < i, check whether current element can be
        included in those subsequences,if yes add the current value to that subsequences
        and find the maxLen among them.*/
        for (int j = 0; j < i; ++j)
        {
            /*Adding the current Value to the existing subsequnce at dp[j]*/
            if (dp[j].back() < arr[i])
            {
                dp[j].push_back(arr[i]);
                int subsequenceLen = dp[j].size();
                maxLen = max(maxLen, subsequenceLen);
            }
        }
    }
    return maxLen;
}

int tabulationAlgorthim(int arr[], int n)
{
    vector<int> dp(n + 1, 1);
    int maxLIS = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxLIS = max(maxLIS, dp[i]);
    }
    return maxLIS;
}

int binarySearchAlgo(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; ++i)
    {
        if (temp.back() < arr[i])
            temp.push_back(arr[i]), ++len;
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}

int longestIncreasingSubsequenceOptimal(int arr[], int n)
{
    int dp[n]; // dp[i] represents i+1'th length LIS ending at minimum integer dp[i]
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        /*
            Since dp array stores elements in the sorted order therefore
            we can use binary search to find the correct position for
            arr[i] to be placed.
            And elements are present in the dp array from 0 to ans-1 position
            So we will be doing the binary search in this range.
        */
        int position = lower_bound(dp, dp + ans, arr[i]) - dp;
        dp[position] = arr[i];

        if (position == ans)
        {
            ans++;
        }
    }

    return ans;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return recursion(0,-1,n,arr);
    // return memoization(0,-1,n,arr,dp);
    // return Tabulation(arr, n);
    // return spaceOptimization(arr, n);
    // return tabulationAlgorthim(arr, n);
    return longestIncreasingSubsequenceOptimal(arr, n);
} 