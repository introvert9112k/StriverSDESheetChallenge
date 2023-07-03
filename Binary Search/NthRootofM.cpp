/*
Using binary search check for the number.
Time Complexity : O(nlogm)
binary search takes logm time,for each call we are doing O(n) operation to
check current number nth power is equal to m.
Space Complexity : O(1)
*/
int approach1(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long power = 1;
        for (int i = 1; i <= n; ++i)
        {
            power = power * mid;
            if (power > m)
                break;
        }
        if (power == m)
            return mid;
        power > m ? high = mid - 1 : low = mid + 1;
    }
    return -1;
}

/*
Use the binary search to find the ans.
To find the power of (mid)^n use the binary exponentation instead of the iteration.
In binary exponentation there may be case of overflow.Whenever the power goes
beyond the m return 0,that mean ans present in left side
if equal to m reuturn 1,i.e we found the ans.
else return 2,that mean the ans is present on right hand side

Time Complexity : o(log2(m)*(logb(a)))
log2(m) for the binary search
logb(a) for finding the a^b.
Space Complexity : O(1)
*/
int findPower(long long a, int b, int m)
{
    long long power = 1;
    while (b > 0)
    {
        if (a > m || power > m)
            return 0;
        if (b & 1)
            power = power * a;
        a = a * a;
        b = b >> 1;
    }
    return power == m ? 1 : 2;
}
int approach2(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int decision = findPower(mid, n, m);
        if (decision == 1)
            return mid;
        decision == 0 ? high = mid - 1 : low = mid + 1;
    }
    return -1;
}

int NthRoot(int n, int m)
{
    return approach2(n, m);
} 