#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    int ans = INT_MIN;
    int prefixProduct = 1, suffixProduct = 1;
    for (int i = 0; i < n; ++i)
    {
        if (prefixProduct == 0)
            prefixProduct = 1;
        if (suffixProduct == 0)
            suffixProduct = 1;
        prefixProduct = prefixProduct * arr[i];
        suffixProduct = suffixProduct * arr[n - 1 - i];
        ans = max({ans, suffixProduct, prefixProduct});
    }
    return ans;
}
 