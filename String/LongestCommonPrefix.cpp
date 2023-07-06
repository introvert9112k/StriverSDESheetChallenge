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

string longestCommonPrefix(vector<string> &arr, int n)
{
    return approach1(arr, n);
}
 