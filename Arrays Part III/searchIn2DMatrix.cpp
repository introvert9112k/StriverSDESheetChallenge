/*
Intuition : 
1.First find out the row in which the target lies using binary search.
2.Next find out the position in the row where the target should lie,
if target lies at that position return true else false.

TC : O(logm + logn) or (log(m*n))
logm for finding the target Row
logn for finding the target index in the row.
SC : O(1) 
*/
int findTargetRow(vector<vector<int>>& mat,int m,int target)
{
   int low = 0,high = m-1;
   while(low <= high)
   {
       int mid = low + (high-low)/2;
       mat[mid][0] <= target ? low = mid+1 : high = mid-1;
   }
   return high;
}
int findTargetIndex(vector<vector<int>>& mat,int n,int targetRow,int target)
{
   int low = 0,high = n-1;
   while(low <= high)
   {
       int mid = low + (high-low)/2;
       mat[targetRow][mid] < target ? low = mid+1 : high = mid-1;
   }
   return low;
} 
/*
Intuition : 
1.The properties that all the row elements are in sorted order and 
previous row value is less than the next row 1st value,makes the matri
to be of sorted array of size m*n.
2.So we can apply the binary search to find the target.
3.We can use the imaginary indexes of the array to iterate over the matrix

TC : O(log(m*n))
SC : O(1)
*/
bool approach2(vector<vector<int>>& mat, int target)
{
   int m = mat.size(),n = mat[0].size();
   int low = 0,high = m*n-1;
   while(low <= high)
   {
       int mid = low + (high-low)/2;
       int value = mat[mid/n][mid%n]; 
       /*correspoding value at the position mid in matrix is given 
       by arr[mid/n][mid%n]*/
       if(value == target) return true;
       value < target ? low = mid+1 : high = mid-1;
   }
   return false;
}
bool searchMatrix(vector<vector<int>>& mat, int target) {
    // int m = mat.size(), n = mat[0].size();
    // int targetRow = findTargetRow(mat,m,target);
    // int ind = findTargetIndex(mat,n,targetRow,target);
    // return mat[targetRow][ind] == target;

    return approach2(mat,target);
} 

/*GFG Solution : */

class Solution
{
    public:
    /*
    Start from the last element in the first Column.
    Given that the matrix is sorted row and column wise.
    if arr[i][j] > x that mean all the values in the same column in next rows will
    be greater than the x,as matrix is sorted column wise.so move to previous element in 
    same row.
    arr[i][j] < x that mean,if we go previous value in same matrix that will be further
    less than the x,so go to next row.
    
    TC : O(m+n)
    SC : O(1) 
    */
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int i = 0,j = m-1;
        while(i < n && j >= 0)
        {
            if(matrix[i][j] == x) return true;
            if(matrix[i][j] < x) ++i;
            else --j;
        }
        return false;
    }
}; 