#include <bits/stdc++.h>
/*function to check the palindrome*/
bool isPalindrome(string &s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        ++i;
        --j;
    }
    return true;
}
/*Intuition :
1.start from the zeroth index of string,start accumualating the characters,
2.If current substring is palindrome,create a partition here and
recursively check for the partition in rest of the string.

• Time Complexity : $O(N*2^N) $ where N is the length of string s.
This is the worst-case time complexity when all the possible substrings are palindrome.
There could be $2^{N}$ possible substrings in the worst case.
For each substring, it takes$ O(N)  $time to generate substring and determine if it a
palindrome or not. This gives us time complexity as $ O(N*2^N) $
• Space Complexity: $O(N),$ where N is the length of the string s.
This space will be used to store the recursion stack.
The maximum depth of the recursive call stack is N.
*/
void findPartitions(int ind, int n, string &s, vector<string> &partition,
                    vector<vector<string>> &ans)
{
    if (ind == n)
    {
        ans.push_back(partition);
        return;
    }
    string currString = "";
    for (int i = ind; i < n; ++i)
    {
        currString += s[i];
        if (isPalindrome(currString))
        {
            partition.push_back(currString);
            findPartitions(i + 1, n, s, partition, ans);
            partition.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    int n = s.length();
    vector<vector<string>> ans;
    vector<string> partition;
    findPartitions(0, n, s, partition, ans);
    return ans;
} 