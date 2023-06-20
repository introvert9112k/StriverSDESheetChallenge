/*
Intution :
1.Generate all possiblites.

Time Complexity: O(9^(n ^ 2)),
in the worst case, for each cell in the n2 boardwe have 9 possible numbers.
Space Complexity: O(1), since we are refilling the given board itself,
there is no extra space required, so constant space complexity.
*/
bool isItSudoku(int matrix[9][9])
{
    auto isPossible = [&](int row, int col, int num)
    {
        for (int i = 0; i < 9; ++i)
        {
            /*checking for the number in the row*/
            if (matrix[row][i] == num)
                return false;
            /*checking for the number in the column*/
            if (matrix[i][col] == num)
                return false;
            /*
            row/3 gives the horizantal level of the submatrix.
            3*(row/3) gives the first row of the horizantal level of
            subMatrix.
            There are 3 rows in subMatrix, row/3 gives the which are we are
            in now in the subMatrix.
            Same with the column, col%3 gives which column we are in
            the subMatrix as there are only 3 columns for each row.
            */
            int subMatrixRow = 3 * (row / 3) + row / 3;
            int subMatrixCol = 3 * (col / 3) + col % 3;
            if (matrix[subMatrixRow][subMatrixCol] == num)
                return false;
        }
        return true;
    };
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            /*if cell is empty*/
            if (matrix[i][j] == 0)
            {
                /*trying out all possible numbers in this location*/
                for (int num = 1; num <= 9; ++num)
                {
                    /*If it is valid to place this number at this location*/
                    if (isPossible(i, j, num))
                    {
                        matrix[i][j] = num; /*Filling the location*/
                        /*Making recursive call to check for the next vacant cell
                        If any call returns true then returning true from there itself,
                        because we just want to find one solution only*/
                        if (isItSudoku(matrix))
                            return true;
                        matrix[i][j] = 0; /*Making the cell vacant if current call
                        doesn't gives the solution*/
                    }
                }
                /*If any the number at this location doesn't yield solution,so returning
                false*/
                return false;
            }
        }
    }
    /*As all the cells are filled,there is a solution,so returning true*/
    return true;
} 