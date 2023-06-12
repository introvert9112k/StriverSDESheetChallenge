#include <bits/stdc++.h> 
/*
TC : O(N)
SC : O(1)
Neglecting the constant 26 both in time and space complexity
*/
bool optimal1(string &s1,string &s2)
{
    if(s1.length() != s2.length()) return false;
    vector<int> freq(26,0);
    for(int i = 0; i<s1.length(); ++i)
    {
        ++freq[s1[i]-'a'];
        --freq[s2[i]-'a'];
    }
    for(auto val : freq)
      if(val != 0) return false;
    return true;
}
/* 
   Time Complexity   -- O(nlogn + n)
   Space Complexity -- O(1) 
   Anagram has same characters with same frequency.So sorting brings them 
   at one place.
   After sorting compare each character one by one.
*/ 
bool optimal2(string &s1,string &s2)
{  
    if(s1.length() != s2.length()) return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for(int i = 0; i<s1.length(); ++i)
          if(s1[i] != s2[i]) return false;
    return true;
}
bool areAnagram(string &str1, string &str2){
    return optimal2(str1,str2);
} 