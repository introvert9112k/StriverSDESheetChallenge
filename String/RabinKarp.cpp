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
vector<int> stringMatch(string text, string pattern)
{
    int n = text.length(), m = pattern.length();
    long long patternHashValue = findHashValue(pattern, m);
    long long subStringHashValue = findHashValue(text, m);
    vector<int> ans;
    long long maxValue = 1, mod = 1e9 + 7;
    for (int i = 0; i < m; ++i)
        maxValue = (maxValue * 31) % mod;
    if (patternHashValue == subStringHashValue)
        ans.push_back(1);
    for (int i = m; i < n; ++i)
    {
        subStringHashValue = ((subStringHashValue * 31) % mod -
                              ((text[i - m] - 'a' + 1) * maxValue) % mod + (text[i] - 'a' + 1) + mod) %
                             mod;
        if (subStringHashValue == patternHashValue)
            ans.push_back(i - m + 2);
    }
    return ans;
} 