#include <bits/stdc++.h>
class MinHeap
{
public:
    vector<int> arr;
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void push(int val)
    {
        arr.push_back(val);       /*insert value at the last of the array*/
        int ind = arr.size() - 1; /*index where the latest value is inserted*/
        /*Inserting this might change the minHeap property,so reviving the property back*/
        while (ind > 0 && arr[parent(ind)] > arr[ind])
        {
            swap(arr[parent(ind)], arr[ind]);
            ind = parent(ind);
        }
    }
    void minHeapify(int ind)
    {
        int right = rightChild(ind);
        int left = leftChild(ind);
        int smallestChild = ind;
        if (right < arr.size() && arr[right] < arr[smallestChild])
            smallestChild = right;
        if (left < arr.size() && arr[left] < arr[smallestChild])
            smallestChild = left;
        if (smallestChild != ind)
        {
            swap(arr[ind], arr[smallestChild]);
            minHeapify(smallestChild);
        }
    }
    int pop()
    {
        /*minimum Value is given by arr[0]*/
        int minValue = arr[0];
        /*copy the last value to the root*/
        arr[0] = arr.back();
        /*remove the last value from the arr*/
        arr.pop_back();
        /*If arr.size() == 0,then there are no elements so return the minvalue*/
        if (arr.size() == 0)
            return minValue;
        else
            minHeapify(0);
        return minValue;
    }
};
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> ans;
    MinHeap pq;
    for (int i = 0; i < n; ++i)
    {
        if (q[i].size() == 2)
            pq.push(q[i][1]);
        else
            ans.push_back(pq.pop());
    }
    return ans;
} 