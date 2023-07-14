#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    queue<pair<int, int>> q;
    int totalOranges = 0, rottenOranges = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                ++rottenOranges;
                ++totalOranges;
            }
            else if (grid[i][j] == 1)
                ++totalOranges;
        }
    }
    if (totalOranges == 0)
        return 0;
    if (rottenOranges == 0)
        return -1;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int timeRequired = -1;
    for (; !q.empty(); ++timeRequired)
    {
        for (int i = q.size(); i > 0; --i)
        {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                    ++rottenOranges;
                }
            }
        }
    }
    return totalOranges == rottenOranges ? timeRequired : -1;
} 