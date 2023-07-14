#include <bits/stdc++.h>
int largestRectangle(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i < n; ++i)
    {
        /*Iterate until the previous smaller element is found for current element*/
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            /*We know that index at st.top() > the curr index height.
            So for the st.top() bar the next smaller bar is curr Index.
            previous Smaller index is given by the index under top() index.
            As stack is sorted in descending order from top to bottom*/
            int currHeight = heights[st.top()];
            /*popping from stack to findout the left smaller index */
            st.pop();
            int rightSmall = i; /*next Smaller is curr Index*/
            /*If stack is empty then there is no left smaller index else stack's top
            will be the left smaller index.*/
            int leftSmall = st.empty() ? -1 : st.top();
            /*calculating the maxArea*/
            maxArea = max(maxArea, (rightSmall - leftSmall - 1) * currHeight);
        }
        st.push(i);
    }
    /*After the iteration is over,there will be some indexes left in the stack.
    For all the indexes in the stack there is no right smaller index.
    So let's consider right smaller index as n and find the left smaller index
    as we done earlier.*/
    while (!st.empty())
    {
        int currHeight = heights[st.top()];
        st.pop();
        int rightSmall = n;
        int leftSmall = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (rightSmall - leftSmall - 1) * currHeight);
    }
    return maxArea;
} 