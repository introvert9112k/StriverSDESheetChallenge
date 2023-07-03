#include <bits/stdc++.h>
/*
Brute Force :
1.Just collect all the numbers into arr and sort it and return median
Time Complexity : O(m*n + m*nlog(m*n))
m*n for collecting matrix values into arr
m+*n(logm*n) for sorting the array.
Space Complexity : O(m*n)
space for the array.
*/
int approach1(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> arr(m * n);
    int k = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr[k++] = matrix[i][j];
        }
    }
    sort(arr.begin(), arr.end());
    return arr[((m * n) / 2)];
}
/*
Intuition :
1.Given the 1 <= matrix[i][j] <= 1e5.
So median would be in the range [1,1e5].
For safety 1e6 is taken as high.

So apply binary search on the range and try to find out the median.
If a number x is median then numbers <= x is (m*n)/2 and numbers >= x (m*n)/2
IF we found numbers <= x then automatically we would know the count of numbers >= x.
So find the count of numbers which are <= x in the matrix.
As the each row is sorted in matrix,apply the binary search to find out the
numbers <= x in each row using binary search and add them up.

if cnt <= (m*n)/2 then ans would be right else it would be left.
Finally low points to the median of the matrix.

Time Complexity : O(m*log2(n).log2(1e6))
log2(1e6) for the binary search on the answer.
We are applying the binary search on the each row which takes m*log2(n).
Space Complexity : o(1)
*/
int numbersLessThanEqualToMid(vector<vector<int>> &matrix, int num)
{
    int m = matrix.size(), n = matrix[0].size();
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            matrix[i][mid] <= num ? low = mid + 1 : high = mid - 1;
        }
        cnt += low;
    }
    return cnt;
}
int usingBinarySearch(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int low = 1, high = 1e6;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = numbersLessThanEqualToMid(matrix, mid);
        cnt <= (m * n) / 2 ? low = mid + 1 : high = mid - 1;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    return usingBinarySearch(matrix);
} 