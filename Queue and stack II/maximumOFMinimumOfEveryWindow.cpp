#include <bits/stdc++.h> 
vector<int> findPreviousSmaller(vector<int> &a,int n)
{
    stack<int> st;
    vector<int> previousSmaller(n);
    for(int i = 0; i<n; ++i)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        previousSmaller[i] = st.empty() ? -1 :  st.top();
        st.push(i);
    }
    return previousSmaller;
} 
vector<int> findNextSmaller(vector<int> &a,int n)
{
    stack<int> st;
    vector<int> nextSmaller(n);
    for(int i = n-1; i >= 0; --i)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        nextSmaller[i] = st.empty() ? n :  st.top();
        st.push(i);
    }
    return nextSmaller;
} 
vector<int> maxMinWindow(vector<int> a, int n) {
   vector<int> ans(n,INT_MIN);
   stack<int> st;
   vector<int> leftSmall = findPreviousSmaller(a,n);
   vector<int> rightSmall = findNextSmaller(a,n);
   for(int i = 0; i<n; ++i)
   {
       int size = rightSmall[i]-leftSmall[i]-1;
       ans[size-1] = max(ans[size-1],a[i]);
   }
   int maxi = INT_MIN;
   for(int i=n-1; i>=0; --i)
   {
       maxi = max(maxi,ans[i]);
       ans[i] = maxi;
   }
   return ans;
}  