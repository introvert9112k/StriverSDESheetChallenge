/*
Intuition :
1.There should be 1 queen is each column or 1 queen in each row.
2.So Try out all the possibilites.
3.Start with the column 0,check where in which row the queen can be placed safely,
later increase the column and check again in which row queen can be placed safely.
4.If columns reached to end,then every column has 1 queen so this would be the valid
configuration.

TC : Exponential in nature, since we are trying out all ways.
To be precise it goes as O(N! * N) nearly.
SC : O(N^2)
space for the chessBoard;
*/

/*
This function checks whether the queen can be placed safely at the given row and col location.
There are 8 possible directions in which the current queen come into under attack
by rest of placed queens.
As we are filling from left to right column,we don't need to  bother about the directions
from right side attacking.(3 directions gone.)
As one queen is placed in column,so we don't want to bother about the attacking from
up and down . (2 directions gone)
So only three attacking directions are left,they are
1.left direction
2.Upper diagonal
3.Lower diagonal
Check in these three directions whether there is any queen.
If any queen is not found in any of the directions then current location is safe.

TC : O(n + n + n)
In worst case for checking is O(n) for each direction.
SC : O(1)
*/
bool isSafeToPlaceQueen(int row, int col, int n, vector<vector<int>> &chessBoard)
{
    int currRow = row, currCol = col;
    for (int j = col; j >= 0; --j)
        if (chessBoard[row][j])
            return false;
    while (currRow >= 0 && currCol >= 0)
    {
        if (chessBoard[currRow][currCol])
            return false;
        --currRow;
        --currCol;
    }
    currRow = row;
    currCol = col;
    while (currRow < n && currCol >= 0)
    {
        if (chessBoard[currRow][currCol])
            return false;
        ++currRow;
        --currCol;
    }
    return true;
}
void isPossibleToPlaceQueens(int n, int col, vector<vector<int>> &chessBoard,
                             vector<vector<int>> &ans)
{
    if (col == n)
    {
        vector<int> temp(n * n);
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp[k++] = chessBoard[i][j];
            }
        }
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; ++row)
    {
        if (isSafeToPlaceQueen(row, col, n, chessBoard))
        {
            chessBoard[row][col] = 1;
            isPossibleToPlaceQueens(n, col + 1, chessBoard, ans);
            chessBoard[row][col] = 0;
        }
    }
}
/*
In this we are optimising the isSafe function.
If we keep track of which row and diagonals are queens placed then we can
directly say whether the current locaiton is safe or not.

leftRow[n] -- stores the rows in which the queens are already placed.

lowerDiagonal[row+col] -- stores the queens placed in lower diagonal.
If we observe carefully the locations which has row+col value same are in
same diagonal.These diagonals start from top-right goes till bottom-left.
So this diagonals corresponds to lower diagonals.

upperDiagonal[n-1+col-row]  stores the queens placed in upper diagonal.
If we observe carefully the locations which has (n-1+col-row) value same are
in same diagonal.These diagonals start from bottom-right goes till top-left.
So this diagonals corresponds to upper diagonals.

TC : O(N!)
Here isSafe function's O(N) time is not present.
SC : O(N^2 + 3N)
Space for the leftRow,uppperDiagonal,lowerDiagonal arrays and space for
chessBoard.
*/
void isPossibleToPlaceQueens2(int n, int col, vector<vector<int>> &chessBoard,
                              vector<vector<int>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal,
                              vector<int> &upperDiagonal)
{
    if (col == n)
    {
        vector<int> temp(n * n);
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp[k++] = chessBoard[i][j];
            }
        }
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; ++row)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
            upperDiagonal[n - 1 + col - row] == 0)
        {
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            chessBoard[row][col] = 1;
            isPossibleToPlaceQueens(n, col + 1, chessBoard, ans);
            chessBoard[row][col] = 0;
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    //    isPossibleToPlaceQueens(n, col, chessBoard, ans);
    isPossibleToPlaceQueens2(n, 0, chessBoard, ans, leftRow, lowerDiagonal,
                             upperDiagonal);
    return ans;
} 