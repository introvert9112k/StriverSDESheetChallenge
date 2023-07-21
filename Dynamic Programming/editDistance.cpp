#include<bits/stdc++.h>
/*
Intuition : 
f(i,j) tells the 
minimum steps required to match the s1[0,i] with the s2[0,j].

There will be two cases in string matching.
    1.The two characters match
    2.The two characters do not match.
    Case 1 : If two characters match,the best thing we can do move shrink the two strings.
    As we are not performing any operations,so need to add anything.
    Case 2 : When strings don't match.We have three operations 
    1.Insert 
    2.Remove
    3.Replace.

    Insert : 
        Suppose we are at the index i and j,we can insert the character in the s1.
        Suppose we insert a character at the i+1 because we are the indexes i and j,
        that mean s1[i+1,n] and s2[j+1,m] are matched. 
        So if we insert the character equal to s2[j] at i+1 index in s1,then s1[i+1]
        and s2[j] will match, so we should reduce the j,the i will still remains same.
        We are hypotheically inserting hte charcter at i+1
        So for insert 1 + f(i,j-1) is the function call 
    Remove : 
      We are indexes i and j,suppose we remove the index at i,then we should reduce
      the i and j remains the same. 
      So for the Remove 1 + f(i-1,j) is the function call.
    Replace : 
       Now suppose we replaced s1[j] with s2[j] in s1,then the two characters matched,
       so shrink both the strings. 
       For Replace 1+ f(i-1,j-1) is the function call.
    We want the minium operations,so return the which operations gives minimum value.

Base cases : 
   BS 1 : When end of s1 is reached i.e i < 0.That mean s1 is empty and s2 is not 
   empty inorder to make them equal we should insert the characters s2[0,j] infront
   of s1,so opeartions required is j+1.
   BS 2  : When end of s2 is reached i.e j < 0.That mean s2 is empty and s1 is not 
   empty inorder to make them equal we should delete the characters s1[0,j] infront
   of s1,so opeartions required is i+1.

Time Complexity : Exponentail
Space Complexity : O(n+m)
*/
int recursion(int i,int j,string &s1,string &s2)
{
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(s1[i] == s2[j]) return recursion(i-1,j-1,s1,s2);
    else
    {
        int insert =  1 + recursion(i, j - 1, s1, s2);
        int remove =  1 + recursion(i - 1, j, s1, s2);
        int replace = 1 + recursion(i - 1, j - 1, s1, s2);
        return min({insert,remove,replace});
    }
} 
int memoization(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = memoization(i-1,j-1,s1,s2,dp);
    else
    {
        int insert =  1 + memoization(i, j - 1, s1, s2,dp);
        int remove =  1 + memoization(i - 1, j, s1, s2,dp);
        int replace = 1 + memoization(i - 1, j - 1, s1, s2,dp);
        return dp[i][j] = min({insert,remove,replace});
    }
}  
/*
Memoization includes the negative indexing so we shif the coordinates to write 
tabulation.
*/
int Tabulation(int n,int m,string &s1,string &s2)
{
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));
    /*BS1 : i.e i < 0 then return j+1
    as we shif the indexes i = -1 becomes i = 0,
    When i = 0,j can be anything from -1 to m-1 so upon shifting 0 to m.
    Similarly for BS2*/
    for(int j=0; j<=m; ++j) dp[0][j] = j;
    for(int i=0; i<=n; ++i) dp[i][0] = i;
    /*
    i can vary from [0,n-1] so upon shifting [1,n]
    j can vary from [0,m-1] so upon shifting [1,m]
    */
    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1; j<=m; ++j)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else 
            {
                int insert =  1 + dp[i][j - 1];
                int remove =  1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insert,remove,replace});
            }
        }
    }
    return dp[n][m];
}
int spaceOptimization(int n,int m,string &s1,string &s2){
    
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int j=0; j<=m; ++j) prev[j] = j;
    for(int i = 1; i<=n; ++i)
    {  
        curr[0] = i;
        for(int j = 1; j<=m; ++j)
        {
            if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
            else 
            {
                int insert =  1 + curr[j - 1];
                int remove =  1 + prev[j];
                int replace = 1 + prev[j - 1];
                curr[j] = min({insert,remove,replace});
            }
        }
        prev = curr;
    }
    return curr[m];
}
int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return recursion(n-1,m-1,str1,str2);
    // return memoization(n-1,m-1,str1,str2,dp);
    // return Tabulation(n,m,str1,str2);
    return spaceOptimization(n,m,str1,str2);
}  