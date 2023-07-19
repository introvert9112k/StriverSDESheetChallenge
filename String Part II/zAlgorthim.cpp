long long findHashValue(string &str, int m)
{
    int mod = 1e9 + 7;
    long long hashValue = 0, base = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        hashValue = (hashValue + base * (str[i] - 'a' + 1)) % mod;
        base = (base * 31) % mod;
    }
    return hashValue;
}
int zAlgorithm(string text, string pattern, int n, int m)
{
    long long patternHashValue = findHashValue(pattern, m);
    long long subStringHashValue = findHashValue(text, m);
    int ans = 0;
    long long maxValue = 1, mod = 1e9 + 7;
    for (int i = 0; i < m; ++i)
        maxValue = (maxValue * 31) % mod;
    if (patternHashValue == subStringHashValue)
        ++ans;
    for (int i = m; i < n; ++i)
    {
        subStringHashValue = ((subStringHashValue * 31) % mod -
                              ((text[i - m] - 'a' + 1) * maxValue) % mod + (text[i] - 'a' + 1) + mod) %
                             mod;
        if (subStringHashValue == patternHashValue)
            ++ans;
    }
    return ans;
} 