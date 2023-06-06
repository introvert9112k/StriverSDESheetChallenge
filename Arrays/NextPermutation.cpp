#include <bits/stdc++.h>
void reverse(vector<int> &permutation, int start, int end)
{
    for (int low = start, high = end; low < high; ++low, --high)
        swap(permutation[low], permutation[high]);
}
/*Intution :
1.We need the next permuation,to get the immediate permutation we
maximize the common prefix we can get.
2.For the current Index to be last index of the common prefix,there
should exists a number which is greater than the current number on its
right.
3.If such number exists we can swap that number with current value.
4.Now the permutation we got is > than the permutation we had.But it
is not the immediate next permutation.
5.Now the case computed permutation is > given permutation satisfied,
now we should take care of the immediate next funcationality.
6.In order to get immediate next the right side elemnets of current index
should be increasing order.
7.so sort the right side elements.

Time Complexity : O(N)
Space Complexity : O(1)
*/
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind = -1;
    /*Finding the such index for which there is a value greater
    than current value on right side.
    We are starting from n-2,because there would be no greater value
    than arr[n-1] on its right side.
    if the condition arr[i] < arr[i+1] doesn't hold mean there is
    no greater value on right side.
    */
    for (int i = n - 2; i >= 0; --i)
    {
        if (permutation[i] < permutation[i + 1])
        {
            ind = i;
            break;
        }
    }
    /*If ind == -1,there is no such point we are looking for,that
    mean current permutation is the largest possible permutation.
    so next permutation would be smallest permutation possible.
    So sort the current permuation in ascending order to get the next
    permutation*/
    if (ind == -1)
    {
        reverse(permutation, 0, n - 1);
        return permutation;
    }
    /*Finding out the least value which is greater than the arr[ind]
    or breaking point.*/
    for (int i = n - 1; i > ind; --i)
    {
        /*Swapping the values,if we swap also the right side
        array still be in descending order.*/
        if (permutation[i] > permutation[ind])
        {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }
    /*As the right side array is in descenindg order,just by reversing
    we would get the ascending or sorted order*/
    reverse(permutation, ind + 1, n - 1);
    return permutation;
} 