vector<int> nextGreater(vector<int> &arr, int n)
{
    stack<int> st;
    1 st.push(arr[n - 1]);
    vector<int> ans(n);
    ans[n - 1] = -1;
    for (int i = n - 2; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
} 