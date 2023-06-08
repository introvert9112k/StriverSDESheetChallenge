class Solution {
public:
  /*
  If we observe carefully the 
  1st row becomes last column
  2nd row becomes second last column 
  and so on.
2. So we can create a matrix and convert the rows to columns as described above.
Time Complexity : O(n*n)
Space Complexity : O(n*n) 
*/
void bruteForce(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> temp(n,vector<int>(m));
    for(int i = 0; i<n; ++i)
    {
        for(int j = 0; j<m; ++j)
        {
            temp[j][n-1-i] = mat[i][j];
        }
    }
    /*Now the temp contains the matrix after rotating 90 degrees.
    If we want we can copy the temp into matrix and return*/
}
    /*
    Intution :
    If we observe carefully then we can identify that the first rows are made to
    columns and then it is reversed to get the requied matrix.
    So there are two tasks
    1.Convert rows into columns [i.e Transpose the Matrix]
    2.Reverse each row.
    See the strivers youtube video.
    Time Complexity : O(n/2*n/2 + n*n/2)
    We just iterate over the upper half of the matrix which has O(n/2*n/2)
    we reverse each row. There are n rows and reversing takes n/2 time.
    Space Complexity : O(1)

    NOTE : for antiClockWise Rotation : 
    1. Transpose the matrix and reverse the columns.
    For 180,270
    90: Transpose + Reverse Rows
    180: Reverse Rows + Reverse columns (Do 90 degrees twice)
    270 : Transpose + Reverse Columns (Do 90 degrees thrice)
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; ++i)
        {
            for(int j = i + 1; j <n; ++j)
              swap(matrix[i][j],matrix[j][i]);
        }
        for(int i = 0; i<n; ++i)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};  