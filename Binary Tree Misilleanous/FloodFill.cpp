#include <bits/stdc++.h>
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
/*
Time complexity  : O(m*n)
Space complexity : O(m*n)
*/
void floodFillAlgo(vector<vector<int>> &ans, int x, int y, int intialColor, int newColor)
{
    ans[x][y] = newColor;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < ans.size() && ny >= 0 && ny < ans[0].size() &&
            ans[nx][ny] == intialColor)
            floodFillAlgo(ans, nx, ny, intialColor, newColor);
    }
}
/*
Time complexity  : O(m*n)
Space complexity : O(m*n)
*/
void floodFillAlgoBFs(vector<vector<int>> &ans, int x, int y, int intialColor, int newColor)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    ans[x][y] = newColor;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        x = it.first;
        y = it.second;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < ans.size() && ny >= 0 && ny < ans[0].size() &&
                ans[nx][ny] == intialColor)
            {
                ans[nx][ny] = newColor;
                q.push({nx, ny});
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    vector<vector<int>> ans(image.begin(), image.end());
    /*If intial Color is equal to newColor,then there is no need to change,so return input*/
    if (image[x][y] == newColor)
        return ans;
    // floodFillAlgo(ans,x,y,image[x][y],newColor);
    floodFillAlgoBFs(ans, x, y, image[x][y], newColor);
    return ans;
} 