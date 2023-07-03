#include <bits/stdc++.h>
bool isPossibleToFinish(int days, int chapters, vector<int> &time,
                        long long readTime)
{
    long long timeLeft = readTime, daysRequired = 0;
    int i = 0;
    while (i < chapters)
    {
        if (time[i] > timeLeft)
        {
            timeLeft = readTime;
            ++daysRequired;
        }
        else
        {
            timeLeft -= time[i];
            ++i;
        }
    }
    if (timeLeft != readTime)
        ++daysRequired;
    return daysRequired <= days;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long totalTime = 0;
    int maxTime = 0;
    for (auto t : time)
    {
        totalTime += t;
        maxTime = max(maxTime, t);
    }
    long long low = maxTime, high = totalTime;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        isPossibleToFinish(n, m, time, mid) ? high = mid - 1 : low = mid + 1;
    }
    return low;
} 