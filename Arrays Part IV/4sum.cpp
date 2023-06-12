#include <bits/stdc++.h>
/*
Intution :
1.Generate all possible quadraplets using the 4 loops,and check the condiiton.
2.We need the unique elements,so after finding the desired quadraplet,sort it
so that all the duplicates also can have the same order, and insert them into
set,so that only unique qudraplets are stored.

TC : O(n*n*n**log(M))
M is the no of unqiue quadraplets
We are iterating over 4 loops which takes O(n^4) and each time we are inserting
into the set,which takes logM time.
SC : O(M + M)
Space for the hashSet and the ans array.
*/
vector<vector<int>> bruteForce(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> set;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                for (int l = k + 1; l < n; ++l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        set.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(set.begin(), set.end());
    return ans;
}
/*
Intution :
1.In the last approach we are using 4 loops i,j,k,l and to find out the quadraplet
2.Now we would use only 3 loops,and fix the 3 numbers and using map
we check whether the 4th number is in arr or not.
3.Suppose if arr[i],arr[j],arr[k] are 3 numbers then the third number will be
(target - arr[i] - arr[j]-arr[k]).
4.We know that the pointers are in order i,j,k,l.Now let's fix the i,j and move
the l from j+1-->n-1.Now we have two numbers arr[i],arr[j],arr[l],using the above
formula we can find out the arr[k].
5.Now we know that the k should be in range (j+1 <= k < l).While moving
we insert all the elements which come in the range of [j-k] into hashSet,and
we check whether the required Value i.e (target - arr[i] - arr[j] - arr[l]) in the
hashSet,if yes that mean this value corresponds to arr[k].
6.Re intialize the hashSet for the newValue of i and j.

TC : O(n*n*n*logM)
We are iterating over 3 loops,and inserting in hashMap takes O(1) time.
let M be the no of unqiue numbers.
At each iteration we are inserting into set whcich takes O(logM) time.
SC : O(M + M)
Space for the hashSet and the ans array.
*/
vector<vector<int>> usingHashMap(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> set;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            unordered_map<int, int> hashMap;
            for (int k = j + 1; k < n; ++k)
            {
                int requiredVal = target - (nums[i] + nums[j] + nums[k]);
                if (hashMap.find(requiredVal) != hashMap.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], requiredVal};
                    sort(temp.begin(), temp.end());
                    set.insert(temp);
                }
                ++hashMap[nums[k]];
            }
        }
    }
    vector<vector<int>> ans(set.begin(), set.end());
    return ans;
}
/*
Intution :
1.Fix the 2 values i.e arr[i],arr[j] and use two sum approach to check for the existence of
arr[l] + arr[k].

TC : O(nlogn + n*n*n)
nlogn - sorting
n*n*n for finding the triplets.
SC : O(M)
Space for the ans array.
*/
vector<vector<int>> usingTwoPointers(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i)
    {
        /*Avoiding the duplicates*/
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        for (int j = i + 1; j < n; ++j)
        {
            /*avoding the duplicates*/
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = n - 1;
            int requiredVal = target - (nums[i] + nums[j]);
            while (k < l)
            {
                int sum = nums[k] + nums[l];
                if (sum > requiredVal)
                    --l;
                else if (sum < requiredVal)
                    ++k;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    ++k;
                    --l;
                    while (k < l && nums[k] == nums[k - 1])
                        ++k;
                    while (k < l && nums[l] == nums[l + 1])
                        --l;
                }
            }
        }
    }
    return ans;
}
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // Write your code here
    // return bruteForce(nums,target);
    return usingHashMap(nums, target);
    // return usingTwoPointers(nums,target);
} 