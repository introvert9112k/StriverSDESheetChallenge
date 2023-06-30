#include <bits/stdc++.h>
bool isGraphBirpatiteDFs(int currNode, vector<int> adjList[],
                         vector<int> &isColored)
{
    for (auto adjNode : adjList[currNode])
    {
        if (isColored[adjNode] == -1)
        {
            isColored[adjNode] = 1 - isColored[currNode];
            if (!isGraphBirpatiteDFs(adjNode, adjList, isColored))
                return false;
        }
        else if (isColored[adjNode] == isColored[currNode])
            return false;
    }
    return true;
}
bool isGraphBirpatiteBFs(int currNode, vector<int> adjList[],
                         vector<int> &isColored)
{
    queue<int> q;
    q.push(currNode);
    while (!q.empty())
    {
        currNode = q.front();
        q.pop();
        for (auto adjNode : adjList[currNode])
        {
            if (isColored[adjNode] == -1)
            {
                isColored[adjNode] = 1 - isColored[currNode];
                q.push(adjNode);
            }
            else if (isColored[adjNode] == isColored[currNode])
                return false;
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adjList[n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (edges[i][j])
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    vector<int> isColored(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (isColored[i] == -1)
        {
            isColored[i] = 0;
            //    if(!isGraphBirpatiteDFs(i,adjList,isColored)) return false;
            if (!isGraphBirpatiteBFs(i, adjList, isColored))
                return false;
        }
    }
    return true;
} 