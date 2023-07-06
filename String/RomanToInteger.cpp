/*
Intuition :
IV - 4
IX - 9
XL - 40
XC - 90
CD - 400
CM - 900
start iterating from the start of the string.
Whenever we encounter the string 'I','X','C' there may be possiblity for the above
mentioned numbers.
Check for the numbers add the corresponding vlaues else just add the roman value.
For the reset of the romans V,D,L and M just add the values.

Time Complexity  : O(|s|)
Space Complexity : O(1)
*/
int approach1(string s)
{
    int n = s.length();
    int num = 0, i = 0;
    while (i < n)
    {
        if (s[i] == 'I')
        {
            if (i + 1 < n && s[i + 1] == 'V')
                num += 4, i += 2;
            else if (i + 1 < n && s[i + 1] == 'X')
                num += 9, i += 2;
            else
                num += 1, ++i;
        }
        else if (s[i] == 'X')
        {
            if (i + 1 < n && s[i + 1] == 'L')
                num += 40, i += 2;
            else if (i + 1 < n && s[i + 1] == 'C')
                num += 90, i += 2;
            else
                num += 10, ++i;
        }
        else if (s[i] == 'C')
        {
            if (i + 1 < n && s[i + 1] == 'D')
                num += 400, i += 2;
            else if (i + 1 < n && s[i + 1] == 'M')
                num += 900, i += 2;
            else
                num += 100, ++i;
        }
        else if (s[i] == 'V')
            num += 5, ++i;
        else if (s[i] == 'L')
            num += 50, ++i;
        else if (s[i] == 'D')
            num += 500, ++i;
        else
            num += 1000, ++i;
    }
    return num;
}
/*
 */

#include <unordered_map>
int approach2(string s)
{
    int count = 0;
    // To store previous char value.
    int preInt = 0;
    // Unordered map for finding interger value for roman numerals.
    unordered_map<char, int> conv =
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};
    // Loop from end to start of the string.
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];
        // Store current char integer value.
        int curInt = conv[ch];
        /*
            If current value is greater or equal to previous value then increment count i.e., II means 1+1
            else in case of IV, V = 5 and I = 1 here 1 < 5 then else part will execute and update count as 5 - 1 = 4.
        */
        if (curInt >= preInt)
        {
            count += curInt;
        }
        else
        {
            count -= curInt;
        }
        // Update 'preInt' value with current value for next iteration.
        preInt = curInt;
    }
    return count;
}
int romanToInt(string s)
{
    return approach2(s);
} 