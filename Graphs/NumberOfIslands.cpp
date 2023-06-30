#include <bits/stdc++.h>
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
void markIslandDFs(int x, int y, int n, int m, int **arr)
{
    arr[x][y] = 0;
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny])
            markIslandDFs(nx, ny, n, m, arr);
    }
}
void markIslandBFs(int x, int y, int n, int m, int **arr)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = 0;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny])
            {
                arr[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}
int getTotalIslands(int **arr, int n, int m)
{
    int islands = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 1)
            {
                ++islands;
                // markIslandDFs(i,j,n,m,arr);
                markIslandBFs(i, j, n, m, arr);
            }
        }
    }
    return islands;
}
 