vector<int> buildLPSArray(string &p)
{
    int m = p.length();
    /*Declaring the LPS array of length equal to string length*/
    vector<int> lps(m);
    /*making lps[0] = 0*/
    lps[0] = 0;
    int i = 1; /*start from the 1st character*/
    int len = 0;
    /*len gives the lps of the string str[0,i-1]
    i.e len = lps[i-1]*/
    while (i < m)
    {
        /*IF p[i] == p[len]
        we are already know that lps[i-1] = len.
        i.e str[0,len-1] == str[i-len,i-1]
        if p[i] == p[len]
        that mean str[0,len] == str[i-len,i]
        so lps[i] = lps[i-1] + 1*/
        if (p[i] == p[len])
        {
            ++len;        /*lps[i-1] = len and len+1 = lps[i-1] + 1*/
            lps[i] = len; /*lps[i-1] + 1 = lps[i]*/
            ++i;          /*incrementing the i*/
        }
        else
        {
            /*if p[i] != p[len]
            then we can say that lps[i] != lps[i-1]+1
            Now we reduce the longest common prefix by 1 recursively and
            check whether it can form lps or not.*/
            if (len != 0)
                len = lps[len - 1];
            /*IF len is 0*/
            else
            {
                lps[i] = 0;
                ++i;
            }
        }
    }
}
vector<int> KMP(string &s, string &p)
{
    int n = s.length(), m = p.lenght();
    vector<int> lps = buildLPSArray(p); /*LPS of the pattern is calculated*/
    int i = 0, j = 0;                   /*For iterating over the strings*/
    while (i < n)
    {
        /*if both characters are equal,increment i and j*/
        if (s[i] == p[j])
        {
            ++i;
            ++j;
            /*if j reaches m we found a occurence*/
            if (j == m)
            {
                /*Printing the start index of the pattern*/
                cout << (i - m) << endl;
                j = lps[j - 1] /*resetting j*/
            }
        }
        else
        {
            /*If j is 0,just increment i*/
            if (j == 0)
                ++i;
            /*resetting j.
            Note that here not incrementing i here,until we found the longest
            common prefix suffix for the string s[0,i] we recursively reset the j.*/
            else
                j = lps[j - 1];
        }
    }
} 