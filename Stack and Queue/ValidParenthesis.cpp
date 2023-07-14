bool isValidParenthesis(string expression)
{
    stack<char> st;
    int n = expression.length();
    for (int i = 0; i < n; ++i)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            if (ch == ')' && st.top() != '(')
                return false;
            else if (ch == ']' && st.top() != '[')
                return false;
            else if (ch == '}' && st.top() != '{')
                return false;
            st.pop();
        }
    }
    return true;
} 