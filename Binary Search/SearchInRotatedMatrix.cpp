int search(int *arr, int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        /*Left half is sorted*/
        if (arr[low] <= arr[mid])
        {
            /*Check whether the target is in left half or not*/
            if (arr[low] <= key && key <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        /*Right half is sorted*/
        else
        {
            if (arr[mid] <= key && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
} 