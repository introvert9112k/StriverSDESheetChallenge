#include <bits/stdc++.h>
class TrieNode
{
public:
    TrieNode *referenceNodes[26];
    int endsWithCount = 0;
    int prefixCount = 0;
    bool isContainsKey(char ch)
    {
        return referenceNodes[ch - 'a'] != nullptr;
    }
    TrieNode *getReferenceNode(char ch)
    {
        return referenceNodes[ch - 'a'];
    }
    void putChar(char ch, TrieNode *node)
    {
        referenceNodes[ch - 'a'] = node;
    }
    void incrementPrefix()
    {
        ++prefixCount;
    }
    void incrementEnd()
    {
        ++endsWithCount;
    }
    int getPrefixCount()
    {
        return prefixCount;
    }
    int getEndsCount()
    {
        return endsWithCount;
    }
    void decrementPrefix()
    {
        --prefixCount;
    }
    void decrementEnd()
    {
        --endsWithCount;
    }
};
class Trie
{

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /*Insert the char into trie if doesn't exists,if exists move to reference node.
    If char exists or doesn't exists increment its prefix count.
    When the end is reached increment the endsCount*/
    void insert(string &word)
    {
        TrieNode *currNode = root;
        int n = word.length();
        for (int i = 0; i < n; ++i)
        {
            /*If doesn't contains the char,then put the char into trie.*/
            if (!currNode->isContainsKey(word[i]))
                currNode->putChar(word[i], new TrieNode());
            currNode = currNode->getReferenceNode(word[i]);
            /*Note that the prefix count of reference node is increment for
            the current char*/
            currNode->incrementPrefix();
        }
        /*incrementing the endsWith count*/
        currNode->incrementEnd();
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *currNode = root;
        int n = word.length();
        for (int i = 0; i < n; ++i)
        {
            /*If doesn't contains the char,then word is not in trie
            so return 0.*/
            if (!currNode->isContainsKey(word[i]))
                return 0;
            /*moving to reference node*/
            else
                currNode = currNode->getReferenceNode(word[i]);
        }
        /*endsWithCount stores the count of Words equal to given string.*/
        return currNode->getEndsCount();
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *currNode = root;
        int n = word.length();
        for (int i = 0; i < n; ++i)
        {
            /*If doesn't contains the char,then prefix is not in trie
            so return 0.*/
            if (!currNode->isContainsKey(word[i]))
                return 0;
            /*moving to reference node*/
            else
                currNode = currNode->getReferenceNode(word[i]);
        }
        /*prefixCount stores the count of Words starts with given prefix.*/
        return currNode->getPrefixCount();
    }

    void erase(string &word)
    {
        TrieNode *currNode = root;
        int n = word.length();
        for (int i = 0; i < n; ++i)
        {
            currNode = currNode->getReferenceNode(word[i]);
            currNode->decrementPrefix();
        }
        currNode->decrementEnd();
    }
}; 