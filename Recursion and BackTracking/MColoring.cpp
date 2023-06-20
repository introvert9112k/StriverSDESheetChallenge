#include <bits/stdc++.h>
bool isSafeToColor(int node, int n, int color, vector<int> &isColored, vector<vector<int>> &mat)
{
    for (int i = 0; i < n; ++i)
    {
        if (mat[node][i] == 1 && isColored[i] == color)
            return false;
    }
    return true;
}
bool isPossibleToColor(int currNode, int n, int m, vector<int> &isColored,
                       vector<vector<int>> &mat)
{
    if (currNode == n)
        return true;
    for (int color = 1; color <= m; ++color)
    {
        if (isSafeToColor(currNode, n, color, isColored, mat))
        {
            isColored[currNode] = color;
            if (isPossibleToColor(currNode + 1, n, m, isColored, mat))
                return true;
            isColored[currNode] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> isColored(n, 0);
    return isPossibleToColor(0, n, m, isColored, mat) ? "YES" : "NO";
} 