#include <bits/stdc++.h>
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long>> ans;
    ans.push_back({1});
    for(int i = 1; i<n; ++i)
    {
      vector<long long> temp(i+1);
      temp[0] = 1;
      temp[i] = 1;
      for(int j = 1; j < i; ++j)
        temp[j] = (1LL*ans[i-1][j] + 1LL*ans[i-1][j-1]);
      ans.push_back(temp);
    }
    return ans;
}
 