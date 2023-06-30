#include <bits/stdc++.h>
void findTopologicalOrderDFs(int currNode, vector<int> adjList[],
                             vector<bool> &visited, vector<int> &toposort)
{
    visited[currNode] = true;
    for (auto adjNode : adjList[currNode])
        if (visited[adjNode] == false)
            findTopologicalOrderDFs(adjNode, adjList, visited, toposort);
    toposort.push_back(currNode);
}
vector<int> topoSortDFs(vector<vector<int>> &edges, int v)
{
    vector<int> adjList[v];
    for (auto edge : edges)
        adjList[edge[0]].push_back(edge[1]);
    vector<int> toposort;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == false)
        {
            findTopologicalOrderDFs(i, adjList, visited, toposort);
        }
    }
    reverse(toposort.begin(), toposort.end());
    return toposort;
}

vector<int> topoSortBFs(vector<vector<int>> &edges, int n)
{
    vector<int> adjList[n];
    for (auto edge : edges)
        adjList[edge[0]].push_back(edge[1]);
    vector<int> indegree(n, 0);
    for (auto edge : edges)
        ++indegree[edge[1]];
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            q.push(i);
    vector<int> toposort;
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();
        toposort.push_back(currNode);
        for (auto adjNode : adjList[currNode])
        {
            if (--indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
    return toposort;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // return topoSortDFs(edges,v);
    return topoSortBFs(edges, v);
} 