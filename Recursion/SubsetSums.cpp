#include <bits/stdc++.h>
/*
Intuition :
1.It's just a brute force,generate all the subsets and take them into 
vector and sort to get in non decreasing order 
TC : O(2^n + 2^nlog(2^n))
2^n for generating the subsets.
2^nlogn(2^n) for sorting the subsets.
SC : O(2^n).
*/
void findSubSetSums(int ind, int sum, vector<int> &num, vector<int> &ans)
{
    if(ind == num.size())
    {
        ans.push_back(sum);
        return;
    }
    findSubSetSums(ind+1, sum + num[ind], num, ans);
    findSubSetSums(ind+1, sum, num, ans);
}
/*
Intuition : 
1.using the powerset to find out the subset sum.
Same as before. 
*/
int power(int a,int b)
{
    int result = 1;
    while(b > 0)
    {
        if(b&1)
          result = result*a;
        a = a*a;
        b = b>>1;
    }
    return result;
}
void subSetSum2(vector<int> &num,vector<int> &ans)
{
    int n = num.size();
    int pow = power(2,n);
    for(int i = 0; i<pow; ++i)
    {
        int val = i,sum = 0;
        while(val  > 0)
        {
            int rsbm = val &-val; /*finding right most bit mask*/
            int pos = log2(rsbm); /*location of the right most set bit*/
            sum+= num[pos]; /*Taking corresponding value into sum*/
            val = val-rsbm;/*unsetting the right most set bit*/
        }
        ans.push_back(sum);
    }
}
vector<int> subsetSum(vector<int> &num)
{ 
   vector<int> ans;
//    findSubSetSums(0,0,num,ans);
   subSetSum2(num,ans);
   sort(ans.begin(),ans.end());
   return ans;
}  