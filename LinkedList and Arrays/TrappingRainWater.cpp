#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{

    // Base case.
    if (n == 0)
    {
        return 0;
    }

    // Result.
    long totalWaterStored = 0L;

    // Storing leftMax and rightMAx.
    vector<long> leftMax(n), rightMax(n);

    leftMax[0] = arr[0];

    // Filling leftMax.
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    rightMax[n - 1] = arr[n - 1];

    // Filling rightMax.
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }

    // Calculate result.
    for (int i = 1; i < n - 1; i++)
    {
        totalWaterStored += min(rightMax[i], leftMax[i]) - arr[i];
    }
    return totalWaterStored;
} 