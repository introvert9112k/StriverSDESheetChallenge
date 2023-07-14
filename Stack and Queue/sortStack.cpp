#include <bits/stdc++.h>
void sortTheStack(stack<int> &st, multiset<int> &set)
{
    if (st.empty())
        return;
    int val = st.top();
    st.pop();
    set.insert(val);
    sortTheStack(st, set);
    st.push(*set.begin());
    set.erase(set.begin());
}
void sortStack(stack<int> &stack)
{
    multiset<int> set;
    sortTheStack(stack, set);
} 