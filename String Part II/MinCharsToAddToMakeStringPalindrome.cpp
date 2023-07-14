#include <bits/stdc++.h>
int minCharsforPalindrome(string str)
{
    int n = str.length();
    string r = str;
    reverse(r.begin(), r.end());
    string temp = str + "$" + r;
    int m = temp.size();
    vector<int> lps(m);
    lps[0] = 0;
    int i = 1, len = 0;
    while (i < m)
    {
        if (temp[i] == temp[len])
        {
            ++len;
            lps[i] = len;
            ++i;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return n - lps[m - 1];
}
 