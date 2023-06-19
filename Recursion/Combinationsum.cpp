/*
Intuition :
1.Generate all the subsets and check which subsets have sum equal to k.
TC : O(2^n *n)
There are 2^n subsets,if sum equal to k we are pushing them into ans
it's takes o(n) time.
SC : O(2^n*n)
Space for storing the all the subsets.
*/
void findValidSubSets(int ind, int n, int k, int sum, vector<int> &arr,
                      vector<int> &subset, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        if (sum == k)
            ans.push_back(subset);
        return;
    }
    subset.push_back(arr[ind]);
    findValidSubSets(ind + 1, n, k, sum + arr[ind], arr, subset, ans);
    subset.pop_back();
    findValidSubSets(ind + 1, n, k, sum, arr, subset, ans);
}
/*
Intuition :
1.using the powerset to find out the subset sum.
Same as before.
*/
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
}
void validSubSets2(vector<int> &num, int k, vector<vector<int>> &ans)
{
    int n = num.size();
    int pow = power(2, n);
    for (int i = 0; i < pow; ++i)
    {
        int val = i, sum = 0;
        vector<int> subset;
        while (val > 0)
        {
            int rsbm = val & -val; /*finding right most bit mask*/
            int pos = log2(rsbm);  /*location of the right most set bit*/
            sum += num[pos];       /*Taking corresponding value into sum*/
            val = val - rsbm;      /*unsetting the right most set bit*/
            subset.push_back(num[pos]);
        }
        if (sum == k)
            ans.push_back(subset);
    }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> subset;
    // findValidSubSets(0,n,k,0,arr,subset,ans);
    validSubSets2(arr, k, ans);
    return ans;
} 