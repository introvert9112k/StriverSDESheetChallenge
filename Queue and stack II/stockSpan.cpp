#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{

    int n = price.size();
    stack<int> st;
    st.push(0);
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        ans[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return ans;
} 