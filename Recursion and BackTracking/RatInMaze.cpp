#include <bits/stdc++.h>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void findAllPaths(int x, int y, int n, vector<vector<int>> &maze,
                  vector<vector<int>> &path, vector<vector<int>> &ans)
{
    path[x][y] = 1;
    if (x == n - 1 && y == n - 1)
    {
        vector<int> temp(n * n);
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp[k++] = path[i][j];
            }
        }
        ans.push_back(temp);
        path[x][y] = 0;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] &&
            path[nx][ny] == 0)
            findAllPaths(nx, ny, n, maze, path, ans);
    }
    path[x][y] = 0;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> path(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    findAllPaths(0, 0, n, maze, path, ans);
    return ans;
} 