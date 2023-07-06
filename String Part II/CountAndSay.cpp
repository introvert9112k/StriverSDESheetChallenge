#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    string temp = "1", ans = "";
    if (n == 1)
        return "1";
    for (int i = 1; i < n; ++i)
    {
        int m = temp.length();
        for (int j = 0; j < m;)
        {
            int count = 0;
            char ch = temp[j];
            while (j < m && temp[j] == ch)
                ++count, ++j;
            ans += to_string(count);
            ans += ch;
        }
        temp = ans;
        ans = "";
    }
    return temp;
} 