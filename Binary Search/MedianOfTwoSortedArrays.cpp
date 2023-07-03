/*
Intuition :
1.Merge the two sorted arrays into one and return the median

Time Complexity  : O(m+n)
Space Complexity : O(m+n)
space for the merged array.
*/
double mergeTwoSortedArrays1(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<int> arr(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n || j < m)
    {
        if (i < n && j < m)
            arr[k++] = a[i] <= b[j] ? a[i++] : b[j++];
        else
            arr[k++] = i < n ? a[i++] : b[j++];
    }
    if ((n + m) & 1)
        return arr[(n + m) / 2];
    else
        return (arr[(n + m) / 2] + arr[(n + m - 1) / 2]) / double(2);
}
/*
Intuiton :
1.We are only concerned about the median.
2.We can keep track of the values which would be our median,when we found those
values we can return from there.

Time Complexiy : O(n+m)
Space Complexity : O(1)
*/
double mergeTwoSortedArrays2(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    /*cnt keep track of the location of median in the merged arrays*/
    int cnt = (n + m) / 2 + 1;
    /*In case of the even length we need the two values,so value1 and value2.
    Keep on updating the values as we progress.
    When we reach the location of median i.e cnt == 0,
    then if length is odd then median is value1.
    else median is (value1 + value2)/2*/
    int value1 = -1, value2 = -1;
    while (i < n || j < m)
    {
        if (i < n && j < m)
        {
            value2 = value1;
            value1 = a[i] <= b[j] ? a[i++] : b[j++];
        }
        else
        {
            value2 = value1;
            value1 = i < n ? a[i++] : b[j++];
        }
        --cnt;
        if (cnt == 0)
            return (n + m) & 1 ? value1 : (value1 + value2) / double(2);
    }
}
double usingBinarySearch(vector<int> &a, vector<int> &b)
{
    if (b.size() < a.size())
        return usingBinarySearch(b, a);
    int n1 = a.size(), n2 = b.size();
    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
        int right1 = cut1 == n1 ? INT_MAX : a[cut1];
        int right2 = cut2 == n2 ? INT_MAX : b[cut2];
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / double(2);
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}
double median(vector<int> &a, vector<int> &b)
{
    // return mergeTwoSortedArrays1(a,b);
    // return mergeTwoSortedArrays2(a,b);
    return usingBinarySearch(a, b);
} 