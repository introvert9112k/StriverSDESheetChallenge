#include <bits/stdc++.h>
/*
Intuition :
1.After every stream of number sort the array and find out the median.

Time Complexity : o(n*(nlogn))
nlogn -- for sorting the array
Space Complexity : O(n)
space for the ans array
*/
vector<int> bruteForce(vector<int> &arr, int n)
{
    vector<int> ans, medians(n);
    for (int i = 0; i < n; ++i)
    {
        ans.push_back(arr[i]);
        sort(ans.begin(), ans.end());
        int currMedian;
        if ((i + 1) & 1)
            currMedian = ans[(i + 1) / 2];
        else
            currMedian = (ans[(i + 1) / 2] + ans[(i - 1) / 2]) / 2;
        medians[i] = currMedian;
    }
    return medians;
}
/*
Intution :
1.use the insertion sort to sort the ans,after every data input.
Time Complexity : O(n*n)
O(n) time is taken to put the correct data input in the ans array
Space Complexity : O(n)
space for the ans array
*/
vector<int> betterWay(vector<int> &arr, int n)
{
    vector<int> ans, medians(n);
    for (int i = 0; i < n; ++i)
    {
        ans.push_back(arr[i]);
        int j = ans.size() - 1;
        while (j > 0 && ans[j] > ans[j - 1])
            swap(ans[j], ans[j - 1]), --j;
        int currMedian;
        if ((i + 1) & 1)
            currMedian = ans[(i + 1) / 2];
        else
            currMedian = (ans[(i + 1) / 2] + ans[(i - 1) / 2]) / 2;
        medians[i] = currMedian;
    }
    return medians;
}
/*
Intuition :
1.See the youtube video for intuition
*/
vector<int> usingMinMaxHeaps(vector<int> &arr, int n)
{
    // declaring minHeap for storing the right half elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // maxHeap for storing the left half elements
    priority_queue<int> maxHeap;
    vector<int> medians(n);
    for (int i = 0; i < n; ++i)
    {
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();
        /*this is the first element in the stream,so push into the maxHeap.
        As the size of the MaxHeap is greater than the minHeap by 1.*/
        if (maxHeapSize == 0)
            maxHeap.push(arr[i]);
        /*When both the heap sizes are equal*/
        else if (minHeapSize == maxHeapSize)
        {
            /*current number i.e arr[i] is less than the minHeap.top() so it
            should belong the left half,as it is valid to have maxHeap size
            greater than minHeap size by 1,we can push the value safely into
            the maxHeap*/
            if (arr[i] <= minHeap.top())
                maxHeap.push(arr[i]);
            /*arr[i] > minHeap.top(),so it should be go into the second Half,
            as the two heaps sizes are equal and we wish to add the excess elements
            into the maxHeap.
            If we add the curr value into minHeap,then minHeapSize > maxHeapSize.
            Which is not desired,so inorder to make maxHeapSize > minHeapSize,pop
            the first element in the minHeap and push into maxHeap and push the
            curr element into the minHeap.
            By doing this,the sorted order is maintained and constraints on the size
            i.e abs(maxHeapSize-minHeapSize) <= 1 is also not voilated*/
            else
            {
                int minHeapFirstValue = minHeap.top();
                minHeap.pop();
                maxHeap.push(minHeapFirstValue);
                minHeap.push(arr[i]);
            }
        }
        /*When the maxHeapSize = minHeapSize+1*/
        else
        {
            /*If there is no element in minHeap*/
            if (minHeapSize == 0)
            {
                /*Then it is safe to push the arr[i] into minHeap because as arr[i]
                >= maxHeap.top() the sorted order is maintained,and size constraint
                is also not vioalted*/
                if (arr[i] >= maxHeap.top())
                    minHeap.push(arr[i]);
                else
                {
                    /*arr[i] < maxHeap.top(),inorder to maintain the sorted
                    order we want to pop the maxHeap.top() and push into minHeap
                    and push the arr[i] into maxHeap*/
                    int maxHeapLastValue = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(maxHeapLastValue);
                    maxHeap.push(arr[i]);
                }
            }

            /*minHepaSize > 1 && maxHeapSize > 0*/
            else
            {
                /*as arr[i] >= minHeap.top() so it should be in the second Half,
                pushing it into second half makes the two heap sizes equal and
                sorted order is also maintained*/
                if (arr[i] >= minHeap.top())
                    minHeap.push(arr[i]);
                else
                {
                    /*arr[i] < minHeap.top() it should come into left half i.e
                    maxHeap.
                    Already the maxHeap size is > minHeap size by 1,if we push
                    into maxHeap then differnce in sizes would be 2,
                    so push the current value into maxHeap and pop the
                    maximum value in maxHeap and push into minHeap */
                    maxHeap.push(arr[i]);
                    int maxHeapLastValue = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(maxHeapLastValue);
                }
            }
        }

        /*If the length is odd,the median would be the maxHeap's top value
        else median would be average of the maxHeap top and minHeaps top*/
        if ((i + 1) & 1)
            medians[i] = maxHeap.top();
        else
            medians[i] = (maxHeap.top() + minHeap.top()) / 2;
    }
    return medians;
}
vector<int> findMedian(vector<int> &arr, int n)
{
    //    return bruteForce(arr, n);
    //   return betterWay(arr, n);
    return usingMinMaxHeaps(arr, n);
} 