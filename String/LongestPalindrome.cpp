string approach1(string &str)
{
    auto isPalindrome = [&](string &currSubString)
    {
        int n = currSubString.length();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (currSubString[i] != currSubString[j])
                return false;
            ++i;
            --j;
        }
        return true;
    };
    string largestPalindrome = "";
    int n = str.length();
    for (int i = 0; i < n; ++i)
    {
        string currSubString = "";
        for (int j = i; j < n; ++j)
        {
            currSubString += str[j];
            if (currSubString.length() > largestPalindrome.length() &&
                isPalindrome(currSubString))
                largestPalindrome = currSubString;
        }
    }
    return largestPalindrome;
}
string longestPalinSubstring(string str)
{
    return approach1(str);
} 