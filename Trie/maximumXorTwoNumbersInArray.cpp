#include <bits/stdc++.h>
/*Trie Node class*/
class TrieNode
{
public:
    TrieNode *referenceNodes[2];
    bool containsKey(int bit)
    {
        return referenceNodes[bit] != nullptr;
    }
    TrieNode *getReferenceNode(int bit)
    {
        return referenceNodes[bit];
    }
    void putValue(int bit, TrieNode *node)
    {
        referenceNodes[bit] = node;
    }
};
/*Trie Class*/
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(int num)
    {
        TrieNode *currNode = root;
        /*Insert the each bit of num into the trie*/
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num & (1 << i)) > 0 ? 1 : 0;
            if (!currNode->containsKey(bit))
                currNode->putValue(bit, new TrieNode());
            currNode = currNode->referenceNodes[bit];
        }
        cout << endl;
    }
    /*To get the maximum xor with the number X,
    We should find the bit with opposite parity from left to right.
    Start from the root, if there exists a bit of oppostie parity of bit of x
    then take that bit value into ans, and move to next reference node.

    If opposite bit doesn't exists, then we don't have any option we must
    take the same bit,if we take same bit xor is zero,so don't add anything
    to ans and move to next reference node.*/
    int findMax(int num)
    {
        TrieNode *currNode = root;
        int maxValue = 0;
        for (int i = 31; i >= 0; --i)
        {
            int currNumBit = (num & (1 << i)) > 0 ? 1 : 0;
            /*1-currNumBit gives the opposite bit of currBit.
            If exits add the value to the ans*/
            if (currNode->containsKey(1 - currNumBit))
            {
                maxValue = maxValue | (1 << i);
                currNode = currNode->getReferenceNode(1 - currNumBit);
            }
            else
                currNode = currNode->getReferenceNode(currNumBit);
        }
        return maxValue;
    }
};
int maximumXor(vector<int> A)
{
    Trie t;
    for (auto val : A)
        t.insert(val);
    int maxXor = 0;
    for (auto val : A)
    {
        maxXor = max(maxXor, t.findMax(val));
    }
    return maxXor;
} 