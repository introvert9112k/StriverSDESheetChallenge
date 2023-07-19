#include <bits/stdc++.h>
class TrieNode
{
public:
    TrieNode *referenceNodes[26];
    bool flag = false;
};
class Trie
{
public:
    TrieNode *root = new TrieNode();
    void insert(string word)
    {
        TrieNode *currNode = root;
        int n = word.length();
        for (int i = 0; i < n; ++i)
        {
            if (currNode->referenceNodes[word[i] - 'a'] == nullptr)
                currNode->referenceNodes[word[i] - 'a'] = new TrieNode();
            currNode = currNode->referenceNodes[word[i] - 'a'];
        }
        currNode->flag = true;
    }
    void findDistinctSubStrings(TrieNode *currNode, int &ans)
    {
        if (currNode == nullptr)
            return;
        if (currNode->flag == true)
            ++ans;
        for (int i = 0; i < 26; ++i)
        {
            if (root->referenceNodes[i] != nullptr)
                findDistinctSubStrings(currNode->referenceNodes[i], ans);
        }
    }
};

int trieBruteForce(string &s)
{
    Trie t;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        string subStr = "";
        for (int j = i; j < n; ++j)
        {
            subStr += s[j];
            t.insert(subStr);
        }
    }
    int ans = 0;
    t.findDistinctSubStrings(t.root, ans);
    return ans + 1;
}

int rabinKarp(string &s)
{
    int n = s.length();
    int mod = 1e9 + 7;
    unordered_set<int> set;
    for (int i = 0; i < n; ++i)
    {
        long long hashValue = 0, base = 1;
        for (int j = i; j < n; ++j)
        {
            hashValue = (hashValue % mod + ((s[j] - 'a' + 1) * base) % mod + mod) % mod;
            base = (base * 31) % mod;
            set.insert(hashValue);
        }
    }
    return set.size() + 1;
}

int countDistinctSubstrings(string &s)
{
    return rabinKarp(s);
} 