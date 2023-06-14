#include <bits/stdc++.h>
/*
There can be three variations of the question.
1.Given row and column print the value at the row and column
2.Given a row print all the values in that row.
3.Print the actual pascal traingle.
We will see one by one.
*/

/*Variation 1 :
Given a row r and column c,the value at that place is given by formula (n-1)C(r-1).
we know that the formula for nCr is n!/(r!*(n-r)!).If we observe carefully sum part
of the numerator is got cancelled by some part in denominator.
If we observe max(r,n-r) part is cancelled in numerator and min(r,n-r) remains in
denominator.
Hence we can calculate the nCr value.

TC : O(min(r,n-r))
SC : O(1)
*/
long long findCombinations(int n, int r)
{
  long long res = 1;
  for (int i = n; i > max(r, n - r); --i)
  {
    res *= i;
    res /= (n - i + 1);
  }
  return res;
}

/*
Variant 2 : Given a row find the all values in that row.
Brute force is to using the formula (n-1)C(r-1) we can calculate all the values.
But Time Complexity : O(n*(max(min(r,n-r))))
By observing how the current value is dependent on the previous calculated value,
we can easily calculate the current value using the previous value.

TC : O(N)
SC : O(1)
*/
vector<long long> generateRow(int n)
{
  vector<long long> temp(n);
  temp[0] = 1;
  int res = 1;
  for (int i = 1; i < n; ++i)
  {
    res *= (n - i); /*To calculate the current vlaue,mulitply (n-i) to numerator*/
    res /= i;       /*Divide i on denominator*/
    temp[i] = res;
  }
  return temp;
}

/*
Variation 3 :
We need to generate the whole pascal traingle.
Approach 1 :
We know how to generate all the row values for the given row number.
So iterate over the each row and using the generater Row function generate the traingle.
TC : O(n*n)
We are iterating n times,and each row genreation takes O(n) time.
SC : O(n*n)
Space for the traingle.

Approach 2 :
Just simulate the process going in the Pascal traingle.
TC : O(n*n)
We are iterating n times,and each row genreation takes O(n) time.
SC : O(n*n)
Space for the traingle.
*/
vector<vector<long long int>> printPascal(int n)
{
  vector<vector<long long>> ans;
  ans.push_back({1});
  for (int i = 1; i < n; ++i)
  {
    vector<long long> temp(i + 1);
    temp[0] = 1;
    temp[i] = 1;
    for (int j = 1; j < i; ++j)
      temp[j] = (1LL * ans[i - 1][j] + 1LL * ans[i - 1][j - 1]);
    ans.push_back(temp);
  }
  return ans;
}
