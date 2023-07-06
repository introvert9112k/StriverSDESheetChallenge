#include <bits/stdc++.h>

int atoi(string str)
{
    int num = 0;
    /*Checking for the negativity*/
    bool isNegative = (str[0] == '-');
    int n = str.length();
    for (int i = 0; i < n; ++i)
    {
        int val = (str[i] - '0');
        /*val >= 0 && val <= 9 then it is digit*/
        if (val >= 0 && val <= 9)
            num = num * 10 + (str[i] - '0');
    }
    return isNegative ? -1 * num : num;
} 