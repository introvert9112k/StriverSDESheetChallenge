/*
Intuition :
1.Just iterate and check for the lucky number.
There are 3 cases possible
case 1 : when i == 0,if arr[0] is lucky number then arr[0] != arr[1]
case 2 : when i == n-1 if arr[n-1] is lucky number then arr[n-1] != arr[n-2]
case 3 : when 0 < i < n-1 is lucky number if arr[i] != arr[i+1] && arr[i] != arr[i-1].

Handle these three cases we can find the lucky number.
Time Complexity  : O(n)
Space Complexity : O(1)
*/
int usingLinearSearch(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 && arr[i] != arr[i + 1])
            return arr[i];
        else if (i == n - 1 && arr[i] != arr[i - 1])
            return arr[i];
        else
        {
            if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1])
                continue;
            else
                return arr[i];
        }
    }
    return -1;
}
/*
Intuition :
1.It is stated than array contains every number repeated twice expect one.
2.Taking Xor of whole array gives the lucky number.

Time Compelxity : O(n)
Space Complexity : O(1)
*/
int usingXor(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    int Xor = 0;
    for (int i = 0; i < n; ++i)
        Xor ^= arr[i];
    return Xor;
}
/*
1.Apply the binary search over the range [0,n-1].
2.If arr[mid] == arr[mid+1] then count the no of numbers in the left subarray and
the right subarray leaves arr[mid] and arr[mid+1].
3.If right subarray has odd length then our target is in right subarray so move
right else move left.
4.If arr[mid] == arr[mid-1] then count the no of numbers in the left subarray and
the right subarray leaves arr[mid] and arr[mid-1].
5.If right subarray has odd length then our target is in right subarray so move
right else move left.
6.If above two cases fail arr[mid] is the target.

Time Complexity  : O(nlogn)
Space Complexity : O(1)
*/
int usingBinarySearch(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int left, right;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // mid < high avoids the edge case when mid is last element in search space
        if (mid < high && arr[mid] == arr[mid + 1])
        {
            left = mid - low;       // finding left subarray length
            right = high - mid - 1; // finding right subarray length
            right & 1 ? low = mid + 2 : high = mid - 1;
        }
        // mid > low avoids the edge case when mid is first element in search space
        else if (mid > low && arr[mid] == arr[mid - 1])
        {
            left = mid - low - 1; // finding left subarray length
            right = high - mid;   // finding right subarray length
            right & 1 ? low = mid + 1 : high = mid - 2;
        }
        else
            return arr[mid];
    }
    return -1;
}

int findSingleElement(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        /*If the mid is at even index*/
        if (mid % 2 == 0)
        {
            /*if arr[mid] == arr[mid+1]
            first instance i.e mid is even
            second instance i.e mid+1 is odd
            So we are in the left half, we should move to right.
            */
            if (nums[mid] == nums[mid + 1])
                low = mid + 1;
            /*
            if arr[mid] == arr[mid-1]
            first instance  i.e mid-1 is odd
            second instance i.e mid is even.
            So we are in the right half,we should move to left.
            */
            else
                high = mid - 1;
        }
        /*If the mid is at the odd index.*/
        else
        {
            /*if arr[mid] == arr[mid+1] i.e
            first instance i.e mid is odd
            second instance i.e mid+1 is even,
            so we are in the right half so we should move left.*/
            if (nums[mid] == nums[mid + 1])
                high = mid - 1;
            /*if arr[mid] == arr[mid-1]
              first instance  i.e mid-1 is even.
              second instance i.e mid is odd
              So we are in the left half so we should move right.
             */
            else
                low = mid + 1;
        }
    }
    return nums[low];
}
int singleNonDuplicate(vector<int> &arr)
{
    return findSingleElement(arr);
} 