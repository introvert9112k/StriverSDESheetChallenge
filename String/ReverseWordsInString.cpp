string approach1(string &str)
{
    vector<string> words;
    int n = str.length(), i = 0;
    while (i < n)
    {
        if (str[i] == ' ')
        {
            ++i;
            continue;
        }
        else
        {
            string temp;
            while (i < n && str[i] != ' ')
            {
                temp.push_back(str[i]);
                ++i;
            }
            words.push_back(temp);
        }
    }
    string ans = "";
    for (int i = words.size() - 1; i >= 0; --i)
    {
        ans += words[i];
        ans += " ";
    }
    return ans;
}
string reverseString(string &str)
{
    return approach1(str);
} 