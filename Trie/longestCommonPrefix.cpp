/*
Intution :
1.Pick each character from the first string.
2.Check if the character at curr Position is same in all strings at same position,
if not return from there.
3.There may be case like common Prefix is > one of the string length,then also
return from there.

Time Complexity : O(M*n)
M -- Length of the smallest String.
N -- Number of strings
Space Complexity : O(1)
excluding the space for the ans
*/
string approach1(vector<string> &arr, int n)
{
    string commonPrefix;
    int j = 0;
    while (true)
    {
        char currChar = arr[0][j];
        for (int i = 0; i < n; ++i)
        {
            if (j >= arr[i].length())
                return commonPrefix;
            else if (arr[i][j] != currChar)
                return commonPrefix;
        }
        commonPrefix += currChar;
        ++j;
    }
    return commonPrefix;
}

/*Class for the trie node*/
class TrieNode
{
private:
    /*character array pointing to their reference nodes*/
    TrieNode *referenceNodes[26];
    /*bool flag for verfication of word's existence*/
    bool flag = false;

public:
    /*
    This takes 1 argument,the character need to search.
    If the referenceNodes[ch-'a'] != nullptr that mean there exists a reference node
    for the current char,that mean the character is present in the current trieNode.
    else current character is not present in TrieNode.
    */
    bool isContainsKey(char ch)
    {
        return referenceNodes[ch - 'a'] != nullptr;
    }
    /*This function will return the reference node of the given character*/
    TrieNode *getReferenceNode(char ch)
    {
        return referenceNodes[ch - 'a'];
    }
    /*
    This function puts the new Char in the current TrieNode,i.e by creating a
    reference Node pointer in the character location.
    */
    void putChar(char ch)
    {
        referenceNodes[ch - 'a'] = new TrieNode();
    }
    /*This will set the flag to true*/
    void setFlagToTrue()
    {
        flag = true;
    }
    /*This will return the flag value of trieNode*/
    bool getFlag()
    {
        return flag;
    }
};

class Trie
{

private:
    /*Creating root of the trie,intially it doesn't contain any characters*/
    TrieNode *root = new TrieNode();

public:
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        /*starting from the root*/
        TrieNode *currNode = root;
        int n = word.length();
        /*Iterating through the each character in word*/
        for (int i = 0; i < n; ++i)
        {
            /*if the character is not in current TrieNode,then insert the char and
            move to it's refernce node*/
            if (!currNode->isContainsKey(word[i]))
            {
                /*putting character in the current TrieNode*/
                currNode->putChar(word[i]);
            }
            /*Moving to its reference node*/
            currNode = currNode->getReferenceNode(word[i]);
        }
        /*
        Now currNode is the refernceNode of the last character.
        We reached the end of the word,so we must set the last character
        refernceNode's flag to true.*/
        currNode->setFlagToTrue();
    }
    string findLongesCommonPrefix()
    {
        TrieNode *currNode = root;
        string lcp = "";
        while (currNode->getFlag() == false)
        {
            char lastChar = ' ';
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (currNode->getReferenceNode(ch) != nullptr)
                {
                    if (lastChar != ' ')
                    {
                        lcp.pop_back();
                        return lcp;
                    }
                    lcp += ch;
                    lastChar = ch;
                }
            }
            currNode = currNode->getReferenceNode(lastChar);
        }
        return lcp;
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie t;
    for (auto str : arr)
        t.insert(str);
    return t.findLongesCommonPrefix();
} 