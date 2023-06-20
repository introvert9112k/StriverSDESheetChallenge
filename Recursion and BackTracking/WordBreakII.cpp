#include <bits/stdc++.h>
void findSentences(int ind, int n, string &s, string sentence, unordered_set<string> &set,
                   vector<string> &ans)
{
    if (ind == n)
    {
        ans.push_back(sentence);
        return;
    }
    string currString = "";
    for (int i = ind; i < n; ++i)
    {
        currString += s[i];
        if (set.find(currString) != set.end())
            findSentences(i + 1, n, s, sentence + currString + " ", set, ans);
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> set;
    int n = s.length();
    for (auto &word : dictionary)
        set.insert(word);
    vector<string> ans;
    findSentences(0, n, s, "", set, ans);
    return ans;
} 