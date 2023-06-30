#include <bits/stdc++.h>
bool isCycleExistsDFs(int currNode, vector<int> adjList[], vector<bool> &visited,
                      vector<bool> &dfsVisited)
{
    visited[currNode] = true;
    dfsVisited[currNode] = true;
    for (auto &adjNode : adjList[currNode])
    {
        if (visited[adjNode] == false)
        {
            if (isCycleExistsDFs(adjNode, adjList, visited, dfsVisited))
                return true;
        }
        else if (dfsVisited[adjNode])
            return true;
    }
    dfsVisited[currNode] = false;
    return false;
}
bool DFs(int n, vector<pair<int, int>> &edges)
{
    vector<int> adjList[n + 1];
    for (auto edge : edges)
        adjList[edge.first].push_back(edge.second);
    vector<bool> visited(n + 1, false), dfsVisited(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == false)
        {
            if (isCycleExistsDFs(i, adjList, visited, dfsVisited))
                return true;
        }
    }
    return false;
}

bool isCycleExistsBFs(int n, vector<pair<int, int>> &edges)
{
    vector<int> adjList[n + 1];
    for (auto edge : edges)
        adjList[edge.first].push_back(edge.second);
    vector<int> indegree(n + 1, 0);
    for (auto edge : edges)
        ++indegree[edge.second];
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();
        ++cnt;
        for (auto adjNode : adjList[currNode])
        {
            if (--indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
    return cnt == n ? false : true;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    return isCycleExistsBFs(n, edges);
    // return DFs(n,edges);
} 