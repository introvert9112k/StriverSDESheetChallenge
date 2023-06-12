#include <bits/stdc++.h> 
/*
Intution : 
let substr[l,r] is the current substring which is substring without 
repeating characters.
Intially l is set to zero,and r is running from [0,n].
We keep track of the last index where characters from [a-z] appears.
Now suppose map[ch] != -1,that is this character visited before,now we 
need to check whether the duplicate character is part of our substring [l,r].

let ind be the last time where ch occurs.
suppose if ind >= l,that mean the duplicate is in our currstring.So if
we add the current charaacter i.e s[r],then we are adding duplicate,
so if we move the left pointer beyond the ind then we can remove the duplicate.
so now l becomes ind + 1.
if ind is < l that mean this character is not part of string which is our
concern so do nothing.
Each time update the last index where the character occurs.

TC : O(n)
Sc : O(1) 
*/
int approach1(string &s)
{
    int j = 0,maxlen = 1,n = s.length();
    vector<int> map(26,-1);
    for(int i = 0; i<n; ++i)
    {
       int ind = map[s[i]-'a'];
       if(ind >= j) j = ind+1;
       map[s[i]-'a'] = i;
       maxlen = max(maxlen,i-j+1);
    }
    return maxlen;
}
int uniqueSubstrings(string input)
{
    //Write your code here
    return approach1(input);
} 