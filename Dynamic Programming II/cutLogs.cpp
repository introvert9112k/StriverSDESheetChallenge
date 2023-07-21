/*
    Time Complexity: O(N ^ 1/3 + T * logN)
    Space Complexity: O(N ^ 1/3)

    Where N is capacity of log cutting stand.
*/

#include <vector>
#include <cmath>

// Create an array dp
vector<vector<int>> dp(15, vector<int>(1, 0));

void preComp()
{
    for (int i = 0; 1; i++)
    {
        int cur = dp[3][i] + (i * (i + 1)) / 2 + 1;
        dp[3].push_back(cur);

        // Check if cur is greater than 10000
        if (cur > 10000)
        {
            break;
        }
    }

    // Iterate i from 4 to 14
    for (int i = 4; i <= 14; i++)
    {
        for (int j = 0; 1; j++)
        {
            int cur = dp[i][j] + dp[i - 1][j] + 1;
            dp[i].push_back(cur);

            // Check if cur is greater than 10000
            if (cur > 10000)
            {
                break;
            }
        }
    }
}

int cutLogs(int k, int n)
{
    // Check if K is equal to 1
    if (k == 1)
    {
        return n;
    }

    // Check if K is equal to 2
    if (k == 2)
    {
        return ceil((-1.0 + sqrt(1 + 8 * n)) / 2.0);
    }

    if (dp[3].size() == 1)
    {
        preComp();
    }

    // Update K with minimum value of K and 14
    k = min(k, 14);

    // Find the lower bound
    int ans = lower_bound(dp[k].begin(), dp[k].end(), n) - dp[k].begin();
    return ans;
}
