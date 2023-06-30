#include <bits/stdc++.h>
bool isCycleExistsDFs(int currNode, int parentNode, vector<int> adjList[],
                      vector<bool> &visited)
{
    visited[currNode] = true;
    for (auto adjNode : adjList[currNode])
    {
        if (!visited[adjNode])
        {
            if (isCycleExistsDFs(adjNode, currNode, adjList, visited))
                return true;
        }
        else if (adjNode != parentNode)
            return true;
    }
    return false;
}

bool isCycleExistsBFs(int currNode, int parentNode, vector<int> adjList[],
                      vector<bool> &visited)
{
    queue<pair<int, int>> q;
    q.push({currNode, -1});
    visited[currNode] = true;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        currNode = it.first;
        int parentNode = it.second;
        for (auto adjNode : adjList[currNode])
        {
            if (!visited[adjNode])
            {
                visited[adjNode] = true;
                q.push({adjNode, currNode});
            }
            else if (adjNode != parentNode)
                return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<int> adjList[n + 1];
    for (int i = 0; i < m; ++i)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == false)
        {
            if (isCycleExistsBFs(i, -1, adjList, visited))
                return "Yes";
        }
    }
    return "No";
} 