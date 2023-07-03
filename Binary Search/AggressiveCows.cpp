bool isPossibleToPlaceCows(vector<int> &stalls, int dist, int k)
{
    int n = stalls.size();
    int lastStall = stalls[0];
    --k;
    for (int i = 1; i < n && k > 0; ++i)
    {
        if ((stalls[i] - lastStall) >= dist)
        {
            lastStall = stalls[i];
            k -= 1;
        }
    }
    return k <= 0;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int low = 0, high = 1e9;
    sort(stalls.begin(), stalls.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        isPossibleToPlaceCows(stalls, mid, k) ? low = mid + 1 : high = mid - 1;
    }
    return high;
} 