#include <bits/stdc++.h>
/*
Intuition :
1.Take a multiset which keeps tracks of maximum element in the current Window.

Time Complexity  : O(nlogk)
set has k elements,in each operation we are inserting and erasing which takes
O(logk) time
Space Complexity : O(k)
At max set can have k elements.
*/
vector<int> usingMultiset(vector<int> &nums, int k)
{
    multiset<int> set;
    int n = nums.size();
    vector<int> ans(n - k + 1);
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        set.insert(nums[i]);
        if (i == k - 1)
            ans[j++] = *set.rbegin();
        else if (i >= k)
        {
            auto it = set.find(nums[i - k]);
            set.erase(it);
            ans[j++] = *set.rbegin();
        }
    }
    return ans;
}
vector<int> usingDequeue(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> dq;
    vector<int> ans(n - k + 1);
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        /*removing the indexes which are not part of the current window*/
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        /*removing the numbers which are less than the current number in the window.
        Because for every window those numbers are part of,current number will also
        be present in that window.
        So maximum would be current number only,they are redudant they never be the
        maximum in the present of current number.So remove them from the queue.*/
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        /*Pushing the current number into queue.*/
        dq.push_back(i);
        /*i >= k-1 then it is valid window.
        As we are storing the numbers in decreasing order,the number at the front of the
        queue is the maximum element in current window*/
        if (i >= k - 1)
            ans[j++] = nums[dq.front()];
    }
    return ans;
}
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    // return usingMultiset(nums,k);
    return usingDequeue(nums, k);
} 