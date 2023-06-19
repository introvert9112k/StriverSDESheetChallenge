#include <bits/stdc++.h>
/*
Intution :
1.Generate all possible triplets using the 3 loops,and check the condiiton.
2.We need the unique elements,so after finding the desired triplet,sort it
so that all the duplicates also can have the same order, and insert them into
set,so that only unique tirplets are stored.

TC : O(n*n*n*log(M))
M is the no of unqiue triplets
We are iterating over 3 loops which takes O(n^3) and each time we are inserting
into the set,which takes logM time.
SC : O(M + M)
Space for the hashSet and the ans array.
*/
vector<vector<int>> bruteForce(vector<int> &arr, int n, int target)
{
    set<vector<int>> hashSet;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    hashSet.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(hashSet.begin(), hashSet.end());
    return ans;
}
/*
Intution :
1.In the last approach we are using three loops i,j,k and to find out the triplet
2.Now we would use only two loops,and fix the two numbers and using map
we check whether the third number is in arr or not.
3.Suppose if arr[i],arr[j] are two numbers then the third number will be
(target - arr[i] - arr[j]).
4.We know that the pointers are in order i,j,k.Now let's fix the i and move
the k from i+1-->n-1.Now we have two numbers arr[i],arr[k],using the above
formula we can find out the arr[j].
5.Now we know that the j should be in range (i+1 <= j < k).While moving
we insert all the elements which come in the range of [i-k] into hashSet,and
we check whether the required Value i.e (target - arr[i] - arr[k]) in the
hashSet,if yes that mean this value corresponds to arr[j].
6.Re intialize the hashSet for the newValue of i.

TC : O(n*n*logM)
We are iterating over two loops,and inserting in hashMap takes O(1) time.
let M be the no of unqiue numbers.
At each iteration we are inserting into set whcich takes O(logM) time.
SC : O(M + M)
Space for the hashSet and the ans array.
*/
vector<vector<int>> usingHashMap(vector<int> &arr, int n, int target)
{
    set<vector<int>> hashSet;
    for (int i = 0; i < n; ++i)
    {
        unordered_map<int, int> map;
        for (int j = i + 1; j < n; ++j)
        {
            int requiredVal = target - (arr[i] + arr[j]);
            if (map.find(requiredVal) != map.end())
            {
                vector<int> temp = {arr[i], arr[j], requiredVal};
                sort(temp.begin(), temp.end());
                hashSet.insert(temp);
            }
            ++map[arr[j]];
        }
    }
    vector<vector<int>> ans(hashSet.begin(), hashSet.end());
    return ans;
}
/*
Intution :
1.Fix the one value i.e arr[i] and use two sum approach to check for the existence of
arr[j] + arr[k].

TC : O(nlogn + n*n)
nlogn - sorting
n*n for finding the triplets.
SC : O(M)
Space for the ans array.
*/
vector<vector<int>> usingTwoPointers(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        /*If previous value is same as current Value,that mean it already
        processed, if we go with current value we end up in duplicates,
        so just continue to next unique value*/
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > target)
                --k;
            else if (sum < target)
                ++j;
            else
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                --k;
                ++j;
                /*move the k and j to the next unique element*/
                while (j < k && arr[j] == arr[j - 1])
                    ++j;
                while (j < k && arr[k] == arr[k + 1])
                    --k;
            }
        }
    }
    return ans;
}

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    // return bruteForce(arr,n,K);
    // return usingHashMap(arr,n,K);
    return usingTwoPointers(arr, n, K);
} 